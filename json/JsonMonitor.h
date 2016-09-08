#ifndef __JsonMonitor_h
#define __JsonMonitor_h

#include <stdio.h>
#include <stdlib.h>
#include "Arduino.h"

class JsonMonitor
{
	public:
		char *generatedJson( int x, int y, int z, float longitude, float latitude, float velocidade, long _time );
	private:
		char *converter( double __val, signed char __width, unsigned char __prec);
};
#endif
