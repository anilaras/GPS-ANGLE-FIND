/*
  gpsPointer.cpp - Library for fing angle between two gps cordinate.
  Created by Anıl ARAS, December 07, 2018.
  Released into the public domain.
*/

#include "gpsPointer.h"

    double lat1, lon1, lat2, lon2;

    double gpsPointer :: degreesToRadians(double degrees)
    {
        return degrees * (M_PI / 180);
    }
    double gpsPointer :: radiansToDegrees(double radians)
    {
        return radians * 180 / M_PI;
    }
    double gpsPointer :: ToBearing(double radians)
    {
        return fmod((radiansToDegrees(radians) + 360), 360);
    }
    double gpsPointer :: DegreeBearing(double lat1, double lon1, double lat2, double lon2)
    {
        double dLon = degreesToRadians(lon2 - lon1);
        double dPhi = log(tan(degreesToRadians(lat2) / 2 + M_PI / 4) / tan(degreesToRadians(lat1) / 2 + M_PI / 4));
        if (abs(dLon) > M_PI)
            dLon = dLon > 0 ? -(2 * M_PI - dLon) : (2 * M_PI + dLon);
        return ToBearing(atan2(dLon, dPhi));
    }

  
    double gpsPointer :: findAngle()
    {
        return DegreeBearing(this->lat1, this->lon1, this->lat2, this->lon2);
    }
    void gpsPointer :: setBasePoint(double latitude, double longitude)
    {
        this->lat1 = latitude;
        this->lon1 = longitude;
    }

    void gpsPointer :: setTargetPoint(double latitude, double longitude)
    {
        this->lat2 = latitude;
        this->lon2 = longitude;
    }