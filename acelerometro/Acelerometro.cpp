#include "Acelerometro.h"

void Acelerometro::begin(){

	Serial.println( ":: Iniciando Acelerometro" );
	accelero.begin(9, 8, 7, 6, A0, A1, A2);
	accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
	accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
	accelero.calibrate();
}

void Acelerometro::getInformacoes(){
	_x = accelero.getXRaw();
	_y = accelero.getYRaw();
	_z = accelero.getZRaw();
}

int Acelerometro::getEixoX(){
	return _x;
}
int Acelerometro::getEixoY(){
	return _y;
}
int Acelerometro::getEixoZ(){
	return _z;
}
