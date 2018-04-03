#ifndef SPIKEHW_H
#define SPIKEHW_H

#define PROMSTART 0x00000000
#define RAMSTART  0x00000800
#define RAMSIZE   0x400
#define RAMEND    (RAMSTART + RAMSIZE)

#define RAM_START 0x40000000
#define RAM_SIZE  0x04000000

#define FCPU      50000000

#define UART_RXBUFSIZE 32


/****************************************************************************
 * Types
 */
typedef unsigned int  uint32_t;    // 32 Bit
typedef signed   int   int32_t;    // 32 Bit

typedef unsigned char  uint8_t;    // 8 Bit
typedef signed   char   int8_t;    // 8 Bit

/****************************************************************************
 * Interrupt handling
 */
typedef void(*isr_ptr_t)(void);

void     irq_enable();
void     irq_disable();
void     irq_set_mask(uint32_t mask);
uint32_t irq_get_mak();

void     isr_init();
void     isr_register(int irq, isr_ptr_t isr);
void     isr_unregister(int irq);

/****************************************************************************
 * General Stuff
 */
void     halt();
void     jump(uint32_t addr);


/****************************************************************************
 * Timer
 */
#define TIMER_EN     0x08    // Enable Timer
#define TIMER_AR     0x04    // Auto-Reload
#define TIMER_IRQEN  0x02    // IRQ Enable
#define TIMER_TRIG   0x01    // Triggered (reset when writing to TCR)

typedef struct {
	volatile uint32_t tcr0;
	volatile uint32_t compare0;
	volatile uint32_t counter0;
	volatile uint32_t tcr1;
	volatile uint32_t compare1;
	volatile uint32_t counter1;
} timer_t;

void msleep(uint32_t msec);
void nsleep(uint32_t nsec);

void prueba();
void tic_init();


/***************************************************************************
 * UART0
 */
#define UART_DR   0x01                    // RX Data Ready
#define UART_ERR  0x02                    // RX Error
#define UART_BUSY 0x10                    // TX Busy

typedef struct {
   volatile uint32_t ucr;
   volatile uint32_t rxtx;
} uart_t;

void uart_init();
void uart_putchar(char c);
void uart_putstr(char *str);
char uart_getchar();

/***************************************************************************
 * SPI0
 */

typedef struct {
   volatile uint32_t rxtx;
   volatile uint32_t run;
   volatile uint32_t cs;
   volatile uint32_t nop2;
   volatile uint32_t divisor;
} spi_t;

void spi_init();
void spi_putchar(char c);
char spi_getchar();


/***************************************************************************
 * PWM0
 */
typedef struct {
   volatile uint32_t en0;
   volatile uint32_t period0;
   volatile uint32_t duty0;
   volatile uint32_t en1;
   volatile uint32_t period1;
   volatile uint32_t duty1;
   volatile uint32_t en2;
   volatile uint32_t period2;
   volatile uint32_t duty2;
   volatile uint32_t en3;
   volatile uint32_t period3;
   volatile uint32_t duty3;
   volatile uint32_t en4;
   volatile uint32_t period4;
   volatile uint32_t duty4;
   volatile uint32_t en5;
   volatile uint32_t period5;
   volatile uint32_t duty5;
   volatile uint32_t en6;
   volatile uint32_t period6;
   volatile uint32_t duty6;
   volatile uint32_t en7;
   volatile uint32_t period7;
   volatile uint32_t duty7;
} pwm_t;

void pwm_en(int sel,uint32_t val);
void pwm_period(int sel,uint32_t val);
void pwm_duty(int sel,uint32_t val);
uint32_t pwm_geten(uint32_t sel);
uint32_t pwm_getperiod(uint32_t sel);
uint32_t pwm_getduty(uint32_t sel);


/***************************************************************************




 * Pointer to actual components
 */
extern timer_t  *timer0;
extern uart_t   *uart0;
extern uint32_t *sram0; 

#endif // SPIKEHW_H