#include "MonitorVias.h"


bool setCoordenadasAnterior( double latitude, double longitude , bool resposta ){
  longitudeAnterior = longitude;
  latitudeAnterior = latitude;
  return resposta;
}

bool isGravar( double latitude, double longitude, double velocidade){
  Serial.println( ":: Verificar se deve gravar" );
  if(velocidade < velocidadeMinima){
    return setCoordenadasAnterior( latitude, longitude, false);
  }

  if( (longitudeAnterior == longitude) && (latitudeAnterior == latitude) ){
    return setCoordenadasAnterior( latitude, longitude, false);
  }

  short diferencaZ = abs( acelerometro.getEixoZ() - ultimoZ);
  if( isBump( diferencaZ ) == false ){
    return setCoordenadasAnterior( latitude, longitude, false);
  }

  return setCoordenadasAnterior( latitude, longitude, true);
}

bool isBump( int diferencaZ ){
  
  int soma = diferencaZ;
 // double somaDesvioPadrao = pow( float( media - lista[0] ), float(2));
  double somaDesvioPadrao = 0.0;
  
  for( int contador=1; contador < elementosMedicao; contador++){
    lista[contador-1] = lista[contador];
    soma+= lista[contador];
    somaDesvioPadrao+= pow( float(media-lista[contador]), float(2));
  }
  
  double desvioPadrao = sqrt( somaDesvioPadrao/elementosMedicao );
  media = soma/elementosMedicao;
  
  lista[elementosMedicao-1] = diferencaZ;

  return ( ( ( lista[elementosMedicao-2] - desvioPadrao ) < diferencaZ ) && ( ( lista[elementosMedicao-2] + desvioPadrao ) > diferencaZ) ) ;
}

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  
  acelerometro.begin();
  gps.begin();

  for( int contador=0; contador < elementosMedicao; contador++){
    acelerometro.getInformacoes();
    lista[contador] = acelerometro.getEixoZ();
  }
  
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


