#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

class i2c {
    int fd;
public:
    i2c(char *dev);
    ~i2c();
    void opendev(char *dev);
    void setAddress(uint8_t address);
    int writeByte(uint8_t command,uint8_t data);
    uint8_t readByte(uint8_t command);

};

#endif
