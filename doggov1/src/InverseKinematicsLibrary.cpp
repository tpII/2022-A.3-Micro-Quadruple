#include "InverseKinematicsLibrary.h"

namespace InverseKinematicsLibrary
{

    std::array<double, 3> IK::getServosAngles(int leg, double x, double y, double z)
    {
        /* Declare Array with 3 angles*/
        std::array<double, 3> angles;

        double t1, t2, t3, r, b;

        t1 = atan(y / x);

        r = sqrt(((x * x) + (y * y)) + ((z - L1) * (z - L1)));

        t3 = acos(((r * r) - (L2 * L2) - (L3 * L3)) / (2.0f * L2 * L3));

        b = acos(((r * r) + (L2 * L2) - (L3 * L3)) / (2.0f * L2 * r));

        t2 = atan((z - L1) / (sqrt((x * x) + (y * y)))) - b;


        Serial.print("Value in rad");
        Serial.println();
        Serial.print("Angle[0] rad = ");
        Serial.print(t1);
        Serial.print(" Angle[1] rad = ");
        Serial.print(t2);
        Serial.print(" Angle[2] rad = ");
        Serial.print(t3);
        Serial.println();

        /* Conversion to Degrees */
        angles[0] = t1 * 180.0 / M_PI;
        ;
        angles[1] = t2 * 180.0 / M_PI;
        ;
        angles[2] = t3 * 180.0 / M_PI;
        ;

        /* Angulos entre 0 y 360 grados */
        angles[0] = (int)angles[0] % 360;
        angles[1] = (int)angles[1] % 360;
        angles[2] = (int)angles[2] % 360;

        /* Default 90/90/90 position for the Servos - MOVE OUTSITE WHEN THIS WORKS */
        // FR FL BR BL
        std::array<double, 16> default_servo_pos = {0,
                                                    BR1_OFFSET, BR2_OFFSET, BR3_OFFSET,
                                                    0,
                                                    FL1_OFFSET, FL2_OFFSET, FL3_OFFSET,
                                                    0,
                                                    FR1_OFFSET, FR2_OFFSET, FR3_OFFSET,
                                                    0,
                                                    BL1_OFFSET, BL2_OFFSET, BL3_OFFSET};
        Serial.print("Values");
        Serial.println();
        Serial.print("Angle[0] rad = ");
        Serial.print(t1);
        Serial.print("Angle[0] deg = ");
        Serial.print(angles[0]);
        Serial.print("Angle[1] rad = ");
        Serial.print(t2);
        Serial.print(" Angle[1] deg = ");
        Serial.print(angles[1]);
        Serial.print("Angle[2] rad = ");
        Serial.print(t3);
        Serial.print(" Angle[2] deg = ");
        Serial.print(angles[2]);
        Serial.println();
       
        angles[0] = default_servo_pos[leg+1]- angles[0];
        angles[1] = default_servo_pos[leg+2]+ angles[1];
        angles[2] = default_servo_pos[leg+3]- angles[2]; 
        

        /* Returns the Angles in an Array */
        return angles;
    }

}