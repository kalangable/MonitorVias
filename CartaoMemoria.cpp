#include "CartaoMemoria.h"

void CartaoMemoria::begin(const int pin){
	pinMode(SS, OUTPUT);
	if (!SD.begin( pin )) {
	       Serial.println( ":: Erro na inicializacao do SD" );
         Serial.println( ":: Reiniciando Arduino" );
        delay(2000);
        asm volatile ("  jmp 0");
  	} 	
}

void CartaoMemoria::gravar( char *dados ){
	_arquivo = SD.open( "buraco.txt" , FILE_WRITE );
	if ( _arquivo ) {
		while(*dados)
			_arquivo.write( *dados++ );
		  _arquivo.write( '\n' );
	   	_arquivo.close();
	} else {
	    //Serial.println( " :: Nao gravar no arquivo" );
	}
}
