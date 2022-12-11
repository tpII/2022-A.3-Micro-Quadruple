#include "InverseKinematicsLibrary.h"


void setServoLeg(std::array<double, 3> angles, int leg){
  QuadLibrary::Quad::setServo(leg + 1, angles[0]);
  QuadLibrary::Quad::setServo(leg + 2, angles[1]);
  QuadLibrary::Quad::setServo(leg + 3, angles[2]);  
}

void inverseKinematicsLeg(int leg, double x,double y, double z){
  std::array<double, 3> angles;
  angles = InverseKinematicsLibrary::IK::getServosAngles(leg,x,y,z,0);
  setServoLeg(angles,leg);
}

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
  std::array<double, 3> angles = InverseKinematicsLibrary::IK::getServosAngles(leg,xPos,yPos,zPos,1);

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
  delay(100);
  // x -> 7.98  y -> 0  z -> 2.05
  QuadLibrary::Quad::ReferencePosition();
  delay(500);
  server.send(200, "text/plain", message); // Response to the HTTP request
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

void handleLeanFront()
{
  String message = "Lean front";
  delay(100);
  inverseKinematicsLeg(8,2,0.5,8.5);
  inverseKinematicsLeg(4,2,0.5,8.5);
  inverseKinematicsLeg(0,7.5,1,4);
  inverseKinematicsLeg(12,7.5,1,4);
  delay(100);
  server.send(200, "text/plain", message); // Response to the HTTP request
}

void handleLeanBack()
{
  String message = "Lean back";
  delay(100);
  inverseKinematicsLeg(8,7,0.5,-2);
  inverseKinematicsLeg(4,7,0.5,-2);
  inverseKinematicsLeg(0,2,0.5,2);
  inverseKinematicsLeg(12,2,0.5,2);
  delay(100);
  server.send(200, "text/plain", message); // Response to the HTTP request
}

void handleMovement()
{
  String message = "Moving robot";
 std::array<std::array<double,3>,6> anglesFront = {{
    {6,0.5,5},
    {4,0.5,6},
    {3,0.5,7},
    {4,0.5,6},
    {6,0.5,5},
    {7,0.5,-1}
  }};
  std::array<std::array<double,3>,6> anglesBack = {{
    {7,1,1},
    {7.5,1,2.5},
    {7.5,1,4},
    {7.5,1,2.5},
    {7,1,1},
    {6.5,1,-3}
  }};
  delay(100);
  int delayAmount=server.arg("delay").toInt();
  delayAmount = delayAmount <100 ? 100: delayAmount>1000 ? 1000:delayAmount;
  // New Way to move the robot
  for(int i=0;i<2;i++){
    int start = i*3;
    int end = (i+1)*3;
    for(int k=start;k<end;k++){
      inverseKinematicsLeg(8,anglesFront[k][0],anglesFront[k][1],anglesFront[k][2]);
      delay(delayAmount);
    }
    for(int k=start;k<end;k++){
      inverseKinematicsLeg(12,anglesBack[k][0],anglesBack[k][1],anglesBack[k][2]);
      delay(delayAmount);
    }
    for(int k=start;k<end;k++){
      inverseKinematicsLeg(4,anglesFront[k][0],anglesFront[k][1],anglesFront[k][2]);
      delay(delayAmount);
    }
    for(int k=start;k<end;k++){
      inverseKinematicsLeg(0,anglesBack[k][0],anglesBack[k][1],anglesBack[k][2]);
      delay(delayAmount);
    }
  }
  server.send(200, "text/plain", message); // Response to the HTTP request
}