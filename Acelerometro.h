#ifndef __Acelerometro_h
#define __Acelerometro_h

#include <AcceleroMMA7361.h>
class Acelerometro
{
  
  public:
    void begin();
    void getInformacoes();
    int getEixoX();
    int getEixoY();
    int getEixoZ();

  private:
    AcceleroMMA7361 _accelero;
    int _x , _y , _z;
};
#endif
