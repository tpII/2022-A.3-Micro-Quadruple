ESP8266WebServer server(80);

#include "Server_robot.hpp"

// Funcion que se ejecutara en URI desconocida
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void InitServer() {
  
  server.on(F("/setServo"), HTTP_GET, handleSetServo);
  server.on(F("/getAngles"), HTTP_GET, handleGetServosAngles);
  server.on(F("/referencePosition"), HTTP_GET, handleReferencePosition);
  server.on(F("/dogPosition"), HTTP_GET, handleDogInitPosition);
  server.on(F("/move"), HTTP_GET, handleMovement);
  
  // Ruteo para URI desconocida
  server.onNotFound(handleNotFound);

  // Iniciar servidor
  server.begin();
  Serial.println("HTTP server started");
}