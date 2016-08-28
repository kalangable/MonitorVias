#include "JsonMonitor.h"

String JsonMonitor::generatedStringJson( int x, int y, int z, double longitude, double latitude, double velocidade, long time ){
    StaticJsonBuffer<200> jsonBuffer;	
	JsonObject& root = jsonBuffer.createObject();
//	root["data"] = info.data;
	root["time"] = time;
	root["velocidade"] = velocidade;

	JsonObject& eixoJson = root.createNestedObject("eixo");
	eixoJson["x"] = x;
	eixoJson["y"] = y;
	eixoJson["z"] = z;
	JsonObject& coordenadas = root.createNestedObject("coordenadas");
	coordenadas["longitude"] = JsonVariant(longitude, 6);
	coordenadas["latitude"] = JsonVariant(latitude, 6);

    String jsonBody;
    root.printTo(jsonBody);
    return jsonBody;
}