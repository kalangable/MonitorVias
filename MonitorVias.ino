#include "MonitorVias.h"

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  acelerometro.begin();
  gps.begin();
  cartao.begin( );
  // Cada interrupção deve registrar uma linha em branco
  cartao.gravar( ",,,,,,," );
}

void loop() {
  
  acelerometro.getInformacoes();
  if( generatedInfoZ( acelerometro.getEixoZ() )){
    gps.novasCoordenadas();
    if( isGravar( gps.getLatitude(), gps.getLongitude(), gps.getVelocidade() ) ){
      formato.setDados( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
      cartao.gravar( formato.csv() );
    }
  }
}

bool isGravar( double latitude, double longitude, double velocidade){
  if(velocidade < velocidadeMinima){
    return setResposta( latitude, longitude, false);
  }

  if( (lon == longitude) && (lat == latitude) ){
    return setResposta( latitude, longitude, false);
  }

  return setResposta( latitude, longitude, true);
}

bool setResposta( double latitude, double longitude , bool resposta ){
  lon = longitude;
  lat = latitude;
  return resposta;
}

bool generatedInfoZ( int eixoZ ){
  
  int soma = eixoZ;
  double somaDesvioPadrao = pow( float( media - lista[0] ), float(2));
  for( int contador=1; contador < elementosMedicao; contador++){
    lista[contador-1] = lista[contador];
    soma+= lista[contador];
    somaDesvioPadrao+= pow( float(media-lista[contador]), float(2));
  }
  lista[elementosMedicao-1] = eixoZ;
  double desvioPadrao = sqrt( somaDesvioPadrao/(elementosMedicao-1) );
  media = soma/elementosMedicao;
  return ( ( ( lista[elementosMedicao-2] - desvioPadrao ) < eixoZ ) && ( ( lista[elementosMedicao-2] + desvioPadrao ) > eixoZ) ) ;
}

