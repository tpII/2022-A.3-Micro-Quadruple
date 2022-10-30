#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define LED 2

/* WIFI LIBS */
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


const char *ssid = "ESP8266 AP"; // The name of the Wi-Fi network that will be created
const char *password = "password";   // The password required to connect to it, leave blank for an open network


ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected!</h1>");
}

/* The robot will Stand Up */
void handleUp() {
  server.send(200, "text/html", "<h1>You are connected!</h1>");
}


void setup() {
  Serial.begin(9600);
  Serial.println("");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.println(myIP);
  

  server.on("/", handleRoot);
  server.on("/up", handleUp);
  server.begin();
  Serial.println("HTTP server started");
  
}

void loop() {
  // TODO
  server.handleClient();
}
