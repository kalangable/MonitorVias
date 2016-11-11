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

#define elementosMedicao 30

#define leituraMetros 3

#define leituraAcelerometroPorMilis 2.7

#define converterKMporMS 3.6

double velocidadeMinima = 7.0;

double lon,lat;

short ultimoZ, media;

bool isGravar( double latitude, double longitude,   double velocidade);
bool setResposta( double latitude, double longitude , bool resposta );
bool generatedInfoZ( int eixoZ );
short lista[elementosMedicao];

#endif
