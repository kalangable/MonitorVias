#include "Acelerometro.h"

void Acelerometro::begin(){

	Serial.println( ":: Iniciando Acelerometro" );
	accelero.begin(9, 8, 7, 6, A0, A1, A2);
	accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
	accelero.setSensitivity(HIGH);                   //sets the sensitivity to +/-6G
	accelero.calibrate();
}

int Acelerometro::getEixoX(){
	return accelero.getXRaw();
}
int Acelerometro::getEixoY(){
	return accelero.getXRaw();
}
int Acelerometro::getEixoZ(){
	return accelero.getXRaw();
}
