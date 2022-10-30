void handleGenericArgs() {  // Handler

  String message = "Number of args received:";
  message += server.args();  // Get number of parameters
  message += "\n";           // Add a new line

  for (int i = 0; i < server.args(); i++) {
    message +=
        "Arg nro " + (String)i + " -> ";  // Include the current iteration value
    message += server.argName(i) + ": ";  // Get the name of the parameter
    message += server.arg(i) + "\n";      // Get the value of the parameter
  }

  server.send(200, "text/plain", message);  // Response to the HTTP request
}

void handleSetServo() {
  String message = "";

  if (server.arg("servo_id") == "" || server.arg("angle")== "") {  // Parameter not found

    message = "servo_id or angle not specified";
    server.send(500, "text / plain", message);  // Returns the HTTP response
    return;

  }
    // Parameter found

    message = "Servo: = ";
    message +=
        server.arg("servo_id");  // Gets the value of servo_id
    message+= " with angle = ";
    message+= 
        server.arg("angle");
  
  int servoId = server.arg("servo_id").toInt();
  int angle = server.arg("angle").toInt();


  QuadLibrary::Quad::setServo(servoId, angle);
  server.send(200, "text / plain", message);  // Returns the HTTP response
}

void handleSetServov2() {  // Handler

  String message = "Number of args received:";
  message += server.args();  // Get number of parameters
  message += "\n";           // Add a new line

  for (int i = 0; i < server.args(); i++) {
    message +=
        "Arg nro " + (String)i + " -> ";  // Include the current iteration value
    message += server.argName(i) + ": ";  // Get the name of the parameter
    message += server.arg(i) + "\n";      // Get the value of the parameter
  }

  
  server.send(200, "text/plain", message);  // Response to the HTTP request
}


//Para tirarse
void handleDefaultPosition(){
  String message = "Standing up:";
  server.send(200, "text/plain", message);  // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::DefaultPosition();
  delay(1000);
}

//Para levantarse
void handleLayDown(){
  String message = "Laying down:";
  server.send(200, "text/plain", message);  // Response to the HTTP request
  delay(100);
  QuadLibrary::Quad::LayDown();
  delay(1000);
  
}