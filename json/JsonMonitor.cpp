#include "JsonMonitor.h"

JsonObject& JsonMonitor::generatedJson( int x, int y, int z, double longitude, double latitude, double velocidade, long time ){
    StaticJsonBuffer<200> jsonBuffer;	
	JsonObject& root = jsonBuffer.createObject();
	root["time"] = time;
	root["velocidade"] = velocidade;

	JsonObject& eixoJson = root.createNestedObject("eixo");
	eixoJson["x"] = x;
	eixoJson["y"] = y;
	eixoJson["z"] = z;
	JsonObject& coordenadas = root.createNestedObject("coordenadas");
	coordenadas["latitude"] = JsonVariant(latitude, 6);
	coordenadas["longitude"] = JsonVariant(longitude, 6);
    return root;
}