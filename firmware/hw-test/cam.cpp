#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "cam.h"

void cam::reset(){

	char R1;
	char R2;

	for(int i = 0;i < 4;i++){
		uart1_putchar(RESET_CAMERA[i]);
	}

	R1 = uart1_getchar();

	for(int i = 0;i < 70;i++){
		R2 = uart1_getchar();
	}

	if(R1 == 0x76 && R2 == 0x0a){
		uart_putstr("Ok");
	}
	

};

void cam::takepicture(){

	uint32_t Z [5];

	for(int i = 0;i < 5;i++){
		uart1_putchar(TAKE_PICTURE[i]);
	}

	for(int i = 0;i < 5;i++){
		Z[i] = uart1_getchar();
	}


	if(Z[0] == 0x76 && Z[2] == 0x36){
		uart_putstr("Ok");	}

};

void cam::getsize(){

	uint32_t Z [9];

	for(int i = 0;i < 5;i++){
		uart1_putchar(GET_SIZE[i]);
	}

	for(int i = 0;i < 9;i++){
		Z[i] = uart1_getchar();
	}

	if(Z[0] == 0x76 && Z[2] == 0x34){

		uart_putstr("Ok");

		xh = Z[7];
		xl = Z[8];

		uart_putchar(xh);
		uart_putchar(xl);
	}
};

void cam::sendpicture(){

	uint32_t Z [9];
	uint32_t X [9];
	char R1;

	for(int i = 0;i < 5;i++){
		uart1_putchar(GET_SIZE[i]);
	}

	for(int i = 0;i < 9;i++){
		X[i] = uart1_getchar();
	}

	if(X[0] == 0x76 && X[2] == 0x34){
		xh = X[7];
		xl = X[8];
	}

	uart_putchar(xh);
	uart_putchar(xl);

	for(int i = 0;i < 12;i++){
		uart1_putchar(SEND_JPG[i]);

	}

	uart1_putchar(X[7]);
	uart1_putchar(X[8]);
	uart1_putchar(0x00);
	uart1_putchar(0x0a);

	for(int i = 0;i < 5;i++){
		Z[i] = uart1_getchar();
	}

	if(Z[0] == 0x76 && Z[2] == 0x32){

		//uart_putchar('\n');
		//uart_putstr("Receiving...");

		
		for(uint32_t i = 0;i < (X[7]*256 + X[8]);i++){
			R1 = uart1_getchar();
			uart_putchar(R1);
			//uart_putchar(i);
		}

		for(int i = 0;i < 5;i++){
			Z[i] = uart1_getchar();
		}

		if(Z[0] == 0x76 && Z[2] == 0x32){
		uart_putstr("Sent");
		}
		
	}

};

void cam::stoptaking(){

	uint32_t Z [5];

	for(int i = 0;i < 5;i++){
		uart1_putchar(STOP_TAKING_PICS[i]);
	}

	for(int i = 0;i < 5;i++){
		Z[i] = uart1_getchar();
	}


	if(Z[0] == 0x76 && Z[2] == 0x36){
		uart_putstr("Finish");
	}

};

