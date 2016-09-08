#ifndef __GravarSD_h
#define __GravarSD_h

#include <SD.h>
#include <SPI.h>

class GravarSD
{
	public:
		void begin();
    	void gravar( char *dados );

    private:
    	File arquivo;
    	const int chipSelect = 4;
};
#endif
