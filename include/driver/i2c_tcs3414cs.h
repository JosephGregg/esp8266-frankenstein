#ifndef __I2C_TCS3414_H
#define	__I2C_TCS3414_H

#include "c_types.h"
#include "ets_sys.h"
#include "osapi.h"

#define TCS3414_ADDRESS   0x72
//also address maybe 52 or 92

#define TCS3414_REG_CTL 0x80
#define TCS3414_REG_TIMING 0x81
#define TCS3414_REG_INT 0x82
#define TCS3414_REG_INT_SOURCE 0x83
#define TCS3414_REG_ID 0x84
#define TCS3414_REG_GAIN 0x87
#define TCS3414_REG_LOW_THRESH_LOW_BYTE 0x88
#define TCS3414_REG_LOW_THRESH_HIGH_BYTE 0x89
#define TCS3414_REG_HIGH_THRESH_LOW_BYTE 0x8A
#define TCS3414_REG_HIGH_THRESH_HIGH_BYTE 0x8B
#define TCS3414_REG_BLOCK_READ 0xCF
#define TCS3414_REG_GREEN_LOW 0xD0
#define TCS3414_REG_GREEN_HIGH 0xD1
#define TCS3414_REG_RED_LOW 0xD2
#define TCS3414_REG_RED_HIGH 0xD3
#define TCS3414_REG_BLUE_LOW 0xD4
#define TCS3414_REG_BLUE_HIGH 0xD5
#define TCS3414_REG_CLEAR_LOW 0xD6
#define TCS3414_REG_CLEAR_HIGH 0xD7
#define TCS3414_CTL_DAT_INIITIATE 0x03
#define TCS3414_CLR_INT 0xE0

//Timing Register
#define TCS3414_SYNC_EDGE 0x40
#define TCS3414_INTEG_MODE_FREE 0x00
#define TCS3414_INTEG_MODE_MANUAL 0x10
#define TCS3414_INTEG_MODE_SYN_SINGLE 0x20
#define TCS3414_INTEG_MODE_SYN_MULTI 0x30
 
#define TCS3414_INTEGRATION_TIME_12ms 0x00
#define TCS3414_INTEGRATION_TIME_100ms 0x01
#define TCS3414_INTEGRATION_TIME_400ms 0x02 

#define TCS3414_INTEG_PARAM_PULSE_COUNT1 0x00
#define TCS3414_INTEG_PARAM_PULSE_COUNT2 0x01
#define TCS3414_INTEG_PARAM_PULSE_COUNT4 0x02
#define TCS3414_INTEG_PARAM_PULSE_COUNT8 0x03

//Interrupt Control Register 
#define TCS3414_INTR_STOP 40
#define TCS3414_INTR_DISABLE 0x00
#define TCS3414_INTR_LEVEL 0x10
#define TCS3414_INTR_PERSIST_EVERY 0x00
#define TCS3414_INTR_PERSIST_SINGLE 0x01

//Interrupt Souce Register
#define TCS3414_INT_SOURCE_GREEN 0x00
#define TCS3414_INT_SOURCE_RED 0x01
#define TCS3414_INT_SOURCE_BLUE 0x10
#define TCS3414_INT_SOURCE_CLEAR 0x03

//Gain Register
#define TCS3414_GAIN_1 0x00
#define TCS3414_GAIN_4 0x10
#define TCS3414_GAIN_16 0x20
#define TCS3414_GANI_64 0x30
#define TCS3414_PRESCALER_1 0x00
#define TCS3414_PRESCALER_2 0x01
#define TCS3414_PRESCALER_4 0x02
#define TCS3414_PRESCALER_8 0x03
#define TCS3414_PRESCALER_16 0x04
#define TCS3414_PRESCALER_32 0x05
#define TCS3414_PRESCALER_64 0x06

typedef struct
{
    uint32_t R;
    uint32_t G;
    uint32_t B;
    uint32_t W;
} Color; 

Color LAST_TCS3414_COLOR;


bool TCS3414_Init(void);
bool TCS3414_SetTimeing(uint8_t timeing, uint8_t gain);
bool TCS3414_SetInterrupt(uint8_t interruptSource, uint8_t interruptControl);
bool TCS3414_Read(void);

#endif
