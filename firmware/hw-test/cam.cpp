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
	int length;
	char R1;

	length = (((int)xh)*256)+((int)xl);
	uart_putchar(length);

	for(int i = 0;i < 12;i++){
		uart1_putchar(SEND_JPG[i]);
	}

	uart1_putchar(xh);
	uart1_putchar(xl);
	uart1_putchar(0x00);
	uart1_putchar(0x0a);

	for(int i = 0;i < 5;i++){
		Z[i] = uart1_getchar();
	}

	if(Z[0] == 0x76 && Z[2] == 0x32){

		//uart_putchar('\n');
		//uart_putstr("Receiving...");

		for(int i = 0;i < length;i++){
			R1 = uart1_getchar();
			uart_putchar(R1);
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

