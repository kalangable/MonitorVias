#include "GPS.h"

void GPS::begin(){

	Serial.println( ":: Iniciando GPS" );
	serialGPS = new SoftwareSerial( 2 , 3 );
	serialGPS->begin(9600);
	while ( gps.satellites.value() < 3 ) {
	    Serial.print( "Buscando satelites : ");
	    Serial.println( gps.satellites.value() );
	    novasCoordenadas( );
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

void GPS::novasCoordenadas( ){

	long start = millis();
  	do
  	{
    	while (serialGPS->available())
      		if(gps.encode(serialGPS->read())){
      			setTime(gps.time.hour(), gps.time.minute(), gps.time.second(), gps.date.day(), gps.date.month(), gps.date.year());
    			adjustTime(offset * SECS_PER_HOUR);
      		}
  	} while ((millis() - start < 100 ) && (!gps.location.isValid()));

}