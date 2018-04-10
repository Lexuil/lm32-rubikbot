#ifndef SERVOS_H
#define SERVOS_H

#include "pwm.h"


#define DER 25
#define IZ  5
#define MID 15


class  arm : public pwm{

public:
      void derecha();
      void izquierda();
      void home();
      void set_serv(int,int);
private:
   	int serv1,serv2;

};



#endif