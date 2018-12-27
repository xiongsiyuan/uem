/*------------------------------
program name:  x.h
perfect date：2018.3.22
mcu:stm8s003f3
-------------------------------*/ 
#ifndef _X_H_
#define _X_H_

		typedef union BYTEBITSDEF{
			unsigned char Byte;
			struct{
				unsigned char bit0:1;
				unsigned char bit1:1;
				unsigned char bit2:1;
				unsigned char bit3:1;
				unsigned char bit4:1;
				unsigned char bit5:1;
				unsigned char bit6:1;
				unsigned char bit7:1;
			} Bits;
		
} Bytebits;

#define LED_ON 0
#define LED_OFF 1
#define ENABLE 1
#define DISABLE 0

#define led1 pc_odr_3//operating 
#define led2 pd_odr_4//charge status indicator

#define led_op 		led1
#define led_chrg 	led2

#define dce pc_odr_6//dc. output switch
#define shdn pc_odr_5//232 shut down
#define cc pa_idr_2//solar panel connection signal
#define chrg pd_idr_2//charge status check
#define down pd_idr_3//charge status check

#define ONE_SECOND_COUNT 128//1s
#define ONE_SECOND_COUNT_MASK ONE_SECOND_COUNT-1

#define LED_FLICKER_COUNT	128
#define LED_FLICKER_COUNT_MASK 	LED_FLICKER_COUNT-1
#define LED_FLICKER_COUNT_END	42

#define CAP_READ_TIME (128 << 5)//1s*(2^5)=32s
#define CAP_READ_TIME_MASK CAP_READ_TIME-1
#define CAPF_READ_TIME (128 << 2)//1s*(2^2)=4s
#define CAPF_READ_TIME_MASK CAPF_READ_TIME-1
//1=1s
#define TIME_SD 5//sleep delay time

#define RCF_COUNT 10//read cw2015 fail count

#define VB_LOW 0x266c//undervoltage thershold value 3000mv
#define VB_LOW_R 0x2858//undervoltage thershold released value 3150mv


/*---------------wwdg value
WWDG计数器的计数周期=12288/4M = 3ms
counter_value-WINDOW_VALU = 7f-60 = 1f = 31
counter_value刷新周期 = 31*3ms = 93ms
---------------------------*/
#define WINDOW_VALUE 0x50
#define COUNTER_INIT_VALUE 0x7f

void clrwdt(void);
void delay_t(unsigned int);


#endif