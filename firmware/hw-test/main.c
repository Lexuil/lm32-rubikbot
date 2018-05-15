
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

int main(){

	// uint8_t abc;

	// uart_putchar('a');

	// abc = fifo_state();

	// fifo_write(19);
	// abc = fifo_read();
	// fifo_write(30);
	// abc = fifo_state();

	cam camera;

	uart_putstr("Initializing...");

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