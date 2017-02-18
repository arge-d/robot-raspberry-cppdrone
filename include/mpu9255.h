#ifndef _MPU9255_H_
#define _MPU9255_H_

#include "i2c.h"

class mpu9255:i2c {
public:
    uint16_t accelerometer[3],gyroscope[3];

    mpu9255(char *device, uint8_t address=0x68);

    void readAcceleration();
    void readGyro();
    void readCompass();
    int readTemp();
};


#endif
