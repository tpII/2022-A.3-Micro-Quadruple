void handleGenericArgs() { //Handler

    String message = "Number of args received:";
    message += server.args();            //Get number of parameters
    message += "\n";                            //Add a new line

    for (int i = 0; i < server.args(); i++) {

    message += "Arg nº" + (String)i + " –> ";   //Include the current iteration value
    message += server.argName(i) + ": ";     //Get the name of the parameter
    message += server.arg(i) + "\n";              //Get the value of the parameter

    } 

    server.send(200, "text/plain", message);       //Response to the HTTP request

}