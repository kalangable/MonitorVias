#include "MonitorVias.h"

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  acelerometro.begin();
  gps.begin();
  cartao.begin();
}

void loop() {
  
  gps.novasCoordenadas( );

  cartao.gravar( json.generatedJson( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() ));
  
}
