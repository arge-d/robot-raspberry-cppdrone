#ifndef _PCA9685_H_
#define _PCA9685_H_
#include <stdint.h>
#include "i2c.h"

#define PCA9685_ADDRESS 0x40

class pca9685 : i2c{
	uint16_t freq;
public:
	pca9685(char *device, uint8_t address=PCA9685_ADDRESS);
	~pca9685();
	void setFreq(uint16_t freq);
	void setPWM(uint8_t channel, uint16_t on, uint16_t off);
	void setAllPWM(uint16_t on, uint16_t off);

};


#endif
