#ifndef __JsonMonitor_h
#define __JsonMonitor_h

#include "Arduino.h"
#include "ArduinoJson.h"

#include "../acelerometro/Acelerometro.h"
#include "../gps/GPS.h"

class JsonMonitor
{
	public:
		String generatedStringJson( int x, int y, int z, double longitude, double latitude, double velocidade, long time );
};
#endif
