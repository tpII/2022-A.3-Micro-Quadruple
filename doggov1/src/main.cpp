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
  Serial.println("");
  Serial.println("Welcome to Manchitas V1.0");
  Serial.println("Please refer to the AP for controlling the Robot");
  Serial.println("------------------------------------------------");


  /* Led on - Led Off*/
  digitalWrite(LED, LOW); 
  delay(1000);            
  digitalWrite(LED, HIGH);
  delay(1000);            

  QuadLibrary::Quad::SetupRobot();
  delay(2000);

  Connect_WiFi_APv2();

  InitServer();
  delay(10);

  
}



void loop() {

  server.handleClient();

}

