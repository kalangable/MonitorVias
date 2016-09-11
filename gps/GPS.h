#ifndef __GPS_h
#define __GPS_h

#include <TimeLib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

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
    TinyGPSPlus gps;
    const int offset = -3;
    SoftwareSerial *serialGPS;
    long ultimaLeitura;
    void setarTempo();
    bool buscarGPS();
};
#endif