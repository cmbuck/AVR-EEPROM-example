#include <stdio.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include "serial.h"

int main(void)
{
	initializeSerial();
	char buf[32];

	char byteOfData = 0x12;
	sprintf(buf, "initialized: %d\r\n", byteOfData);
	serialWriteString(buf);

	unsigned char* eepromAddress = 0x00;
	byteOfData = eeprom_read_byte(eepromAddress);

	sprintf(buf, "after read: %d\r\n", byteOfData);
	serialWriteString(buf);

	byteOfData++;
	eeprom_write_byte(eepromAddress, byteOfData);
	byteOfData = eeprom_read_byte(eepromAddress);

	sprintf(buf, "after write: %d\r\n", byteOfData);
	serialWriteString(buf);

}
