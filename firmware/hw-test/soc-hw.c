#include "soc-hw.h"

uart_t  *uart0  = (uart_t *)   0x20000000;
timer_t *timer0 = (timer_t *)  0x30000000;
spi_t   *spi0   = (spi_t *)    0x40000000;
pwm_t   *pwm0   = (pwm_t *)    0x50000000;

isr_ptr_t isr_table[32];

void tic_isr();
/***************************************************************************
 * IRQ handling
 */
void isr_null()
{
}

void irq_handler(uint32_t pending)
{
	int i;

	for(i=0; i<32; i++) {
		if (pending & 0x01) (*isr_table[i])();
		pending >>= 1;
	}
}

void isr_init()
{
	int i;
	for(i=0; i<32; i++)
		isr_table[i] = &isr_null;
}

void isr_register(int irq, isr_ptr_t isr)
{
	isr_table[irq] = isr;
}

void isr_unregister(int irq)
{
	isr_table[irq] = &isr_null;
}

/***************************************************************************
 * TIMER Functions
 */
void msleep(uint32_t msec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}

void nsleep(uint32_t nsec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000000)*nsec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}


uint32_t tic_msec;

void tic_isr()
{
	tic_msec++;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
}

void tic_init()
{
	tic_msec = 0;

	// Setup timer0.0
	timer0->compare0 = (FCPU/10000);
	timer0->counter0 = 0;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;

	isr_register(1, &tic_isr);
}


/***************************************************************************
 * UART Functions
 */
void uart_init()
{
	//uart0->ier = 0x00;  // Interrupt Enable Register
	//uart0->lcr = 0x03;  // Line Control Register:    8N1
	//uart0->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart0->div = (FCPU/(57600*16));
}

char uart_getchar()
{   
	while (! (uart0->ucr & UART_DR)) ;
	return uart0->rxtx;
}

void uart_putchar(char c)
{
	while (uart0->ucr & UART_BUSY) ;
	uart0->rxtx = c;
}

void uart_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart_putchar(*c);
		c++;
	}
}


/***************************************************************************
 * PWM Functions
 */

void pwm_en(int sel, uint32_t val){

	if(sel == 0) pwm0->en0 = val;
	if(sel == 1) pwm0->en1 = val;
	if(sel == 2) pwm0->en2 = val;
	if(sel == 3) pwm0->en3 = val;
	if(sel == 4) pwm0->en4 = val;
	if(sel == 5) pwm0->en5 = val;
	if(sel == 6) pwm0->en6 = val;
	if(sel == 7) pwm0->en7 = val;

}

void pwm_duty(int sel, uint32_t val){

	if(sel == 0) pwm0->duty0 = val;
	if(sel == 1) pwm0->duty1 = val;
	if(sel == 2) pwm0->duty2 = val;
	if(sel == 3) pwm0->duty3 = val;
	if(sel == 4) pwm0->duty4 = val;
	if(sel == 5) pwm0->duty5 = val;
	if(sel == 6) pwm0->duty6 = val;
	if(sel == 7) pwm0->duty7 = val;

}

void pwm_period(int sel, uint32_t val){

	if(sel == 0) pwm0->period0 = val;
	if(sel == 1) pwm0->period1 = val;
	if(sel == 2) pwm0->period2 = val;
	if(sel == 3) pwm0->period3 = val;
	if(sel == 4) pwm0->period4 = val;
	if(sel == 5) pwm0->period5 = val;
	if(sel == 6) pwm0->period6 = val;
	if(sel == 7) pwm0->period7 = val;

}

uint32_t pwm_geten(uint32_t sel){

	if(sel == 0) return pwm0->en0;
	if(sel == 1) return pwm0->en1;
	if(sel == 2) return pwm0->en2;
	if(sel == 3) return pwm0->en3;
	if(sel == 4) return pwm0->en4;
	if(sel == 5) return pwm0->en5;
	if(sel == 6) return pwm0->en6;
	if(sel == 7) return pwm0->en7;

}

uint32_t pwm_getduty(uint32_t sel){

	if(sel == 0) return pwm0->duty0;
	if(sel == 1) return pwm0->duty1;
	if(sel == 2) return pwm0->duty2;
	if(sel == 3) return pwm0->duty3;
	if(sel == 4) return pwm0->duty4;
	if(sel == 5) return pwm0->duty5;
	if(sel == 6) return pwm0->duty6;
	if(sel == 7) return pwm0->duty7;
	
}

uint32_t pwm_getperiod(uint32_t sel){

	if(sel == 0) return pwm0->period0;
	if(sel == 1) return pwm0->period1;
	if(sel == 2) return pwm0->period2;
	if(sel == 3) return pwm0->period3;
	if(sel == 4) return pwm0->period4;
	if(sel == 5) return pwm0->period5;
	if(sel == 6) return pwm0->period6;
	if(sel == 7) return pwm0->period7;
	
}