#include "InverseKinematicsLibrary.h"

/**
 * @brief Prueba para recibir query params
 * Imprime los parametros recibidos en la respuesta del servidor
*/
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
  message += server.arg("servo_id"); // Gets the value of servo_id
  message += " with angle = ";
  message += server.arg("angle");

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
  
  /* Validate that we receive at least 4 arguments */
  if (server.arg("x") == "" || server.arg("y") == "" || server.arg("z") == "" || server.arg("leg") == "")
  {
    message = "Please provide x,y,z,leg";
    server.send(500, "text / plain", message); // Returns the HTTP response
    return;
  }

  /* Message for the Server */
  message = "X,Y,Z = ";
  message += server.arg("x");
  message += " , ";
  message += server.arg("y");
  message += " , ";
  message += server.arg("z");
  message += " , ";
  message += server.arg("leg");

  /* Map the Arguments to variables */
  double xPos = server.arg("x").toDouble();
  double yPos = server.arg("y").toDouble();
  double zPos = server.arg("z").toDouble();
  int leg = server.arg("leg").toInt();

  /* Get Angles for the x,y,z position */
  std::array<double, 3> angles = InverseKinematicsLibrary::IK::getServosAngles(leg,xPos,yPos,zPos);

  delay(500);

  /* Message for the Server */
  message = "T1,T2,T3 = ";
  message += angles[0]; 
  message += " , ";
  message += angles[1];
  message += " , ";
  message += angles[2];

  /* Moves the Leg */
  QuadLibrary::Quad::setServo(leg + 1, angles[0]);
  QuadLibrary::Quad::setServo(leg + 2, angles[1]);
  QuadLibrary::Quad::setServo(leg + 3, angles[2]);
  
  server.send(200, "text / plain", message); // Returns the HTTP response
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

void handleMovement()
{
  String message = "such movement";
  server.send(200, "text/plain", message); // Response to the HTTP request
  delay(100);


  int j = 2,leg=server.arg("leg").toInt();
  while (j != 0)
  {
    j--;
    std::array<double, 3> angles;
    for(int i=7;i>4;i--){
      angles = InverseKinematicsLibrary::IK::getServosAngles(leg,6,0.5f,i);
      delay(300);
      /* Moves the FR Leg */
      QuadLibrary::Quad::setServo(leg+1, angles[0]);
      QuadLibrary::Quad::setServo(leg+2, angles[1]);
      QuadLibrary::Quad::setServo(leg+3, angles[2]);
    }
  
    /* Get Angles for this position with the FR leg as reference*/
    angles = InverseKinematicsLibrary::IK::getServosAngles(leg,6,0.5f,5);
    delay(300);
    /* Moves the FR Leg */
    QuadLibrary::Quad::setServo(leg+1, angles[0]);
    QuadLibrary::Quad::setServo(leg+2, angles[1]);
    QuadLibrary::Quad::setServo(leg+3, angles[2]);


  }
}