#include "JsonMonitor.h"

char *JsonMonitor::converter( double __val, signed char __width, unsigned char __prec){
 
  char transformacao[30];
  dtostrf( __val , __width , __prec , transformacao );
  return transformacao;

}

char *JsonMonitor::generatedJson( int x, int y, int z, float longitude, float latitude, float velocidade, long _time ){
  char root[180];
  //sprintf( root, "%ld ,\"velocidade\":%s ,\"eixo\":{\"x\":%d,\"y\":%d,\"z\":%d},\"coordenadas\":{\"longitude\":%s,\"latitude\":%s}}", _time , converter( velocidade, 5, 2 ), x , y , z , converter( longitude, 10, 6 ), converter( latitude, 10, 6 ));
  sprintf( root, "%ld,%s,%d,%d,%d,%s,%s", _time , converter( velocidade, 5, 2 ), x , y , z , converter( longitude, 10, 6 ), converter( latitude, 10, 6 ));
  return root;
    
}