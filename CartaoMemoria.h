#ifndef __CartaoMemoria_h
#define __CartaoMemoria_h

#include <SD.h>
#include <SPI.h>

class CartaoMemoria
{
    public:
      void begin( const int pin );
      void gravar( char *dados );
    
    private:
      File _arquivo;
};
#endif
