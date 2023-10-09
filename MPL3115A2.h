
#include <stdint.h>

#define SlaveAddressllC 0xC0
#define MPL3115A2_ADDRESS_write                 (0xC0)    
#define MPL3115A2_ADDRESS_read                  (0xC1)   
#define MPL3115A2_REGISTER_STATUS               (0x00)
#define MPL3115A2_REGISTER_STATUS_TDR           (0x02)
#define MPL3115A2_REGISTER_STATUS_PDR           (0x04)
#define MPL3115A2_REGISTER_STATUS_PTDR          (0x08)
#define MPL3115A2_REGISTER_PRESSURE_MSB         (0x01)
#define MPL3115A2_REGISTER_PRESSURE_CSB         (0x02)
#define MPL3115A2_REGISTER_PRESSURE_LSB         (0x03)
#define MPL3115A2_REGISTER_TEMP_MSB             (0x04)
#define MPL3115A2_REGISTER_TEMP_LSB             (0x05)
#define MPL3115A2_REGISTER_DR_STATUS            (0x06)
#define MPL3115A2_OUT_P_DELTA_MSB               (0x07)
#define MPL3115A2_OUT_P_DELTA_CSB               (0x08)
#define MPL3115A2_OUT_P_DELTA_LSB               (0x09)
#define MPL3115A2_OUT_T_DELTA_MSB               (0x0A)
#define MPL3115A2_OUT_T_DELTA_LSB               (0x0B)
#define MPL3115A2_device_ID                     (0x0C)
#define MPL3115A2_PT_DATA_CFG                   (0x13)
#define MPL3115A2_PT_DATA_CFG_TDEFE             (0x01)
#define MPL3115A2_PT_DATA_CFG_PDEFE             (0x02)
#define MPL3115A2_PT_DATA_CFG_DREM              (0x04)
#define MPL3115A2_CTRL_REG1                     (0x26)
#define _SBYB                                   (0x01)
#define MPL3115A2_CTRL_REG1_OST                 (0x02)
#define MPL3115A2_CTRL_REG1_RST                 (0x04)
#define _OS1                                    (0x00)
#define _OS2                                    (0x08)
#define _OS4                                    (0x10)
#define _OS8                                    (0x18)
#define _OS16                                   (0x20)
#define _OS32                                   (0x28)
#define _OS64                                   (0x30)
#define _OS128                                  (0x38)
#define MPL3115A2_CTRL_REG1_RAW                 (0x40)
#define  _ALT                                   (0x80)
#define  _BAR                                   (0x00)
#define MPL3115A2_CTRL_REG2                     (0x27)
#define MPL3115A2_CTRL_REG3                     (0x28)
#define MPL3115A2_CTRL_REG4                     (0x29)
#define MPL3115A2_CTRL_REG5                     (0x2A)
#define MPL3115A2_REGISTER_STARTCONVERSION      (0x12)

void IIC_RegWrite(int8_t slave_address, int8_t reg_val, int8_t data);

uint8_t IIC_RegRead(int8_t slave_address, uint8_t reg_val);

uint8_t init_MPL3115A2(void); 

uint32_t get_pressure_millibar(void);

