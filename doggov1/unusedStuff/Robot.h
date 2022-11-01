#pragma once
#ifndef Robot_h
#define Robot_h
#endif

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


#include <Adafruit_PWMServoDriver.h>


// called this way, it uses the default address 0x40
// you can also call it with a different address you want
// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 500  // This is the rounded 'minimum' microsecond length based on the minimum
       // pulse of 150
#define USMAX 2500  // This is the rounded 'maximum' microsecond length based on the maximum
        // pulse of 600
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates





class Robot{
    private:
        Adafruit_PWMServoDriver pwm;
        int pulseWidth(int angle);
    public:
        Robot();
        void setupRobot(void);
        void standUp(void);
        void layDown(void);
};