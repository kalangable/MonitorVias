#include "GPS.h"

void GPS::begin(SoftwareSerial& serial){
	serial.begin(9600);
	while ( gps.satellites.value() < 3 ) {
	    Serial.println("Buscando satelites");
	    novasCoordenadas( serial );
	}
	Serial.println(" GPS :: OK");

}

long GPS::getTime(){
	return now();
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
      		if(gps.encode(serial.read())){
      			setTime(gps.time.hour(), gps.time.minute(), gps.time.second(), gps.date.day(), gps.date.month(), gps.date.year());
    			adjustTime(offset * SECS_PER_HOUR);
      		}
  	} while ((millis() - start < 100 ) && (!gps.location.isValid()));

}