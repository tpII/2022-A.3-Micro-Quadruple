
ESP8266WebServer server(80);

#include "Server_robot.hpp"

// Funcion que se ejecutara en la URI '/'
void handleRoot() { server.send(200, "text/plain", "Hola mundo!"); }

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
// Serving Hello world
void getHelloWord() {
  server.send(200, "text/json", "{\"name\": \"Hello world\"}");
}

void InitServer() {
  // Ruteo para '/'
  server.on("/", handleRoot);

  // Ruteo para '/inline' usando función lambda
  server.on("/inline",
            []() { server.send(200, "text/plain", "Esto tambien funciona"); });
  server.on("/", HTTP_GET, []() {
    server.send(200, F("text/html"), F("Welcome to the REST Web Server"));
  });
  server.on(F("/helloWorld"), HTTP_GET, getHelloWord);

  server.on(F("/genericArgs"), HTTP_GET, handleGenericArgs);
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