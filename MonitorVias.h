#ifndef MonitorVias_h
#define MonitorVias_h
#include "Arduino.h"
#include "sd/GravarSD.h"
#include "acelerometro/Acelerometro.h"
#include "gps/GPS.h"
#include "formatador/Formatador.h"

Acelerometro acelerometro;
GPS gps;
GravarSD cartao;
Formatador formato;

#endif
