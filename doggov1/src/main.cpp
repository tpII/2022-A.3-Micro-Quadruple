#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "QuadLibrary.h"
#include "InverseKinematicsLibrary.h"

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

  
}



void loop() {

  /* Get Angles to this position */
  std::array<double, 3> angles = InverseKinematicsLibrary::IK::getServosAngles(1,-4,4);

  Serial.println(angles[0]);
  Serial.println(angles[1]);
  Serial.println(angles[2]);


  QuadLibrary::Quad::Servos90Grados();
  delay(6000);

  //QuadLibrary::Quad::LayDown();
  delay(6000);


}

