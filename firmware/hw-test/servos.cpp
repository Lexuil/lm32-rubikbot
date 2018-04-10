#include "servos.h"

void arm::home(){
	pwm_duty(serv2,IZ);
	pause();
	pwm_duty(serv1,MID);
	pause();
	pwm_duty(serv2,DER);
	pause();
};

void arm::derecha(){
	pwm_duty(serv1,DER);
	pause();
	pwm_duty(serv2,IZ);
	pause();
	pwm_duty(serv1,MID);
	pause();
	pwm_duty(serv2,DER);
	pause();
};

void arm::izquierda(){
	pwm_duty(serv1,IZ);
	pause();
	pwm_duty(serv2,IZ);
	pause();
	pwm_duty(serv1,MID);
	pause();
	pwm_duty(serv2,DER);
	pause();
};

void arm::set_serv(int x,int y){
	serv1 = x;
	serv2 = y;
	pwm_period(serv1,200);
	pwm_period(serv2,200);
	pwm_duty(serv1,MID);
	pwm_duty(serv2,IZ);
	pwm_en(serv1,1);
	pwm_en(serv2,1);
	pause();
};