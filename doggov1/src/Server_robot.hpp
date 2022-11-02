#include "InverseKinematicsLibrary.h"


void handleGenericArgs()
{ // Handler

  String message = "Number of args received:";
  message += server.args(); // Get number of parameters
  message += "\n";          // Add a new line

  for (int i = 0; i < server.args(); i++)
  {
    message +=
        "Arg nro " + (String)i + " -> "; // Include the current iteration value
    message += server.argName(i) + ": "; // Get the name of the parameter
    message += server.arg(i) + "\n";     // Get the value of the parameter
  }

  server.send(200, "text/plain", message); // Response to the HTTP request
}

void handleSetServo()
{
  String message = "";

  if (server.arg("servo_id") == "" || server.arg("angle") == "")
  { // Parameter not found

    message = "servo_id or angle not specified";
    server.send(500, "text / plain", message); // Returns the HTTP response
    return;
  }
  // Parameter found

  message = "Servo: = ";
  message +=
      server.arg("servo_id"); // Gets the value of servo_id
  message += " with angle = ";
  message +=
      server.arg("angle");

  int servoId = server.arg("servo_id").toInt();
  int angle = server.arg("angle").toInt();

  QuadLibrary::Quad::setServo(servoId, angle);
  server.send(200, "text / plain", message); // Returns the HTTP response
}

void handleSetServov2()
{ // Handler

  String message = "Number of args received:";
  message += server.args(); // Get number of parameters
  message += "\n";          // Add a new line

  for (int i = 0; i < server.args(); i++)
  {
    message +=
        "Arg nro " + (String)i + " -> "; // Include the current iteration value
    message += server.argName(i) + ": "; // Get the name of the parameter
    message += server.arg(i) + "\n";     // Get the value of the parameter
  }

  server.send(200, "text/plain", message); // Response to the HTTP request
}

void handleGetServosAngles()
{
  String message = "";

  if (server.arg("x") == "" || server.arg("y") == "" || server.arg("z") == "")
  { // Parameter not found

    message = "Please provide x,y,z";
    server.send(500, "text / plain", message); // Returns the HTTP response
    return;
  }
  // Parameter found

  message = "X,Y,Z = ";
  message += server.arg("x"); // Gets the value of servo_id
  message += " , ";
  message += server.arg("y");
  message += " , ";
  message += server.arg("z");

  int xPos = server.arg("x").toDouble();
  int yPos = server.arg("y").toDouble();
  int zPos = server.arg("z").toDouble();

  // Serial.println(xPos);
  // Serial.println(yPos);
  // Serial.println(zPos);

  /* Get Angles for this position with the FR leg as reference*/
  std::array<double, 3> angles = InverseKinematicsLibrary::IK::getServosAngles(0,xPos,yPos,zPos);

  delay(500);

  message = "T1,T2,T3 = ";
  message += angles[0]; // Gets the value of servo_id
  message += " , ";
  message += angles[1];
  message += " , ";
  message += angles[2];

  /* Moves the FR Leg */
  QuadLibrary::Quad::setServo(9, angles[0]);
  QuadLibrary::Quad::setServo(10, angles[1]);
  QuadLibrary::Quad::setServo(11, angles[2]);
  
  server.send(200, "text / plain", message); // Returns the HTTP response
}

// Para tirarse
void handleDefaultPosition()
{
  String message = "Standing up:";
  server.send(200, "text/plain", message); // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::DefaultPosition();
  delay(1000);
}

// Para levantarse
void handleLayDown()
{
  String message = "Laying down:";
  server.send(200, "text/plain", message); // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::LayDown();
  delay(1000);
}

// Reference Positions
void handleReferencePosition()
{
  String message = "Reference Position for IK Calculations:";
  server.send(200, "text/plain", message); // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::ReferencePosition();
  delay(1000);
}

// Dog Position
void handleDogInitPosition()
{
  String message = "Dog Init Position";
  server.send(200, "text/plain", message); // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::DogInitPosition();
  delay(1000);
}