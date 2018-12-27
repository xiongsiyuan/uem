/*------------------------------
program name:  cw_bat_info.h
perfect date��2018.1.8
mcu:bs86d20a-3

function:cw2015 bat. information
-------------------------------*/ 


#ifndef _CW_BAT_INFO_H_
#define _CW_BAT_INFO_H_

#define SIZE_BATINFO 64
//battery curve value of ����18650/2600mah/4s4p 
const unsigned char cw_bat_config_info[SIZE_BATINFO] = {
0x14,0xA6,0x70,0x6C,0x6C,0x67,0x64,0x62,
0x60,0x5C,0x59,0x4E,0x50,0x42,0x2E,0x26,
0x25,0x24,0x27,0x2E,0x41,0x5A,0x6D,0x4C,
0x39,0xD7,0x06,0x66,0x00,0x01,0x05,0x34,
0x61,0x76,0x79,0x7D,0x42,0x1E,0xA4,0x00,
0x27,0x5A,0x52,0x87,0x8F,0x91,0x94,0x52,
0x82,0x8C,0x92,0x96,0x2B,0x59,0x6E,0xCB,
0x2F,0x7D,0x72,0xA5,0xB5,0xC1,0x94,0x99
};

#endif



