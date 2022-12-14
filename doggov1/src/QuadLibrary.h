// Quad.h
#pragma once

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

#define BR1_OFFSET 75
#define BR2_OFFSET 64
#define BR3_OFFSET 90

#define FL1_OFFSET 72
#define FL2_OFFSET 72
#define FL3_OFFSET 78

#define FR1_OFFSET 117
#define FR2_OFFSET 75
#define FR3_OFFSET 97

#define BL1_OFFSET 95
#define BL2_OFFSET 130
#define BL3_OFFSET 100


#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  150   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600   // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  500      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2500     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50   // Analog servos run at ~50 Hz updates

namespace QuadLibrary
{
    class Quad
    {
    public:

        static void SetupRobot();

        static void ReferencePosition();

        static void DogInitPosition();
        
        static void setServo(int servoId, int degree);

    };
}
