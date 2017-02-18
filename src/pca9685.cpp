#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <linux/i2c-dev.h>

#include "pca9685.h"

// PCA9685 8bit Registers:
#define PCA9685_ADDRESS 0x40
#define MODE1           0x00
#define MODE2           0x01
#define SUBADR1         0x02
#define SUBADR2         0x03
#define SUBADR3         0x04
#define PRESCALE        0xFE

#define LED0_ON_L       0x06
#define LED0_ON_H       0x07
#define LED0_OFF_L      0x08
#define LED0_OFF_H      0x09

#define ALL_LED_ON_L    0xFA
#define ALL_LED_ON_H    0xFB
#define ALL_LED_OFF_L	0xFC
#define ALL_LED_OFF_H	0xFD

// PCA9685 Bits:
#define RESTART         0x80
#define SLEEP           0x10
#define ALLCALL         0x01
#define INVRT           0x10
#define OUTDRV          0x04

pca9685::pca9685(char *device, uint8_t address): i2c(device)
{
    setAddress(address);
    setAllPWM(0,0);
    writeByte(MODE2, OUTDRV);
    writeByte(MODE1, ALLCALL);
    usleep(5000);/*
    writeByte(MODE1, readByte(MODE1) & ~SLEEP );

    printf("%u",readByte(MODE1));

    usleep(5000);*/
}


pca9685::~pca9685()
{
}

void pca9685::setFreq(uint16_t freq)
{
    this->freq=freq;
    float prescale = (25000000.0/4096.0/(float)freq)-1;
    uint8_t oldmode =readByte(MODE1);
    writeByte(MODE1, (oldmode & 0x7F) | 0x10);
    writeByte(PRESCALE, (uint8_t)(prescale+0.5));
    writeByte(MODE1, oldmode);
    usleep(1000);
    writeByte(MODE1, oldmode | 0x80);
}

void pca9685::setPWM(uint8_t channel, uint16_t on, uint16_t off)
{
    writeByte(LED0_ON_L+4*channel, on & 0xFF);
    writeByte(LED0_ON_H+4*channel, (on & 0xFF00)>>8);
    writeByte(LED0_OFF_L+4*channel, off & 0xFF);
    writeByte(LED0_OFF_H+4*channel, (off & 0xFF00)>>8);
printf("%u,%u,%u,%u\n",readByte(LED0_ON_L),readByte(LED0_ON_H),readByte(LED0_OFF_L),readByte(LED0_OFF_H));
}


void pca9685::setAllPWM(uint16_t on, uint16_t off)
{
    setPWM(61,on,off);
}
