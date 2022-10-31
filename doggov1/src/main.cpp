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

  server.handleClient();

  //This Loops the FR Leg for a while
  // std::array<double, 3> angles = InverseKinematicsLibrary::IK::getServosAngles(0,0,3,5);
  // QuadLibrary::Quad::setServo(9, angles[0]);
  // QuadLibrary::Quad::setServo(10, angles[1]);
  // QuadLibrary::Quad::setServo(11, angles[2]);
  // delay(500);
  // angles = InverseKinematicsLibrary::IK::getServosAngles(0,0,3,6);
  // QuadLibrary::Quad::setServo(9, angles[0]);
  // QuadLibrary::Quad::setServo(10, angles[1]);
  // QuadLibrary::Quad::setServo(11, angles[2]);
  // delay(500);
  // angles = InverseKinematicsLibrary::IK::getServosAngles(0,0,3,7);
  // QuadLibrary::Quad::setServo(9, angles[0]);
  // QuadLibrary::Quad::setServo(10, angles[1]);
  // QuadLibrary::Quad::setServo(11, angles[2]);
  // delay(500);
  // angles = InverseKinematicsLibrary::IK::getServosAngles(0,0,3,8);
  // QuadLibrary::Quad::setServo(9, angles[0]);
  // QuadLibrary::Quad::setServo(10, angles[1]);
  // QuadLibrary::Quad::setServo(11, angles[2]);
  // delay(750);

}

