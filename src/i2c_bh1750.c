#include "c_types.h"
#include "ets_sys.h"
#include "osapi.h"
#include "console.h"

#include "driver/i2c_master.h"
#include "driver/i2c_bh1750.h"

#ifdef CONFIG_CMD_BH1750_DEBUG
#define dbg(fmt, ...) LOG(LOG_DEBUG, fmt, ##__VA_ARGS__)
#else
#define dbg(fmt, ...)
#endif

static uint8 currentmode = BH1750_ONE_TIME_HIGH_RES_MODE;

bool ICACHE_FLASH_ATTR 
BH1750_Read()
{
	if(!i2c_master_writeRegister(BH1750_ADDRESS, currentmode, 0)){
		return false;
	}

	os_delay_us(BH1750_CONVERSION_TIME*1000);

	LAST_BH_LIGHT = (i2c_master_readRegister16(BH1750_ADDRESS, 0) - 256) / 1.2;
	return true;
}


bool ICACHE_FLASH_ATTR 
BH1750_Init(uint8 mode)
{
	if(!i2c_master_writeRegister(BH1750_ADDRESS, mode, 0)){
		return false;
	}

	currentmode = mode;
	return true;
}

static int do_i2c_bh1750(int argc, const char* const* argv)
{
	if(argc == 1 || strcmp(argv[1], "read") == 0){

		if(BH1750_Read()){
			console_printf( argc == 1 ? "%d\n" : "Light: %d lux\n", LAST_BH_LIGHT);
		}else{
			console_printf( "failed read value\n" );
		}
	} else

	if(strcmp(argv[1], "init") == 0){

		console_printf( BH1750_Init(BH1750_ONE_TIME_HIGH_RES_MODE) ? "Ok\n":"Failed\n" );
	} 

	return 0;
}

CONSOLE_CMD(i2c_bh1750, 0, 2, 
		do_i2c_bh1750, NULL, NULL, 
		"I2C light sensor BH1750"
		HELPSTR_NEWLINE "i2c_bh1750 init"
		HELPSTR_NEWLINE "i2c_bh1750 [read]"
);
