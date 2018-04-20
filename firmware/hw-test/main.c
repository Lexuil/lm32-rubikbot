
#include "soc-hw.h"
#include "servos.h"


char C = 'r';
int br;
int inst;
int dir;
int val;


void instruccion(arm y,char x){
	switch(x){
		case 0x10:
			y.derecha();
			uart_putchar('d');
			break;

		case 0x11:
			y.izquierda();
			uart_putchar('z');
			break;
	}
}

int main(){

	arm arm1;
	arm arm2;
	arm arm3;
	arm arm4;

	arm1.set_serv(0,1);
	arm2.set_serv(2,3);
	arm3.set_serv(4,5);
	arm4.set_serv(6,7);


	while(1){
		C = uart_getchar();

		switch(C){
			case 0xff:
				C = uart_getchar();
				if(C == 0xf0){
					uart_putchar('h');
					arm1.home();
					arm2.home();
					arm3.home();
					arm4.home();
				}
				break;

			case 0xfe:
				C = uart_getchar();
				if(C == 0xf0){
					uart_putchar('i');
					arm1.init();
					arm2.init();
					arm3.init();
					arm4.init();
				}
				break;

			case 0xfd:
				br   = uart_getchar();
				inst = uart_getchar();
				C    = uart_getchar();
				if(C == 0xf0){
					uart_putchar('o');
					switch(br){
						case 0x01:
							instruccion(arm1,inst);
							break;
						case 0x02:
							instruccion(arm2,inst);
							break;
						case 0x03:
							instruccion(arm3,inst);
							break;
						case 0x04:
							instruccion(arm4,inst);
							break;
					}
				}
				break;

			case 0xfc:
				br  = uart_getchar();
				dir = uart_getchar();
				val = uart_getchar();
				C   = uart_getchar();
				if(C == 0xf0){
					uart_putchar('c');
					switch(br){
						case 0x01:
							arm1.calib(dir,val);
							break;
						case 0x02:
							arm2.calib(dir,val);
							break;
						case 0x03:
							arm3.calib(dir,val);
							break;
						case 0x04:
							arm4.calib(dir,val);
							break;
					}
				}
				break;
		}
	}
/*
	arm arm1;

	arm1.test();



	arm arm1;
	arm arm2;
	arm arm3;
	arm arm4;

	arm1.set_serv(0,1);
	arm2.set_serv(2,3);
	arm3.set_serv(4,5);
	arm4.set_serv(6,7);

	arm1.home();
	arm2.home();
	arm3.home();
	arm4.home();

	arm1.derecha();
	arm1.izquierda();

	arm2.derecha();
	arm2.izquierda();

	arm3.derecha();
	arm3.izquierda();

	arm4.derecha();
	arm4.izquierda();
	
	*/
}