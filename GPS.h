#ifndef __GPS_h
#define __GPS_h

#include <TimeLib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#include <stdio.h>

class GPS
{
    public:
      void begin();
      long getTime();
      double getLatitude();
      double getLongitude();
      double getVelocidade();
      void novasCoordenadas();
    
    private:
      TinyGPSPlus _gps;
      const int _gmt = -3;
      SoftwareSerial *_serialGPS;
      long _ultimaLeitura;
      void setarTempo();
      bool buscarGPS();
};
#endif
