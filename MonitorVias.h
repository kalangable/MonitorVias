#ifndef MonitorVias_h
#define MonitorVias_h
#include "Arduino.h"
#include "sd/GravarSD.h"
#include "acelerometro/Acelerometro.h"
#include "gps/GPS.h"
#include "json/JsonMonitor.h"

Acelerometro acelerometro;

GPS gps;
JsonMonitor json;
GravarSD cartao;

#endif
