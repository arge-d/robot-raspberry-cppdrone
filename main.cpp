#include <stdio.h>

#include <unistd.h>

#include "pid.h"
#include "pca9685.h"
#include "mpu9255.h"


int main() {
    char device[20]="/dev/i2c-1";
    pca9685 controller(device);
    uint8_t gas=25;
    controller.setFreq(120);
    controller.setAllPWM(0, (((float)gas/100.0+1.0)/1000.0*120.0)*4095.0);

    //mpu9255 sensor(device);
    //for(;;usleep(50000),sensor.readAcceleration())  printf("%u,%u,%u\n",sensor.accelerometer[0],sensor.accelerometer[1],sensor.accelerometer[2]);
    return 0;
}
