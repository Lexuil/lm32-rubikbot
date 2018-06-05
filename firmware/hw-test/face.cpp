#include "face.h"

void face::Face(arm a, arm b, arm c, arm d, uint32_t Ca){
	if(Ca != Cao){
		if(Ca < 5){
			if(Cao < 5){
				if(Ca > Cao){
					for(uint32_t i=0; i<(Ca-Cao); i++){
						R1(a,b,c,d);
					}
				}else{
					for(uint32_t i=0; i<(Cao-Ca); i++){
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
					for(uint32_t i=0; i<(Ca-Cao1); i++){
						R1(a,b,c,d);
					}
				}else{
					for(uint32_t i=0; i<(Cao1-Ca); i++){
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
				for(uint32_t i = 0; i<2 ; i++){
					R11(a,b,c,d);
				}
			}
		}
	}

	Cao1 = Cao;
	Cao = Ca;
};

void face::Face1(arm a, arm b, arm c, arm d, uint32_t x){
	if(x == 1){
		
	}
	if(x == 2){
		L11(a,b,c,d);
		R1(a,b,c,d);
	}
	if(x == 3){
		L1(a,b,c,d);
	}
	if(x == 4){
		L1(a,b,c,d);
	}
	if(x == 5){
		R1(a,b,c,d);
		L11(a,b,c,d);
	}
	if(x == 6){
		L11(a,b,c,d);
	}
	if(x == 7){
		R11(a,b,c,d);
		R11(a,b,c,d);
	}
};

void face::facepictureinit(arm a, arm b, arm c, arm d){
	a.atras0();
	c.atras0();
	msleep(1000);
	a.izquierda0();
	c.derecha0();
	msleep(1000);
	a.adelante0();
	c.adelante0();
	msleep(1000);
	b.atras0();
	d.atras0();
	msleep(1000);
};

void face::facepictureend(arm a, arm b, arm c, arm d){
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
};

void face::R1(arm a, arm b, arm c, arm d){
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
};

void face::L1(arm a, arm b, arm c, arm d){
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
};

void face::R11(arm a, arm b, arm c, arm d){
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
};

void face::L11(arm a, arm b, arm c, arm d){
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
};