/*
 *	All the serial related functions
 */
#include <avr/io.h>

#define USART_BAUDRATE 2400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void initializeSerial()
{
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);   // Turn on the transmission and reception circuitry
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes

	UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
}

unsigned char serialReadByte()
{
	unsigned char receivedByte;
	while ((UCSR0A & (1 << RXC0)) == 0) {}; // Do nothing until data have been received and is ready to be read from UDR
	      receivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
	return receivedByte;
}

void serialWriteByte(unsigned char byteToSend)
{
	while ((UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
	      UDR0 = byteToSend; // Echo back the received byte back to the computer
}

/*
 * Writes a string to the UART, each char at a time.
 * inputs: string[]	-	The array of characters to write
 * Note: the string must be null-terminated
 */
void serialWriteString(unsigned char string[])
{
	int i = 0;
	while (string[i])
	{
		serialWriteByte(string[i]);
		i++;
	}
}
