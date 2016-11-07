#include "MonitorVias.h"

void setup() {
  
  Serial.begin( 9600 );
  while (!Serial);
  acelerometro.begin();
  pinMode(13, OUTPUT);
  //gps.begin();
  //cartao.begin( );
  // Cada interrupção deve registrar uma linha em branco
  //cartao.gravar( ",,,,,,," );
  //contador = 1000;
}

void loop() {

  /*
  contador = 1000;
  Serial.print( "inicio GPS: ");
  tempoI = millis();
  while(contador>0){
    loop_gps();
    contador--;
  }
  tempoT = millis() - tempoI;
  Serial.println( tempoT );
  tempoT = 0;
  
  Serial.print( "inicio acelerometro: ");
  */
  tempoI = millis();
  //cartao.gravar( ",,,,,,," );
  contador = 2718;
   while(contador>0){
    loop_acelerometro();
    modultimoZ = abs(acelerometro.getEixoZ() - ultimoZ);
    if(  modultimoZ > 40   ){
      digitalWrite(13, HIGH);
      Serial.print( " -->");
      Serial.print( modultimoZ );
      Serial.print( " - ");
      Serial.println(acelerometro.getEixoZ());
    }else{
      digitalWrite(13, LOW);
    }
    ultimoZ = acelerometro.getEixoZ();
    contador--;
  }
  
 // cartao.gravar( ",,,,,,," );
  tempoT = millis() - tempoI;
  Serial.print( " -->" );
  Serial.println( tempoT );
  tempoT = 0;
  
}

void loop_gps() {
  
    gps.novasCoordenadas();
    formato.setDados( 1, 1, 1, gps.getLongitude(), gps.getLatitude(), gps.getVelocidade(), millis() );
    //cartao.gravar( formato.csv() );
}


void loop_acelerometro() {
  
  acelerometro.getInformacoes();
  formato.setDados( acelerometro.getEixoX(), acelerometro.getEixoY(), acelerometro.getEixoZ(), 1.0, 1.0, 1.0, millis());
  //cartao.gravar( formato.csv() );
}

void besta() {
  
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

