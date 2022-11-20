// QuadLibrary.cpp
// compile with: cl /c /EHsc QuadLibrary.cpp
// post-build command: lib QuadLibrary.obj

#include "QuadLibrary.h"

std::array<double, 16> OFFSETS = { 
    0, BR1_OFFSET, BR2_OFFSET, BR3_OFFSET,
    0, FL1_OFFSET, FL2_OFFSET, FL3_OFFSET,
    0, FR1_OFFSET, FR2_OFFSET, FR3_OFFSET,
    0, BL1_OFFSET, BL2_OFFSET, BL3_OFFSET
};

std::array<double, 16> MIN_ALLOWED = {
    0, BR1_OFFSET - 10, BR2_OFFSET - 50, BR3_OFFSET - 75,
    0, FL1_OFFSET - 10, FL2_OFFSET - 50, FL3_OFFSET - 75,
    0, FR1_OFFSET - 45, FR2_OFFSET - 15, FR3_OFFSET - 75,
    0, BL1_OFFSET - 45, BL2_OFFSET - 15, BL3_OFFSET - 75
};

std::array<double, 16> MAX_ALLOWED = {
    0, BR1_OFFSET + 45, BR2_OFFSET + 15, BR3_OFFSET + 75,
    0, FL1_OFFSET + 45, FL2_OFFSET + 15, FL3_OFFSET + 75,
    0, FR1_OFFSET + 10, FR2_OFFSET + 50, FR3_OFFSET + 75,
    0, BL1_OFFSET + 10, BL2_OFFSET + 50, BL3_OFFSET + 75
};

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pulseWidth(int angle)
{
    //angle must be between 0 and 180
    angle = angle < 0 ? 0 : angle;
    angle = angle > 180 ? 180 : angle;
    
    int pulse_wide, analog_value;
    pulse_wide = map(angle, 0, 180, USMIN, USMAX);
    analog_value = int(float(pulse_wide) / 1000000 * SERVO_FREQ * 4096);

    return analog_value;
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

/* Limits outputs to avoid hardware damage */
int clamp(int servoId, int degree){
    degree = degree < MIN_ALLOWED[servoId] ? MIN_ALLOWED[servoId]:degree;
    degree = degree > MAX_ALLOWED[servoId] ? MAX_ALLOWED[servoId]:degree;
    return degree;
}

namespace QuadLibrary
{   
    /* Mandatory Setup */
    void Quad::SetupRobot()
    {
        pwm.begin();
        pwm.setOscillatorFrequency(27000000);
        pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz updates
        delay(10);
    }

    /* Reference Positions 90/90/90 degrees*/
    void Quad::ReferencePosition()
    {
        pwm.setPWM(BR1, 0, pulseWidth(BR1_OFFSET)); // BR1
        pwm.setPWM(BR2, 0, pulseWidth(BR2_OFFSET)); // BR2
        pwm.setPWM(BR3, 0, pulseWidth(BR3_OFFSET)); // BR3

        // pwm.setPWM(4, 0, pulseWidth(90));
        pwm.setPWM(FL1, 0, pulseWidth(FL1_OFFSET)); // FL1
        pwm.setPWM(FL2, 0, pulseWidth(FL2_OFFSET)); // FL2
        pwm.setPWM(FL3, 0, pulseWidth(FL3_OFFSET)); // FL3

        // pwm.setPWM(8, 0, pulseWidth(90));
        pwm.setPWM(FR1, 0, pulseWidth(FR1_OFFSET)); // FR1
        pwm.setPWM(FR2, 0, pulseWidth(FR2_OFFSET)); // FR2
        pwm.setPWM(FR3, 0, pulseWidth(FR3_OFFSET)); // FR3

        // pwm.setPWM(12, 0, pulseWidth(90));
        pwm.setPWM(BL1, 0, pulseWidth(BL1_OFFSET));  // BL1
        pwm.setPWM(BL2, 0, pulseWidth(BL2_OFFSET)); // BL2
        pwm.setPWM(BL3, 0, pulseWidth(BL3_OFFSET)); // BL3
    }

    /* Default Dog Stance */
    void Quad::DogInitPosition()
    {
        pwm.setPWM(BR1, 0, pulseWidth(85)); // BR1
        pwm.setPWM(BR2, 0, pulseWidth(40)); // BR2
        pwm.setPWM(BR3, 0, pulseWidth(40)); // BR3

        // pwm.setPWM(4, 0, pulseWidth(90));
        pwm.setPWM(FL1, 0, pulseWidth(75)); // FL1
        pwm.setPWM(FL2, 0, pulseWidth(100)); // FL2
        pwm.setPWM(FL3, 0, pulseWidth(130)); // FL3

        // pwm.setPWM(8, 0, pulseWidth(90));
        pwm.setPWM(FR1, 0, pulseWidth(110)); // FR1
        pwm.setPWM(FR2, 0, pulseWidth(40)); // FR2
        pwm.setPWM(FR3, 0, pulseWidth(40)); // FR3

        // pwm.setPWM(12, 0, pulseWidth(90));
        pwm.setPWM(BL1, 0, pulseWidth(90));  // BL1
        pwm.setPWM(BL2, 0, pulseWidth(140)); // BL2
        pwm.setPWM(BL3, 0, pulseWidth(130)); // BL3
    }
    
    /**
     * @brief Maps the given angle the selected servo
     * 
     * @param servoId 
     * @param degree 
     */
    void Quad::setServo(int servoId, int degree)
    {
        Serial.print("Setting servo " + servoId);
        Serial.print("to = " + clamp(servoId,degree));
        Serial.print("|| w/o Clamp = " + degree);
        pwm.setPWM(servoId, 0, pulseWidth(clamp(servoId,degree)));
    }

}
