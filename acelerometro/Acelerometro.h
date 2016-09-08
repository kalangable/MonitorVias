#ifndef __Acelerometro_h
#define __Acelerometro_h

#include <AcceleroMMA7361.h>
class Acelerometro
{
  
  public:
    void begin();
    int getEixoX();
    int getEixoY();
    int getEixoZ();

  private:
    //Variaveis
    AcceleroMMA7361 accelero;
};
#endif
