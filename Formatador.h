#ifndef __Formatador_h
#define __Formatador_h

#include <stdio.h>
#include <stdlib.h>
#include "Arduino.h"

class Formatador
{
	public:
		void setDados( int argX, int argY, int argZ, float argLongitude, float argLatitude, float argVelocidade, long argTime );
		char *csv( );
	private:
		int _x, _y, _z; 
		float _latitude, _longitude, _velocidade;
		long _time;
		char *tipoFormato( char *tipo );
		char *converter( double __val, signed char __width, unsigned char __prec);
};
#endif
