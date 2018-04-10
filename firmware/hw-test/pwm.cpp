#include "pwm.h"

void pwm::pause(){

	msleep(1000);

};
void pwm::pwm_en(int sel, uint32_t val){

	if(sel == 0) pwm0->en0 = val;
	if(sel == 1) pwm0->en1 = val;
	if(sel == 2) pwm0->en2 = val;
	if(sel == 3) pwm0->en3 = val;
	if(sel == 4) pwm0->en4 = val;
	if(sel == 5) pwm0->en5 = val;
	if(sel == 6) pwm0->en6 = val;
	if(sel == 7) pwm0->en7 = val;

};

void pwm::pwm_duty(int sel, uint32_t val){

	if(sel == 0) pwm0->duty0 = val;
	if(sel == 1) pwm0->duty1 = val;
	if(sel == 2) pwm0->duty2 = val;
	if(sel == 3) pwm0->duty3 = val;
	if(sel == 4) pwm0->duty4 = val;
	if(sel == 5) pwm0->duty5 = val;
	if(sel == 6) pwm0->duty6 = val;
	if(sel == 7) pwm0->duty7 = val;

};

void pwm::pwm_period(int sel, uint32_t val){

	if(sel == 0) pwm0->period0 = val;
	if(sel == 1) pwm0->period1 = val;
	if(sel == 2) pwm0->period2 = val;
	if(sel == 3) pwm0->period3 = val;
	if(sel == 4) pwm0->period4 = val;
	if(sel == 5) pwm0->period5 = val;
	if(sel == 6) pwm0->period6 = val;
	if(sel == 7) pwm0->period7 = val;

};

uint32_t pwm::pwm_geten(uint32_t sel){

	if(sel == 0) return pwm0->en0;
	if(sel == 1) return pwm0->en1;
	if(sel == 2) return pwm0->en2;
	if(sel == 3) return pwm0->en3;
	if(sel == 4) return pwm0->en4;
	if(sel == 5) return pwm0->en5;
	if(sel == 6) return pwm0->en6;
	if(sel == 7) return pwm0->en7;
	return 0;

};

uint32_t pwm::pwm_getduty(uint32_t sel){

	if(sel == 0) return pwm0->duty0;
	if(sel == 1) return pwm0->duty1;
	if(sel == 2) return pwm0->duty2;
	if(sel == 3) return pwm0->duty3;
	if(sel == 4) return pwm0->duty4;
	if(sel == 5) return pwm0->duty5;
	if(sel == 6) return pwm0->duty6;
	if(sel == 7) return pwm0->duty7;
	return 0;
	
};

uint32_t pwm::pwm_getperiod(uint32_t sel){

	if(sel == 0) return pwm0->period0;
	if(sel == 1) return pwm0->period1;
	if(sel == 2) return pwm0->period2;
	if(sel == 3) return pwm0->period3;
	if(sel == 4) return pwm0->period4;
	if(sel == 5) return pwm0->period5;
	if(sel == 6) return pwm0->period6;
	if(sel == 7) return pwm0->period7;
	return 0;
	
};