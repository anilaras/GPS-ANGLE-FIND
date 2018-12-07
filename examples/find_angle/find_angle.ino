#include <gpsPointer.h>

gpsPointer gps;

void setup(){
    Serial.begin(9600);
}


void loop(){
    gps.setBasePoint(40.182846, 29.067084);   //latitude, longitude
    gps.setTargetPoint(39.750545, 37.015022); //latitude, longitude
    double gpsAngle = gps.findAngle();        //degree
    Serial.println(gpsAngle);
    delay(1000);
}