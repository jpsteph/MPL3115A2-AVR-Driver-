#include "I2C.h"
#include "MPL3115A2.h"

void IIC_RegWrite(int8_t slave_address, int8_t reg_val, int8_t data) {

    TWIStart();

    TWIWriteACK(slave_address);

    TWIWrite(reg_val);

    TWIWrite(data);

    TWIStop();

}

uint8_t IIC_RegRead(int8_t slave_address, uint8_t reg_val) {

    uint8_t read_data;

    TWIStart();

    TWIWriteACK(slave_address);

    TWIWrite(reg_val);  

    TWIStart();

    TWIWriteACK(slave_address | 0x01);

    read_data = TWIReadNACK();

    TWIStop();

    return read_data;

}

uint8_t init_MPL3115A2(void) {
    if(0xC4 != IIC_RegRead(SlaveAddressllC, 0x0C)) { //making sure I2C w/ pressure sensor works
        return 0;
    }	

    //getting pressure sensor setup
	IIC_RegWrite(SlaveAddressllC, MPL3115A2_CTRL_REG1, _OS128|_BAR|_SBYB);	//when _SBYB = 1 (active measurement bit) and OST = 0 (one shot measuremt bit) device will make periodic measurements (default has it set to 1 measurement per second, can be changed with CTRL_REG2)
    //_OS128 = 512 ms sampling time from OS[2:0] bits
	IIC_RegWrite(SlaveAddressllC, MPL3115A2_PT_DATA_CFG, 0x07);  //needed to enable STA bit when reading register 0x00
    return 1;

}

uint32_t get_pressure_millibar(void) {
    uint32_t OUT_P_MSB;
	uint32_t OUT_P_CSB;
	uint32_t OUT_P_LSB;
    uint32_t pressure;
    uint8_t STA;    //used to check if pressure sample is ready via i2c read

    STA = IIC_RegRead(SlaveAddressllC, 0x00);

    if(STA & 0x08) {
        OUT_P_MSB = IIC_RegRead(SlaveAddressllC, 0x01);	
        OUT_P_CSB = IIC_RegRead(SlaveAddressllC, 0x02);	
        //fractional part
        OUT_P_LSB = IIC_RegRead(SlaveAddressllC, 0x03); 

        pressure = (OUT_P_MSB << 16) | (OUT_P_CSB << 8) | (OUT_P_LSB);

        return pressure;    
    }
    return 0;

}