#include "Robot.h"


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, USMIN, USMAX);
  analog_value = int(float(pulse_wide) / 1000000 * SERVO_FREQ * 4096);
  return analog_value;
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not
// precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;      // 1,000,000 us per second
  pulselength /= SERVO_FREQ;  // Analog servos run at ~60 Hz updates
  Serial.print(pulselength);
  Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength);
  Serial.println(" us per bit");
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

Robot::Robot(){
}

void Robot::setupRobot(){
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
}

void Robot::layDown() {
  pwm.setPWM(BR1, 0, pulseWidth(120));   //BR1
  pwm.setPWM(BR2, 0, pulseWidth(0));   //BR2
  pwm.setPWM(BR3, 0, pulseWidth(90));   //BR3

  // pwm.setPWM(4, 0, pulseWidth(90));
  pwm.setPWM(FL1, 0, pulseWidth(110));   //FL1
  pwm.setPWM(FL2, 0, pulseWidth(0));   //FL2
  pwm.setPWM(FL3, 0, pulseWidth(90));   //FL3
  
  // pwm.setPWM(8, 0, pulseWidth(90));
  pwm.setPWM(FR1, 0, pulseWidth(90));   //FR1
  pwm.setPWM(FR2, 0, pulseWidth(180));  //FR2
  pwm.setPWM(FR3, 0, pulseWidth(90));  //FR3
  
  // pwm.setPWM(12, 0, pulseWidth(90));
  pwm.setPWM(BL1, 0, pulseWidth(110));  //BL1
  pwm.setPWM(BL2, 0, pulseWidth(180)); //BL2
  pwm.setPWM(BL3, 0, pulseWidth(90)); //BL3

}

void Robot::standUp(){
  pwm.setPWM(BR1, 0, pulseWidth(85));   //BR1
  pwm.setPWM(BR2, 0, pulseWidth(40));   //BR2
  pwm.setPWM(BR3, 0, pulseWidth(40));   //BR3

  // pwm.setPWM(4, 0, pulseWidth(90));
  pwm.setPWM(FL1, 0, pulseWidth(60));   //FL1
  pwm.setPWM(FL2, 0, pulseWidth(40));   //FL2
  pwm.setPWM(FL3, 0, pulseWidth(40));   //FL3
  
  // pwm.setPWM(8, 0, pulseWidth(90));
  pwm.setPWM(FR1, 0, pulseWidth(110));   //FR1
  pwm.setPWM(FR2, 0, pulseWidth(120));  //FR2
  pwm.setPWM(FR3, 0, pulseWidth(140));  //FR3
  
  // pwm.setPWM(12, 0, pulseWidth(90));
  pwm.setPWM(BL1, 0, pulseWidth(90));  //BL1
  pwm.setPWM(BL2, 0, pulseWidth(140)); //BL2
  pwm.setPWM(BL3, 0, pulseWidth(130)); //BL3
}


