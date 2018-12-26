/*------------------------------
program name:  uart1.h
perfect date£º2018.1.11
mcu:stm8s003f3
communication protocol:v1.4
-------------------------------*/ 
#ifndef _UART1_H_
#define _UART1_H_

/*-----------------received data 6 bytes
pattern =head+lentgh+command+checksum
				=0xaa,0x03,0x01,data1,data2,checksum
-------------------------------*/
unsigned char rx_data[6] = {0};
unsigned char rx_buf[6] = {0};
/*-----------------send data 7 bytes
pattern =head+lentgh+command+data+checksum
				=0xaa,0x04,0x02,data1,data2,data3,checksum
-------------------------------*/
unsigned char tx_data[7] = {0xaa,0x04,0x02};

void uart1_init(void);
unsigned char uart1_sendByte(unsigned char);

#endif