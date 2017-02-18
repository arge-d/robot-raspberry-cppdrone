#include "mpu9255.h"


mpu9255::mpu9255(char *device, uint8_t address) : i2c(device)
{
    /*

    class mpu9255:
    	def __init__(self, bus):
    		self.__addr=0x68
    		self.__bus=bus
    		self.__bus.write_byte_data(self.__addr,0x6B,0x00)
    		self.__bus.write_byte_data(self.__addr,0x19,0x07)
    		self.__bus.write_byte_data(self.__addr,0x1A,0x18)
    		self.__bus.write_byte_data(self.__addr,0x1B,0x18)
    		self.__bus.write_byte_data(self.__addr,0x1C,0x01)
    		if(0x73!=self.__bus.read_byte_data(self.__addr,0x75)):
    			print("MPU ERROR")
    		buffer = self.__bus.read_i2c_block_data(self.__addr,0x3B,6)
    		self.__acc= [ctypes.c_int16(buffer[2*i]*16*16+buffer[2*i+1]).value/32768 for i in range(3)]
    	def readAcceleration(self):
    		buffer = self.__bus.read_i2c_block_data(self.__addr,0x3B,6)
    		return [ctypes.c_int16(buffer[2*i]*16*16+buffer[2*i+1]).value/32768*math.pi-self.__acc[i] for i in range(3)]
    	def readGyroscope(self):
    		buffer = self.__bus.read_i2c_block_data(self.__addr,0x43,6)
    		return [buffer[2*i]*16*16+buffer[2*i+1] for i in range(3)]
    	def readCompass(self):
    		buffer = 0
    		return buffer
    	def readTemperature(self):
    		buffer = self.__bus.read_i2c_block_data(self._addr,0x41,2)
    		return buffer[0]<<8+buffer[1]

    */
    setAddress(address);
    writeByte(0x6B, 0x00);
    writeByte(0x19, 0x07);
    writeByte(0x1A, 0x18);
    writeByte(0x1B, 0x18);
    writeByte(0x1C, 0x01);
    if (0x73 != readByte(0x75));;// perror("MPU ERROR");

}

void mpu9255::readAcceleration()
{
/*    buffer = self.__bus.read_i2c_block_data(self.__addr,0x3B,6)
    return [ctypes.c_int16(buffer[2*i]*16*16+buffer[2*i+1]).value/32768*math.pi-self.__acc[i] for i in range(3)]*/
    for(unsigned i=0;i<3;i++) accelerometer[i] = readByte(0x3B+2*i)<<8|readByte(0x3C+2*i+1);
}

void mpu9255::readGyro()
{
    for(unsigned i=0;i<3;i++) gyroscope[i] = readByte(0x3B+2*i)<<8|readByte(0x3C+2*i+1);
}

void mpu9255::readCompass()
{

}

int mpu9255::readTemp()
{

}
