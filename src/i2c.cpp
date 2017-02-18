#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "i2c.h"

i2c::i2c(char *dev)
{
    opendev(dev);
}

void i2c::opendev(char *dev)
{
    fd = open(dev, O_RDWR);
    if (fd < 0) {
        perror("i2cOpen");
        exit(1);
    }
}

i2c::~i2c()
{
    close(fd);
}

void i2c::setAddress(uint8_t address)
{
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        perror("i2cSetAddress");
        exit(1);
    }
}

int i2c::writeByte(uint8_t command,uint8_t data)
{
    uint8_t dat[2]={command,data};
    if (write(fd, dat, 2) != 2) {
        perror("pca9555SetRegisterPair");
    }
}

uint8_t i2c::readByte(uint8_t command)
{
    uint8_t data = command;
    if (write(fd, &data, 1) != 1) {
        perror("pca9555ReadRegisterPair set register");
    }
    if (read(fd, &data, 1) != 1) {
        perror("pca9555ReadRegisterPair read value");
    }
    return data;
}
