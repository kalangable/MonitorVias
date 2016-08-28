#ifndef __Acelerometro_h
#define __Acelerometro_h

#include "Arduino.h"
#include <AcceleroMMA7361.h>
class Acelerometro
{
  
  public:
    Acelerometro();
    int getEixoX();
    int getEixoY();
    int getEixoZ();

  private:
    //Variaveis
    AcceleroMMA7361 accelero;
};
#endif
