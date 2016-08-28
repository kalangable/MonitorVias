#include "GravarSD.h"
void GravarSD::begin(){
	if (!SD.begin( 10 )) {
	    	Serial.println( ":: Erro na inicialização do SD" );
	    	return;
  	}
	arquivo = SD.open( "monitor.txt" , FILE_WRITE );
}

void GravarSD::gravar( String dados ){
	if ( arquivo ) {
	   	arquivo.println( dados );
	   	arquivo.flush();
	} else {
	    Serial.println( "Não foi possivel criar o arquivo" );
	}
}
