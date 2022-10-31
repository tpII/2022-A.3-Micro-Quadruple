#include "InverseKinematicsLibrary.h"

namespace InverseKinematicsLibrary
{

    std::array<double, 3> IK::getServosAngles(int leg, double x, double y, double z)
    {
        /* Declare Array with 3 angles*/
        std::array<double, 3> angles;

        double t1, t2, t3, r, b;

        if ((x >= 0) && (y >= 0))
        {
            t1 = atan(y / x);
        }
        else if ((x <= 0) && (y <= 0))
        {
            t1 = M_PI + atan(y / x);
        }
        else if ((x > 0) && (y < 0))
        {
            t1 = 2 * M_PI - atan(y / x);
        }
        else
            t1 = M_PI - atan(y / x);

        r = sqrt(((x * x) + (y * y)) + ((z - L1) * (z - L1)));

        t3 = acos((-(L2 * L2) - (L3 * L3) + (r * r)) / (2 * L2 * L3));

        b = acos(((r * r) + (L2 * L2) - (L3 * L3)) / (2 * L2 * r));

        t2 = atan((z - L1) / (sqrt((x * x) + (y * y)))) - b;

        /* Conversion to Degrees */
        angles[0] = t1 * 180.0 / M_PI;
        ;
        angles[1] = t2 * 180.0 / M_PI;
        ;
        angles[2] = t3 * 180.0 / M_PI;
        ;

        /* Angulos en el Primer cuadrante*/
        if (angles[0] > 359)
        {
            angles[0] -= 360;
        }
        if (angles[1] > 359)
        {
            angles[1] -= 360;
        }
        if (angles[2] > 359)
        {
            angles[2] -= 360;
        }

        /* Default 90/90/90 position for the Servos - MOVE OUTSITE WHEN THIS WORKS */
        // FR FL BR BL
        std::array<double, 12> default_servo_pos = {110, 80, 90, 70, 70, 90, 80, 65, 90, 90, 120, 90};

        /* First Angle has no deviation, ever */
        for (size_t i = 1; i < 3; i++)
        {
            angles[i] += default_servo_pos[i + leg];
        }

        /* Returns the Angles in an Array */
        return angles;
    }

}