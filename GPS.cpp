#include "GPS.h"

void GPS::begin(){
    Serial.println( ":: Iniciando GPS" );
    _serialGPS = new SoftwareSerial( 2 , 3 );
    _serialGPS->begin( 9600 );
    while ( _gps.satellites.value() < 4 ) {
        novasCoordenadas( );
    }
    Serial.println(" GPS :: OK");
    setarTempo();
}
long GPS::getTime(){
    if( (now() - _ultimaLeitura) > 600 )
    setarTempo();
    return now();
}
double GPS::getLatitude(){
    return _gps.location.lat();
}
double GPS::getLongitude(){
    return _gps.location.lng();
}
double GPS::getVelocidade(){
    return _gps.speed.kmph();
}
void GPS::novasCoordenadas( ){
    while( !buscarGPS() );
}
bool GPS::buscarGPS( ){
    return ( _serialGPS->available() && _gps.encode( _serialGPS->read()) );
}
void GPS::setarTempo( ){
    while( !buscarGPS() );
    setTime(_gps.time.hour(), _gps.time.minute(), _gps.time.second(), _gps.date.day(),
             _gps.date.month(), _gps.date.year());
    adjustTime( _gmt * SECS_PER_HOUR);
    _ultimaLeitura = now();
}
