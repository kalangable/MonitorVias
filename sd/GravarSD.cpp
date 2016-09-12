#include "GravarSD.h"

void GravarSD::begin(){
	pinMode(SS, OUTPUT);
	if (!SD.begin( chipSelect )) {
	    	Serial.println( ":: Erro na inicializacao do SD" );
  	} 	
}

void GravarSD::gravar( char *dados ){
	arquivo = SD.open( "buraco.txt" , FILE_WRITE );
	if ( arquivo ) {
		while(*dados)
			arquivo.write( *dados++ );
		arquivo.write( '\n' );
	   	arquivo.close();
	} else {
	    Serial.println( " :: Nao gravar no arquivo" );
	}
}