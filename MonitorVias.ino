#include "MonitorVias.h"

void setup() {
  Serial.begin(9600);
  while (!Serial);
  gps.begin(ss);
  memoria.begin();
}

void loop() {

  gps.novasCoordenadas( ss );
  memoria.gravar(json.generatedStringJson( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() ));
   
  //gravador.gravar(new Json(acelerometro.informacaoesEixos(), gps.inforamacoesCoordenadas()));
  
}
