#include "servos.h"

void arm::init(){
	pwm_duty(serv2,atr);
	pause();
	pwm_duty(serv1,mid);
	pause();
	pwm_duty(serv2,ade);
	pause();
};

void arm::home(){
	pwm_duty(serv2,atr);
	pause();
};

void arm::derecha(){
	pwm_duty(serv1,der);
	pause();
	pwm_duty(serv2,atr);
	pause();
	pwm_duty(serv1,mid);
	pause();
	pwm_duty(serv2,ade);
	pause();
};

void arm::izquierda(){
	pwm_duty(serv1,iz);
	pause();
	pwm_duty(serv2,atr);
	pause();
	pwm_duty(serv1,mid);
	pause();
	pwm_duty(serv2,ade);
	pause();
};

void arm::set_serv(int x,int y){
	serv1 = x;
	serv2 = y;

	der = 0x29;
	iz  = 0x09;
	mid = 0x18;

	atr = 0x30;
	ade = 0x17;

	pwm_period(serv1,200);
	pwm_period(serv2,200);
	pwm_duty(serv1,mid);
	pwm_duty(serv2,atr);
	pwm_en(serv1,1);
	pwm_en(serv2,1);
	pause();
};

void arm::calib(char dir,int val){
	if(dir == 0x20){
		der = val;
	}
	if(dir == 0x21){
		iz = val;
	}
	if(dir == 0x22){
		mid = val;
	}
	if(dir == 0x23){
		atr = val;
	}
	if(dir == 0x24){
		ade = val;
	}
};

void arm::derecha0(){
	pwm_duty(serv1,der);
};


void arm::izquierda0(){
	pwm_duty(serv1,iz);
};


void arm::medio0(){
	pwm_duty(serv1,mid);
};


void arm::atras0(){
	pwm_duty(serv2,atr);
};


void arm::adelante0(){
	pwm_duty(serv2,ade);
};

/*
void arm::test(){
	pwm_period(5,200);
	pwm_period(1,200);
	pwm_duty(5,13);
	pwm_duty(1,8);
	pwm_en(5,1);
	pwm_en(1,1);
	msleep(1000);
	pwm_duty(1,9);
	pwm_duty(5,9);
	msleep(1000);
	pwm_duty(1,10);
	pwm_duty(5,10);
	msleep(1000);
	pwm_duty(1,11);
	pwm_duty(5,11);
	msleep(1000);
	pwm_duty(1,12);
	pwm_duty(5,12);
	msleep(1000);
	pwm_duty(1,13);
	pwm_duty(5,13);
	msleep(1000);
}*/