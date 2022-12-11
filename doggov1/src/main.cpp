
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


#define LED D0


void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Welcome to Manchitas V1.0");
  Serial.println("Please refer to the AP for controlling the Robot");
  Serial.println("------------------------------------------------");
  Serial.println("/layDown /standUp /dogPosition /referencePosition");
  Serial.println("/getAngles?x=0&y=5&z=7 For Example");
  Serial.println("/setServo?servo_id=9&angle=110 For Example");
  Serial.println("------------------------------------------------");
  delay(1000);

  
  digitalWrite(LED, LOW); // turn the LED on.
  delay(1000);            // wait for a second
  digitalWrite(LED, HIGH);// turn the LED off
  delay(1000);            // wait for a second

  QuadLibrary::Quad::SetupRobot();
  delay(2000);

  Connect_WiFi_APv2();

  InitServer();
  delay(2000);
  QuadLibrary::Quad::DogInitPosition();
  digitalWrite(LED, LOW); // turn the LED on.
  delay(4000);            // wait for a second
  digitalWrite(LED, HIGH);// turn the LED off
  delay(100);
  
}



void loop() {

  server.handleClient();
}

