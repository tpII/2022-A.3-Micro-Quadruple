#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define LED 2

#define BR1 1
#define BR2 2
#define BR3 3

#define FL1 5
#define FL2 6
#define FL3 7

#define FR1 9
#define FR2 10
#define FR3 11

#define BL1 13
#define BL2 14
#define BL3 15

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  500 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2500 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum;

void standUp();

void layDown();

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, USMIN, USMAX);
  analog_value = int(float(pulse_wide) / 1000000 * SERVO_FREQ * 4096);
  return analog_value;
}

void setup() {
  Serial.begin(9600);
  Serial.println("8 chaasdasdnnel Servo test!");
  digitalWrite(LED, LOW); // turn the LED on.
  delay(1000);            // wait for a second
  digitalWrite(LED, HIGH);// turn the LED off
  delay(1000);            // wait for a second

  pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  servonum = 13;
  delay(10);
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  // Drive each servo one at a time using setPWM()
  Serial.println(servonum);
  //-----------------------------
  // PARADO
  standUp();  
  delay(6000);
  //-----------------------------
  layDown();
  delay(6000);
}

void layDown() {
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

void standUp(){
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