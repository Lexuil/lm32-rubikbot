
#include "soc-hw.h"

int period = 0;
int duty = 0;

int main(){
	pwm_period(7,200);
	pwm_duty(7,10);
	pwm_en(7,1);

	pwm_period(5,200);
	pwm_duty(5,10);
	pwm_en(5,1);

	pwm_period(3,200);
	pwm_duty(3,10);
	pwm_en(3,1);

	pwm_period(2,200);
	pwm_duty(2,10);
	pwm_en(2,1);

	pwm_period(0,200);
	pwm_duty(0,10);
	pwm_en(0,1);

	duty = pwm_getduty(0);
	period = pwm_getperiod(0);

	pwm_period(4,period);
	pwm_duty(4,duty);
	pwm_en(4,1);

	msleep(1000000);

	while(1){
		pwm_duty(0,13);
		msleep(1000000);
		pwm_duty(0,15);
		msleep(1000000);
		pwm_duty(0,20);
		msleep(1000000);
		pwm_duty(0,10);
		msleep(1000000);
	}
		
}

