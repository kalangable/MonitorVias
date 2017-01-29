#include "Formatador.h"

char *Formatador::converter( double __val, signed char __width, unsigned char __prec ){
  char transformacao[30];
  dtostrf( __val , __width , __prec , transformacao );
  return transformacao;
}

char *Formatador::tipoFormato( char *tipo ){
  char root[180];
  sprintf( root, tipo , _time , converter( _velocidade, 5, 2 ), _x , _y , _z , converter( _latitude, 10, 6 ), converter( _longitude, 10, 6 ));
  return root;
}

void Formatador::setDados( int argX, int argY, int argZ, float argLongitude, float argLatitude, float argVelocidade, long argTime ){
	_x = argX;
	_y = argY;
	_z = argZ; 
	_latitude = argLatitude;
	_longitude = argLongitude;
	_velocidade = argVelocidade;
	_time = argTime;
}

char *Formatador::csv(){
  return tipoFormato( "%ld,%s,%d,%d,%d,%s,%s" );
}