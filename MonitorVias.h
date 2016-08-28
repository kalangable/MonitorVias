#ifndef MonitorVias_h
#define MonitorVias_h
#include <SoftwareSerial.h>
#include "sd/GravarSD.h"
#include "acelerometro/Acelerometro.h"
#include "gps/GPS.h"
#include "json/JsonMonitor.h"
Acelerometro acelerometro;
SoftwareSerial ss(3, 4);
GPS gps;
JsonMonitor json;
GravarSD memoria;
#endif
