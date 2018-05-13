#ifndef SERVOS_H
#define SERVOS_H

#include "pwm.h"


#define DER 25
#define IZ  5
#define MID 13

#define ATR 18
#define ADE 12


class  arm : public pwm{

public:
      void derecha();
      void izquierda();
      void init();
      void home();
      void set_serv(int,int);
      void calib(char,int);
private:
   	int serv1,serv2;
   	int der,iz,mid,atr,ade;

};



#endif