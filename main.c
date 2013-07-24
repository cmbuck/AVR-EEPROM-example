#include <avr/io.h>
#include <avr/eeprom.h>
#include "serial.h"

int main(void)
{
	initializeSerial();
	char buf[32];

	unsigned char byteOfData = 0x12;
	sprintf(buf, "initialized: %H", byteOfData);
	serialWriteString(buf);

	unsigned char* eepromAddress = 0x00;
	byteOfData = eeprom_read_byte(eepromAddress);

	sprintf(buf, "after read: %H", byteOfData);
	serialWriteString(buf);

}
