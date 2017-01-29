#include "MonitorVias.h"


bool setCoordenadasAnterior( double latitude, double longitude , bool resposta ){
  longitudeAnterior = longitude;
  latitudeAnterior = latitude;
  return resposta;
}

bool isGravar( double latitude, double longitude, double velocidade){
  bool gravar = true;
  
  Serial.println( ":: Verificar se deve gravar" );
  if(velocidade < velocidadeMinima){
    gravar = false;
  }

  if( (longitudeAnterior == longitude) && (latitudeAnterior == latitude) ){
    gravar = false;
  }

  return setCoordenadasAnterior( latitude, longitude, gravar);
}

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  
  acelerometro.begin();
  gps.begin();
  cartao.begin( pinGravacaoCartaoMemoria );
  // Cada interrupção deve registrar uma linha em branco
  cartao.gravar( ",,,,,,," );
}

void loop() {
  
  gps.novasCoordenadas();
  acelerometro.getInformacoes();
  
  if( isGravar( gps.getLatitude(), gps.getLongitude(), gps.getVelocidade() ) ){
    formato.setDados( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
    cartao.gravar( formato.csv() );
  }
  
}


