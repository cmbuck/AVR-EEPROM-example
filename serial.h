/*
 * serial.h
 *
 *  Created on: Jul 23, 2013
 *      Author: Chris
 */

#ifndef SERIAL_H_
#define SERIAL_H_

void initializeSerial();
unsigned char serialReadByte();
void serialWriteByte(unsigned char byteToSend);
void serialWriteString(unsigned char string[]);

#endif /* SERIAL_H_ */
