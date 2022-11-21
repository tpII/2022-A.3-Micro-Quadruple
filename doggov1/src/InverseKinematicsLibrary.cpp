#include "InverseKinematicsLibrary.h"

namespace InverseKinematicsLibrary
{

    std::array<double, 3> IK::getServosAngles(int leg, double x, double y, double z)
    {

        double t1, t2, t3, r, b;

        t1 = atan(y / x);   // If X = 0 we cry

        r = sqrt(((x * x) + (y * y)) + ((z - L1) * (z - L1)));

        t3 = acos(((r * r) - (L2 * L2) - (L3 * L3)) / (2.0f * L2 * L3));

        b = acos(((r * r) + (L2 * L2) - (L3 * L3)) / (2.0f * L2 * r));

        t2 = atan((z - L1) / (sqrt((x * x) + (y * y)))) - b;


        /* Default 90/90/90 positions */
        std::array<double, 16> default_servo_pos = {
            0, BR1_OFFSET, BR2_OFFSET, BR3_OFFSET,
            0, FL1_OFFSET, FL2_OFFSET, FL3_OFFSET,
            0, FR1_OFFSET, FR2_OFFSET, FR3_OFFSET,
            0, BL1_OFFSET, BL2_OFFSET, BL3_OFFSET 
        };

        /* Result Array Converted to Degrees, limited from 0 to 360  */
        std::array<double, 3> angles;

        if((leg == 0) || (leg==8)){
            angles[0] = default_servo_pos[leg + 1] - ((int)(t1 * 180.0 / M_PI) % 360);
            angles[1] = default_servo_pos[leg + 2] + ((int)(t2 * 180.0 / M_PI) % 360);
            angles[2] = default_servo_pos[leg + 3] - ((int)(t3 * 180.0 / M_PI) % 360);
        }

        /* If we calculated for left legs, invert the angles */
        if ((leg == 4) || (leg ==  12)){
            angles[0] = default_servo_pos[leg + 1] + ((int)(t1 * 180.0 / M_PI) % 360);
            angles[1] = default_servo_pos[leg + 2] - ((int)(t2 * 180.0 / M_PI) % 360);
            angles[2] = default_servo_pos[leg + 3] + ((int)(t3 * 180.0 / M_PI) % 360);          
        }
        

        /* Returns the Angles in an Array */
        return angles;
    }

}