
#include "soc-hw.h"

int main(){

	arm arm1;

	arm1.set_serv(0,2);

	arm1.home();

	arm1.derecha();
	arm1.izquierda();

	/*

	pwm_period(2,200);
	pwm_duty(2,IZ);
	pwm_en(2,1);
	
	pwm_period(0,200);
	pwm_duty(0,IZ);
	pwm_en(0,1);

	while(1){
		pwm_duty(0,IZ);
		msleep(1000);
		pwm_duty(0,MID);
		msleep(1000);
		pwm_duty(0,DER);
		msleep(1000);
		pwm_duty(0,MID);
		msleep(1000);
		pwm_duty(0,IZ);


		pwm_duty(2,IZ);
		msleep(1000);
		pwm_duty(2,MID);
		msleep(1000);
		pwm_duty(2,DER);
		msleep(1000);
		pwm_duty(2,MID);
		msleep(1000);
		pwm_duty(2,IZ);
		msleep(1000);


		pwm_duty(0,IZ);
		pwm_duty(2,IZ);
		msleep(1000);
		pwm_duty(0,MID);
		pwm_duty(2,MID);
		msleep(1000);
		pwm_duty(0,DER);
		pwm_duty(2,DER);
		msleep(1000);
		pwm_duty(0,MID);
		pwm_duty(2,MID);
		msleep(1000);
		pwm_duty(0,IZ);
		pwm_duty(2,IZ);
		msleep(1000);
	}
		*/
}

