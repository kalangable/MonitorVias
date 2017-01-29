#include "Acelerometro.h"

void Acelerometro::begin(){
    
    Serial.println( ":: Iniciando Acelerometro" );
    _accelero.begin(9, 8, 7, 6, A0, A1, A2);
    _accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
    _accelero.setSensitivity(HIGH);                   //sets the sensitivity to +/-6G
    _accelero.calibrate();
}

void Acelerometro::getInformacoes(){
    _x = _accelero.getXRaw();
    _y = _accelero.getYRaw();
    _z = _accelero.getZRaw();
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
