
#include "soc-hw.h"
#include "servos.h"

int main(){

	arm arm1;

	arm1.set_serv(0,2);

	arm1.home();

	arm1.derecha();
	arm1.izquierda();
	
}

