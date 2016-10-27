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

#define elementosMedicao 10

double velocidadeMinima = 7.0;

double lon,lat;

bool isGravar( double latitude, double longitude,   double velocidade);
bool setResposta( double latitude, double longitude , bool resposta );
bool generatedInfoZ( int eixoZ );
short lista[elementosMedicao] = { 760, 810 , 710 , 760 , 810 , 710 , 760 , 810 , 710 , 760};
int media = 760;


#endif
