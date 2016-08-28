#include "GPS.h"

void GPS::begin(SoftwareSerial& serial){
	serial.begin(9600);
	while ( gps.satellites.value() < 3 ) {
	    Serial.println("Buscando satelites");
	    novasCoordenadas( serial );
	}
}

long GPS::getTime(){
	return 1l;
}
double GPS::getLatitude(){
	return gps.location.lat();
}
double GPS::getLongitude(){
	return gps.location.lng();
}
double GPS::getVelocidade(){
	return gps.speed.kmph();
}

void GPS::novasCoordenadas( SoftwareSerial& serial ){
	long start = millis();
  	do
  	{
    	while (serial.available())
      		gps.encode(serial.read());
  	} while ((millis() - start < 100 ) && (!gps.location.isValid()));
}