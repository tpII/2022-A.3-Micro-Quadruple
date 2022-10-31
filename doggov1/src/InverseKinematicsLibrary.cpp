#include "InverseKinematicsLibrary.h"

namespace InverseKinematicsLibrary
{
    std::array<double, 3> IK::getServosAngles(int x, int y, int z)
    {
        /* Declare Array with 3 angles*/
        std::array<double, 3> angles;

        double t1;

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

        
        double r = sqrt(((x * x) + (y * y)) + ((z - L1) * (z - L1)));

        double t3 = acos((-(L2 * L2) - (L3 * L3) + (r * r)) / (2 * L2 * L3));

        double b = acos(((r * r) + (L2 * L2) - (L3 * L3)) / (2 * L2 * r));

        double t2 = atan((z - L1) / (sqrt((x * x) + (y * y)))) - b;

        /* Conversion to Degrees */
        angles[0] = t1 * 180.0 / M_PI;;
        angles[1] = t2 * 180.0 / M_PI;;
        angles[2] = t3 * 180.0 / M_PI;;

        /* Returns the Angles in an Array */
        return angles;
    }

}
