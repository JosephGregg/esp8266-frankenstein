objects-y+=main.o stdio.o helpers.o
objects-y+=microrl.o
objects-y+=console.o
objects-y+=hostname.o
objects-y+=env.o
objects-y+=strbuf.o
objects-y+=tcpbuf.o

objects-y+=telnet.o

objects-y+=cmd_common.o cmd_env.o uart.o

objects-$(CONFIG_CMD_IW)+=cmd_iw.o
objects-$(CONFIG_CMD_UART)+=cmd_uart.o
objects-$(CONFIG_CMD_IF)+=cmd_ifconfig.o
objects-$(CONFIG_CMD_GPIO)+=cmd_gpio.o
objects-$(CONFIG_CMD_FLASH)+=cmd_flash.o
objects-$(CONFIG_CMD_LISTEN)+=cmd_listen.o
objects-$(CONFIG_CMD_SEND)+=cmd_send.o
objects-$(CONFIG_CMD_DS18B20)+=cmd_ds18b20.o
objects-$(CONFIG_CMD_TFTP)+=cmd_tftp.o tftp.o
objects-$(CONFIG_CMD_AT)+=cmd_at.o
objects-$(CONFIG_CMD_ADC)+=cmd_adc.o
objects-$(CONFIG_ENABLE_PASSTHROUGH)+=cmd_passthrough.o

objects-$(CONFIG_CMD_I2C)+=cmd_i2c.o pin_map.o i2c_master.o 
objects-$(CONFIG_CMD_I2C_BMP180)+=i2c_bmp180.o
objects-$(CONFIG_CMD_I2C_INA219)+=i2c_ina219.o
objects-$(CONFIG_CMD_I2C_SHT21)+=i2c_sht21.o
objects-$(CONFIG_CMD_I2C_BH1750)+=i2c_bh1750.o
objects-$(CONFIG_CMD_I2C_PCF8591)+=i2c_pcf8591.o
objects-$(CONFIG_CMD_I2C_HMC58831)+=i2c_hmc5883l.o
objects-$(CONFIG_CMD_I2C_TCS3414CS)+=i2c_tcs3414cs.o


subdirs-y+=netapps/

subdirs-y+=lwip
