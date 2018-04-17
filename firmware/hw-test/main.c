
#include "soc-hw.h"
#include "servos.h"

int main(){

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
	
}

