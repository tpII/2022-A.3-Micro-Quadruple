/*
 *  Simple hello world Json REST response
  *  by Mischianti Renzo <https://www.mischianti.org>
 *
 *  https://www.mischianti.org/
 *
 */
 
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
#include "config.h"  // Sustituir con datos de vuestra red
#include "Server.hpp"
#include "ESP8266_Utils.hpp"
 
// Serving Hello worl
 
// void setup(void) {
//   Serial.begin(74880);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.println("");
 
//   // Wait for connection
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.print("Connected to ");
//   Serial.println(ssid);
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
 
//   // Activate mDNS this is used to be able to connect to the server
//   // with local DNS hostmane esp8266.local
//   if (MDNS.begin("esp8266")) {
//     Serial.println("MDNS responder started");
//   }
 
//   // Set server routing
//   restServerRouting();
//   // Set not found response
//   server.onNotFound(handleNotFound);
//   // Start server
//   server.begin();
//   Serial.println("HTTP server started");
// }
 
// void loop(void) {
//   server.handleClient();
// }

void setup(void) 
{
   Serial.begin(115200);
   
   Connect_WiFi_APv2();
 
   InitServer();
}
 
void loop()
{
   server.handleClient();
}
