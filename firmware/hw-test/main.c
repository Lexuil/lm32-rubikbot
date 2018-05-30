
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "soc-hw.h"
#include "servos.h"
#include "cam.h"
#include "face.h"

char C = 'r';
int br;
int inst;
int dir;
int val;
int adr;

uint32_t FF;

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

/* --- MOVE_ARM FUNCTION --- */

void move_arm(arm arm1, arm arm2, arm arm3, arm arm4,char b, char c){	
	if (c == 0x27){  // ' = 27 (ASCII to HEX)
			if(b == 0x52){ 
				arm4.izquierda();
				uart_putstr("Moving Arm 1 to the LEFT..."); // Moves ARM 1 (Cube's Right Face --ORANGE--) to the LEFT
				}
			if(b == 0x42){
				arm3.izquierda();
				uart_putstr("Moving Arm 2 to the LEFT..."); // Moves ARM 1 (Cube's Back Face --BLUE--) to the LEFT
				} 	
			if(b == 0x4C){
			 	arm2.izquierda();
				uart_putstr("Moving Arm 3 to the LEFT..."); // Moves ARM 1 (Cube's Left Face --RED--) to the LEFT
			 } 
			if (b == 0x46){
				arm1.izquierda();
				uart_putstr("Moving Arm 4 to the LEFT..."); // Moves ARM 1 (Cube's Front Face --GREEN--) to the LEFT
			}
			if (b == 0x55){
				arm1.izquierda();
				uart_putstr("Moving Arm 1 to the LEFT..."); // Moves ARM 1 (Cube's Upper Face --YELLOW--) to the RIGHT
			}
			if (b == 0x44){
				arm4.izquierda();
				uart_putstr("Moving Arm 3 to the LEFT..."); // Moves ARM 1 (Cube's Down Face --WHITE--) to the RIGHT
			}
	}
	else {
			if (b == 0x52){
				arm4.derecha();
				uart_putstr("Moving Arm 1 to the RIGHT..."); // Moves ARM 1 (Cube's Right Face --ORANGE--) to the RIGHT
			}
			if (b == 0x42){
				arm3.derecha();
				uart_putstr("Moving Arm 2 to the RIGHT..."); // Moves ARM 1 (Cube's Back Face --BLUE--) to the RIGHT	
			}		
			if (b == 0x4C){
				arm2.derecha();
				uart_putstr("Moving Arm 3 to the RIGHT..."); // Moves ARM 1 (Cube's Left Face --RED--) to the RIGHT
			}
			if (b == 0x46){
				arm1.derecha();
				uart_putstr("Moving Arm 4 to the RIGHT..."); // Moves ARM 1 (Cube's Front Face --GREEN--) to the RIGHT
			}
			if (b == 0x55){
				arm1.atras0();
				arm3.atras0();
				msleep(1000);
				arm2.derecha0();
				arm4.izquierda0();
				msleep(1000);
				arm1.adelante0();
				arm3.adelante0();
				msleep(1000);
				arm2.atras0();
				arm4.atras0();
				msleep(1000);
				arm2.medio0();
				arm4.medio0();
				msleep(1000);
				arm2.adelante0();
				arm4.adelante0();
				msleep(1000);
				arm1.derecha();
				arm1.atras0();
				arm3.atras0();
				msleep(1000);
				arm2.izquierda0();
				arm4.derecha0();
				msleep(1000);
				arm1.adelante0();
				arm3.adelante0();
				msleep(1000);
				arm2.atras0();
				arm4.atras0();
				msleep(1000);
				arm2.medio0();
				arm4.medio0();
				msleep(1000);
				arm2.adelante0();
				arm4.adelante0();

				uart_putstr("Moving Arm 1 to the RIGHT..."); // Moves ARM 1 (Cube's Upper Face --YELLOW--) to the RIGHT
			}
			if (b == 0x44){
				arm4.derecha();
				uart_putstr("Moving Arm 3 to the RIGHT..."); // Moves ARM 1 (Cube's Down Face --WHITE--) to the RIGHT
			}
		}
}

int main(){


	cam camera;

	uart_putstr("YInitializing...");

	arm arm1;
	arm arm2;
	arm arm3;
	arm arm4;

	face F;

	arm1.set_serv(0,1);
	arm2.set_serv(2,3);
	arm3.set_serv(4,5);
	arm4.set_serv(6,7);

	arm1.calib(0x20,0x29);
	arm1.calib(0x21,0x05);
	arm1.calib(0x22,0x17);
	arm1.calib(0x23,0x30);
	arm1.calib(0x24,0x10);

	arm2.calib(0x20,0x29);
	arm2.calib(0x21,0x05);
	arm2.calib(0x22,0x18);
	arm2.calib(0x23,0x30);
	arm2.calib(0x24,0x17);

	arm3.calib(0x20,0x29);
	arm3.calib(0x21,0x09);
	arm3.calib(0x22,0x18);
	arm3.calib(0x23,0x30);
	arm3.calib(0x24,0x10);

	arm4.calib(0x20,0x29);
	arm4.calib(0x21,0x9);
	arm4.calib(0x22,0x18);
	arm4.calib(0x23,0x30);
	arm4.calib(0x24,0x17);

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
				FF  = command_array[1];
			 	uart_putstr("Moving...");
			 	F.Face(arm1,arm2,arm3,arm4,FF);
			 	uart_putstr("Ready");
			}
// Cube Solver
			if (command_array[0] == 0xfa){
				adr = command_array[1];
				dir = command_array[2];
				uart_putstr("Solving Cube");
				move_arm(arm1, arm2, arm3, arm4, adr, dir);
				uart_putstr("Done");
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