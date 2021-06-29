/*
  gpsPointer.h - Library for fing angle between two gps cordinate.
  Created by Anıl ARAS, December 07, 2018.
  Released into the public domain.
*/
#ifndef gpsPointer_H
#define gpsPointer_H

#include "Arduino.h"
#include <math.h>

class gpsPointer{
    private :
      double lat1, lon1, lat2, lon2;
      static double degreesToRadians(double degrees);
      static double radiansToDegrees(double radians);
      static double ToBearing(double radians);
      static double DegreeBearing(double lat1, double lon1, double lat2, double lon2);
    public :
      double findAngle();
      void setBasePoint(double latitude, double longitude);
      void setTargetPoint(double latitude, double longitude);
      double distance(long double lat1, long double long1,long double lat2, long double long2);
};

#endif
