#include "Acelerometro.h"

Acelerometro::Acelerometro(){
	accelero.begin(13, 12, 11, 9, A0, A1, A2);
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
