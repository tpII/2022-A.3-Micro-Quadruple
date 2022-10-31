// InverseKinematicsLibrary.h
#pragma once

#define L1 1.5 //May be 4 tbh
#define L2 4
#define L3 4

#define M_PI 3.14159265358979323846  /* pi */


#include<array>
#include <tgmath.h> 

namespace InverseKinematicsLibrary
{
    class IK
    {
    public:
        
        /** Function that returns the 3 angles for the Front Right Leg (FR1) */
        static std::array<double,3> getServosAngles(int leg, double x, double y, double z);

    };
}