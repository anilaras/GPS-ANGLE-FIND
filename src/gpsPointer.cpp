/*
  gpsPointer.cpp - Library for fing angle between two gps cordinate.
  Created by Anıl ARAS, December 07, 2018.
  Released into the public domain.
*/

#include "gpsPointer.h"

double lat1, lon1, lat2, lon2;

double gpsPointer::degreesToRadians(double degrees) {
    return degrees * (M_PI / 180);
}
double gpsPointer::radiansToDegrees(double radians) {
    return radians * 180 / M_PI;
}
double gpsPointer::ToBearing(double radians) {
    return fmod((radiansToDegrees(radians) + 360), 360);
}
double gpsPointer::DegreeBearing(double lat1, double lon1, double lat2, double lon2) {
    double dLon = degreesToRadians(lon2 - lon1);
    double dPhi = log(tan(degreesToRadians(lat2) / 2 + M_PI / 4) / tan(degreesToRadians(lat1) / 2 + M_PI / 4));
    if (abs(dLon) > M_PI)
        dLon = dLon > 0 ? -(2 * M_PI - dLon) : (2 * M_PI + dLon);
    return ToBearing(atan2(dLon, dPhi));
}

double gpsPointer::distance(long double lat1, long double long1,
    long double lat2, long double long2) {
    // Convert the latitudes and longitudes from degree to radians. 
    lat1 = degreesToRadians(lat1);
    long1 = degreesToRadians(long1);
    lat2 = degreesToRadians(lat2);
    long2 = degreesToRadians(long2);

    // Haversine Formula 
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in Kilometers, R = 6371 
    // Use R = 3956 for miles 
    long double R = 6371;

    // Calculate the result 
    ans = ans * R;

    return ans;
}

double gpsPointer::findAngle() {
    return DegreeBearing(this -> lat1, this -> lon1, this -> lat2, this -> lon2);
}
void gpsPointer::setBasePoint(double latitude, double longitude) {
    this -> lat1 = latitude;
    this -> lon1 = longitude;
}

void gpsPointer::setTargetPoint(double latitude, double longitude) {
    this -> lat2 = latitude;
    this -> lon2 = longitude;
}
