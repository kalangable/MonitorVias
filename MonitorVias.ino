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
  acelerometro.getInformacoes();
  ultimoZ = acelerometro.getEixoZ();
  int soma = 0;
  for( int contador=0; contador < elementosMedicao; contador++){
    acelerometro.getInformacoes();
    lista[contador] = abs(acelerometro.getEixoZ() - ultimoZ);
    soma+=lista[contador];
    ultimoZ = acelerometro.getEixoZ();
  }
  media = soma/elementosMedicao;

  double somaDesvioPadrao = 0.0;
  for( int contador=0; contador < elementosMedicao; contador++){
    somaDesvioPadrao+= pow( float(media-lista[contador]), float(2));
  }
  double variancia = somaDesvioPadrao/(elementosMedicao - 1);
  
  double desvioPadrao = sqrt( variancia );
}

void loop() {
  acelerometro.getInformacoes();
  short leituraAtual = acelerometro.getEixoZ();
  short diferencaZ = abs(leituraAtual - ultimoZ);
  ultimoZ = leituraAtual;
  if( isBump( diferencaZ ) == true ){
    digitalWrite(5, HIGH);
    gps.novasCoordenadas();
    formato.setDados( "red" ,leituraAtual, gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), gps.getTime() );
    //delay(5000);
/*    Serial.print( ":: Gravar ");
  Serial.print( acelerometro.getEixoZ());
  Serial.print( "-");
  Serial.print( gps.getLongitude() );
  Serial.print( "-");
  Serial.print( gps.getLatitude() );
  Serial.print( "-");
  Serial.println( gps.getTime() );*/
    //cartao.gravar( formato.csv() );
  }else{
    digitalWrite(5, LOW);
  }
  

}


bool isBump( int diferencaZ ){

  
  double somaDesvioPadrao = 0.0;
  for( int contador=0; contador < elementosMedicao; contador++){
    somaDesvioPadrao+= pow( float(lista[contador]-media), float(2));
    
    
  }
  
  double variancia = somaDesvioPadrao/(elementosMedicao - 1);
  
  
  double desvioPadrao = sqrt( variancia );
  if( desvioPadrao < 20.00 ){
    desvioPadrao = 20.0;
  }
  
  bool retorno = !( ( ( lista[elementosMedicao-1] - desvioPadrao ) < diferencaZ ) && ( ( lista[elementosMedicao-1] + desvioPadrao ) > diferencaZ) );

  int soma = diferencaZ;
  for( int contador=1; contador < elementosMedicao; contador++){
    lista[contador-1] = lista[contador];
    soma+=lista[contador];
  }
  lista[elementosMedicao-1] = diferencaZ;
  if( retorno ){
    Serial.print( ":: Valores ");
    Serial.print( media );
    Serial.print( " - ");
    Serial.print( desvioPadrao );
    
    Serial.print( " - [ ");
    Serial.print( lista[elementosMedicao-2] - desvioPadrao );
    Serial.print( " < ");
    Serial.print( diferencaZ );
    Serial.print( " > ");
    Serial.print( lista[elementosMedicao-2] + desvioPadrao );
    Serial.println( "]");
  }
  media = soma/elementosMedicao;
  return retorno ;
  
}



bool isBump2( int diferencaZ ){
  
  int soma = diferencaZ;
  double somaDesvioPadrao = pow( float( media - lista[0] ), float(2));
  
  for( int contador=1; contador < elementosMedicao; contador++){
    //Deslocar 1 elemento para traz
    lista[contador-1] = lista[contador];
    // Calcular os valores de variancia
    somaDesvioPadrao += pow( float( lista[contador] - media ), float(2));
    //Preparar a soma dos elementos para calcular a proxima media
    soma+= lista[contador];
  }

  lista[elementosMedicao-1] = diferencaZ;
  
  double variancia = somaDesvioPadrao/(elementosMedicao - 1);
  double desvioPadrao = sqrt( variancia );

  
  
  
 
  
  Serial.print( ":: Valores ");
  Serial.print( media );
  Serial.print( " - ");
  Serial.print( variancia );
  Serial.print( " - ");
  Serial.print( somaDesvioPadrao );
  Serial.print( " - [ ");
  Serial.print( lista[elementosMedicao-2] - desvioPadrao );
  Serial.print( " - ");
  Serial.print( diferencaZ );
  Serial.print( " - ");
  Serial.print( lista[elementosMedicao-2] + desvioPadrao );
  Serial.println( "]");
  media = soma/elementosMedicao;
  return ( ( ( lista[elementosMedicao-2] - desvioPadrao ) < diferencaZ ) && ( ( lista[elementosMedicao-2] + desvioPadrao ) > diferencaZ) ) ;
}

