
#include "soc-hw.h"

int main(){
	pwm_period(0,200);
	pwm_duty(0,10);
	pwm_en(0,1);
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

