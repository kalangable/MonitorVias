#include "MonitorVias.h"

void setup() {
  Serial.begin(9600);
  while (!Serial);
  gps.begin(ss);
  memoria.begin();
}

void loop() {

  gps.novasCoordenadas( ss );
  JsonObject& jsonObject = json.generatedJson( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
  char buffer[150];
  jsonObject.printTo(buffer, sizeof(buffer));
  memoria.gravar( buffer );
  
}
