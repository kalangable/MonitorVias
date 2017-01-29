#ifndef MonitorVias_h
#define MonitorVias_h
#include "Arduino.h"
#include "CartaoMemoria.h"
#include "Acelerometro.h"
#include "GPS.h"
#include "Formatador.h"

Acelerometro acelerometro;
GPS gps;
CartaoMemoria cartao;
Formatador formato;

#define pinGravacaoCartaoMemoria 4
#define velocidadeMinima 7.0


double longitudeAnterior,latitudeAnterior;

bool isGravar( double latitude, double longitude,   double velocidade);

bool setResposta( double latitude, double longitude , bool resposta );

#endif
