#include "MonitorVias.h"

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  acelerometro.begin();
  gps.begin();
  cartao.begin( );
}

void loop() {
  
  acelerometro.getInformacoes();
  gps.novasCoordenadas( );
  formato.setDados( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
  cartao.gravar( formato.csv() );
  
}
