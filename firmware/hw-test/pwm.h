#ifndef PWM_H
#define PWM_H


#include "soc-hw.h"

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

class  pwm{

public:
	void pause();
	void pwm_en(int sel,uint32_t val);
	void pwm_period(int sel,uint32_t val);
	void pwm_duty(int sel,uint32_t val);
	uint32_t pwm_geten(uint32_t sel);
	uint32_t pwm_getperiod(uint32_t sel);
	uint32_t pwm_getduty(uint32_t sel);
private:
	pwm_t   *pwm0   = (pwm_t *)    0x50000000;

};



#endif