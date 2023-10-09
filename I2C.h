
#include <stdint.h>

void TWIInit(uint32_t speed_hz);

void TWIStart(void);

void TWIStop(void);

void TWIWrite(uint8_t u8data);

void TWIWriteRestartACK(uint8_t u8data);

void TWIWriteACK(uint8_t u8data);

uint8_t TWIReadACK(void);

uint8_t TWIReadNACK(void);

uint8_t TWIGetStatus(void);

