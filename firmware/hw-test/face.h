#ifndef FACE_H
#define FACE_H

#include "servos.h"


class  face : public arm{

public:
      void Face(arm,arm,arm,arm,uint32_t);
      void R1(arm,arm,arm,arm);
      void R11(arm,arm,arm,arm);
      void L1(arm,arm,arm,arm);
      void L11(arm,arm,arm,arm);
private:
   uint32_t Cao  = 1;
   uint32_t Cao1 = 1;

};



#endif