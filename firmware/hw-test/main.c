
#include "soc-hw.h"

#define DER 25
#define IZ  5
#define MID 15

class  arm{
	int serv1,serv2;

	public:
		void derecha();
		void izquierda();
		void home();
		void set_serv(int,int);
};


void arm::home(){
	pwm_duty(serv2,DER);
	msleep(1000);
	pwm_duty(serv1,MID);
	msleep(1000);
	pwm_duty(serv2,IZ);
}

void arm::derecha(){
	pwm_duty(serv1,MID);
	msleep(1000);
	pwm_duty(serv1,DER);
	msleep(1000);
	pwm_duty(serv2,IZ);
	msleep(1000);
	pwm_duty(serv1,MID);
	msleep(1000);
	pwm_duty(serv2,DER);
}
void arm::izquierda(){
	pwm_duty(serv1,MID);
	msleep(1000);
	pwm_duty(serv1,IZ);
	msleep(1000);
	pwm_duty(serv2,IZ);
	msleep(1000);
	pwm_duty(serv1,MID);
	msleep(1000);
	pwm_duty(serv2,DER);
}

void arm::set_serv(int x,int y){
	serv1 = x;
	serv2 = y;
	pwm_period(serv1,200);
	pwm_period(serv2,200);
	pwm_duty(serv1,MID);
	pwm_duty(serv2,IZ);
	pwm_en(serv1,1);
	pwm_en(serv2,1);
}

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

