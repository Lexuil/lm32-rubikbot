
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "soc-hw.h"
#include "servos.h"
#include "cam.h"


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

uint32_t command_array [5];

uint8_t read_command(){

		uint8_t cm;
		uint8_t i=0;
        while ( (cm != 0xf0) && (i<5) ){
        	cm = uart_getchar();
        	command_array[i]=cm;
        	i++;

        }
        if (cm == 0xf0 )
        	return 1;
        return 0;			
}

void R1(arm a, arm b, arm c, arm d){
	a.atras0();
	c.atras0();
	msleep(1000);
	b.derecha0();
	d.izquierda0();
	msleep(1000);
	a.adelante0();
	c.adelante0();
	msleep(1000);
	b.atras0();
	d.atras0();
	msleep(1000);
	b.medio0();
	d.medio0();
	msleep(1000);
	b.adelante0();
	d.adelante0();
	msleep(1000);
}

void L1(arm a, arm b, arm c, arm d){
	a.atras0();
	c.atras0();
	msleep(1000);
	b.izquierda0();
	d.derecha0();
	msleep(1000);
	a.adelante0();
	c.adelante0();
	msleep(1000);
	b.atras0();
	d.atras0();
	msleep(1000);
	b.medio0();
	d.medio0();
	msleep(1000);
	b.adelante0();
	d.adelante0();
	msleep(1000);
}

void R11(arm a, arm b, arm c, arm d){
	b.atras0();
	d.atras0();
	msleep(1000);
	a.derecha0();
	c.izquierda0();
	msleep(1000);
	b.adelante0();
	d.adelante0();
	msleep(1000);
	a.atras0();
	c.atras0();
	msleep(1000);
	a.medio0();
	c.medio0();
	msleep(1000);
	a.adelante0();
	c.adelante0();
	msleep(1000);
}

void L11(arm a, arm b, arm c, arm d){
	b.atras0();
	d.atras0();
	msleep(1000);
	a.izquierda0();
	c.derecha0();
	msleep(1000);
	b.adelante0();
	d.adelante0();
	msleep(1000);
	a.atras0();
	c.atras0();
	msleep(1000);
	a.medio0();
	c.medio0();
	msleep(1000);
	a.adelante0();
	c.adelante0();
	msleep(1000);
}

int Cao  = 1;
int Cao1 = 1;

void Face(arm a, arm b, arm c, arm d, int Ca){
	if(Ca != Cao){
		if(Ca < 5){
			if(Cao < 5){
				if(Ca > Cao){
					for(int i=0; i<(Ca-Cao); i++){
						R1(a,b,c,d);
					}
				}else{
					for(int i=0; i<(Cao-Ca); i++){
						L1(a,b,c,d);
					}
				}
			}
			if(Cao >= 5){
				if(Cao == 6){
					R11(a,b,c,d);
				}
				if(Cao == 5){
					L11(a,b,c,d);
				}
				if(Ca > Cao1){
					for(int i=0; i<(Ca-Cao1); i++){
						R1(a,b,c,d);
					}
				}else{
					for(int i=0; i<(Cao1-Ca); i++){
						L1(a,b,c,d);
					}
				}

			}
		}else if(Ca >= 5){
			if(Cao < 5){
				if(Ca == 5){
					R11(a,b,c,d);
				}
				if(Ca == 6){
					L11(a,b,c,d);
				}
			}
			if(Cao >= 5){
				for(int i = 0; i<2 ; i++){
					R11(a,b,c,d);
				}
			}
		}
	}

	Cao1 = Cao;
	Cao = Ca;
}

int main(){

	cam camera;

	uart_putstr("YInitializing...");

	arm arm1;
	arm arm2;
	arm arm3;
	arm arm4;

	arm1.set_serv(0,1);
	arm2.set_serv(2,3);
	arm3.set_serv(4,5);
	arm4.set_serv(6,7);

	uart_putstr("Ready");


	while(1){
		uart_putchar('\n');
		uart_putstr("------Instruction------");
		uart_putchar('\n');

	    uint8_t cm=read_command();

		if (cm){
			if (command_array[0] == 0xff) {
					uart_putstr("Home...");
					arm1.home();
					arm2.home();
					arm3.home();
					arm4.home();
					uart_putstr("Ready");
			}

			if (command_array[0] == 0xfe){
					uart_putstr("Init...");
					arm1.init();
					arm2.init();
					arm3.init();
					arm4.init();
					uart_putstr("Ready");
			}

			if (command_array[0] == 0xfd){
				inst = command_array[2];
				uart_putstr("Moving...");
				if (command_array[1] == 0x01) 
					instruccion(arm1,inst);
				if (command_array[1] == 0x02)
					instruccion(arm2,inst);
				if (command_array[1] == 0x03)
					instruccion(arm3,inst);
				if (command_array[1] == 0x04)
					instruccion(arm4,inst);
				uart_putstr("Ready");
			}
			if (command_array[0] == 0xfc){
				br  = command_array[1];
				dir = command_array[2];
				val = command_array[3];
				uart_putstr("Calibrating...");
				if (command_array[1] == 0x01)
					arm1.calib(dir,val);
				if (command_array[1] == 0x02)
					arm2.calib(dir,val);
				if (command_array[1] == 0x03)
					arm3.calib(dir,val);
				if (command_array[1] == 0x04)
					arm4.calib(dir,val);
				uart_putstr("Ready");
			}
			if (command_array[0] == 0xfb){
				br  = command_array[1];
				uart_putstr("Moving...");
				Face(arm1,arm2,arm3,arm4,br);
				uart_putstr("Ready");
			}

			if (command_array[0] == 0x50){
				uart_putstr("Reset camera...");
				camera.reset();
			}

			if (command_array[0] == 0x5a){
				uart_putstr("Take picture...");
				camera.takepicture();
			}

			if (command_array[0] == 0x5b){
				uart_putstr("Get size...");
				camera.getsize();
			}

			if (command_array[0] == 0x5c){
				uart_putstr("Sending...");
				camera.sendpicture();
			}

			if (command_array[0] == 0x5d){
				uart_putstr("Stoping...");
				camera.stoptaking();
			}
		}

	}
}