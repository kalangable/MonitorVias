#ifndef __GPS_h
#define __GPS_h

#include "Arduino.h"
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

class GPS
{
  public:
    void begin( SoftwareSerial &serial );
    long getTime();
    double getLatitude();
    double getLongitude();
    double getVelocidade();
    void novasCoordenadas( SoftwareSerial& serial );  
  private:
    //Variaveis
    TinyGPSPlus gps;
};
#endif