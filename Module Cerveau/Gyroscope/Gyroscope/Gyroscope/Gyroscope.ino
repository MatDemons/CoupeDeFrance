/**
 *    \file CoupeDeFranceDetection.ino
 *    \brief code de la carte cateurs
 *    \author Nicolas Sobczak
 *    \date Mars 2017
 *  This version of code sends messages with only data from the IR sensors.
 *  During final testing, the ultrasonic sensors were found to be too inconsistent.
 */
//_______________________________________________________________________________________________________


/* ======================================================================================================
 *      Initialisation
 * ======================================================================================================
 */
#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define LED_PIN 13
bool blinkState = false;


//_____________________________________________________________________________________________
//_____________________________________________________________________________________________
void setup() {
        // join I2C bus (I2Cdev library doesn't do this automatically)
        Wire.begin();

        // initialize serial communication
        // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
        // it's really up to you depending on your project)
        Serial.begin(9600);

        // initialize device
        Serial.println("Initializing I2C devices...");
        accelgyro.initialize();

        // verify connection
        Serial.println("Testing device connections...");
        Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

        // configure Arduino LED for
        pinMode(LED_PIN, OUTPUT);
}

void loop() {
        // read raw accel/gyro measurements from device
        // accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        // these methods (and a few others) are also available
        // accelgyro.getAcceleration(&ax, &ay, &az);
        // accelgyro.getRotation(&gx, &gy, &gz);

        gz = accelgyro.getRotationZ();

        // display tab-separated accel/gyro x/y/z values
        Serial.print("\ngz =\t");
        // Serial.print(ax); Serial.print("\t");
        // Serial.print(ay); Serial.print("\t");
        // Serial.print(az); Serial.print("\t");
        // Serial.print(gx); Serial.print("\t");
        // Serial.print(gy); Serial.print("\t");
        Serial.println(gz);

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);

        delay(500);
}