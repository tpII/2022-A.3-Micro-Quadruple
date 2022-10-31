#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "Robot.h"  //Robot library


//Wifi dependency
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> 
//Own libraries
#include "config.h"  // Sustituir con datos de vuestra red
#include "Server.hpp"
#include "ESP8266_Utils.hpp"


#define LED 2

Robot robot = Robot();

void setup() {
  Serial.begin(9600);

  digitalWrite(LED, LOW);   // turn the LED on.
  delay(1000);              // wait for a second
  digitalWrite(LED, HIGH);  // turn the LED off
  delay(1000);              // wait for a second

  robot.setupRobot();

  Connect_WiFi_APv2();

  InitServer();
  delay(10);
}



void loop() {

  Serial.println("Hola");
  //-----------------------------
  // PARADO
  robot.standUp();
  delay(6000);
  //-----------------------------
  robot.layDown();
  delay(6000);

  server.handleClient();
}