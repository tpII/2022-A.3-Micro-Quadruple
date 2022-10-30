#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "QuadLibrary.h"


//Wifi dependency
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> 
//Own libraries
#include "config.h"  // Sustituir con datos de vuestra red
#include "Server.hpp"
#include "ESP8266_Utils.hpp"


#define LED 2





void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  
  digitalWrite(LED, LOW); // turn the LED on.
  delay(1000);            // wait for a second
  digitalWrite(LED, HIGH);// turn the LED off
  delay(1000);            // wait for a second

  QuadLibrary::Quad::SetupRobot();
  delay(2000);

  Connect_WiFi_APv2();

  InitServer();
  delay(10);

  
}



void loop() {

  // QuadLibrary::Quad::DefaultPosition();
  // delay(6000);

  // QuadLibrary::Quad::LayDown();
  // delay(6000);

  server.handleClient();
}

