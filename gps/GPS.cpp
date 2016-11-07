#include "GPS.h"

void GPS::begin(){
	Serial.println( ":: Iniciando GPS" );
	serialGPS = new SoftwareSerial( 2 , 3 );
	serialGPS->begin( 9600 );
	while ( gps.satellites.value() < 4 ) {
	    novasCoordenadas( );
	}
	Serial.println(" GPS :: OK");
	
	setarTempo();
}
long GPS::getTime(){
	if( (now() - ultimaLeitura) > 600 )
		setarTempo();
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
	do{
		while( !buscarGPS() );
	}while( getLatitude() > 0 || getLongitude() > 0 );
}
bool GPS::buscarGPS( ){
	return ( serialGPS->available() && gps.encode( serialGPS->read()) );
}
void GPS::setarTempo( ){
	do{
		while( !buscarGPS() );
		/*Serial.print( ":: hora " );
		Serial.println( gps.time.hour() );
		Serial.print( ":: minuto " );
		Serial.println( gps.time.minute() );
		Serial.print( ":: segundo " );
		Serial.println( gps.time.second() );
		Serial.print( ":: dia " );
		Serial.println( gps.date.day() );
		Serial.print( ":: mes " );
		Serial.println( gps.date.month() );
		Serial.print( ":: ano " );
		Serial.println( gps.date.year() );*/
		setTime(gps.time.hour(), gps.time.minute(), gps.time.second(), gps.date.day(), gps.date.month(), gps.date.year());
		adjustTime(offset * SECS_PER_HOUR);
		ultimaLeitura = now();
	}while( ultimaLeitura < 1000000000 );
}