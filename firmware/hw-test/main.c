
#include "soc-hw.h"

int main(){

	pwm_period(2,200);
	pwm_duty(2,5);
	pwm_en(2,1);

	pwm_period(0,200);
	pwm_duty(0,5);
	pwm_en(0,1);

	while(1){
		pwm_duty(0,5);
		pwm_duty(2,10);
		msleep(1000);
		pwm_duty(0,9);
		pwm_duty(2,15);
		msleep(1000);
		pwm_duty(0,13);
		pwm_duty(2,13);
		msleep(1000);
		pwm_duty(0,18);
		pwm_duty(2,20);
		msleep(1000);
		pwm_duty(0,23);
		pwm_duty(2,10);
		msleep(1000);
	}
		
}

