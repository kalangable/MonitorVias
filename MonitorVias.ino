#include "MonitorVias.h"

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  acelerometro.begin();
  pinMode(5, OUTPUT);
  gps.begin();
  //cartao.begin( );
  // Cada interrupção deve registrar uma linha em branco
  //cartao.gravar( "" );
  for( int contador=0; contador < elementosMedicao; contador++){
    acelerometro.getInformacoes();
    lista[contador] = acelerometro.getEixoZ();
  }
}

void loop() {
  acelerometro.getInformacoes();
  short diferencaZ = abs( acelerometro.getEixoZ() - ultimoZ);
  if( isBump( diferencaZ ) == true ){
    digitalWrite(5, HIGH);
    gps.novasCoordenadas();
    formato.setDados( "red" ,acelerometro.getEixoZ(), gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
/*    Serial.print( ":: Gravar ");
  Serial.print( acelerometro.getEixoZ());
  Serial.print( "-");
  Serial.print( gps.getLongitude() );
  Serial.print( "-");
  Serial.print( gps.getLatitude() );
  Serial.print( "-");
  Serial.println( gps.getTime() );*/
    //cartao.gravar( formato.csv() );
  }
  digitalWrite(5, LOW);
  ultimoZ = acelerometro.getEixoZ();
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
  
  
  Serial.print( ":: Valores ");
  Serial.print( media );
  Serial.print( " - ");
  Serial.print( somaDesvioPadrao );
  Serial.print( " - [ ");
  Serial.print( lista[elementosMedicao-2] - desvioPadrao );
  Serial.print( " - ");
  Serial.print( diferencaZ );
  Serial.print( " - ");
  Serial.print( lista[elementosMedicao-2] + desvioPadrao );
  Serial.println( "]");
  return ( ( ( lista[elementosMedicao-2] - desvioPadrao ) < diferencaZ ) && ( ( lista[elementosMedicao-2] + desvioPadrao ) > diferencaZ) ) ;
}

