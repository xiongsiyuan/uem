/* --------------------------------
program:stm8_i2c_cw2015
revise date:2017.7.20
function: i2c subroutine
 ----------------------------------*/
#include "x.h"
#include "stm8s003f3.h"
#include "cw_bat_config_info.h"
#include "stm8s_i2c.h"

unsigned char temp_data[SIZE_BATINFO] = {0};//read data

unsigned char write_cw(unsigned char reg_addr, unsigned char *pdata, unsigned char data_length)
{
	unsigned char i;
	unsigned char ret;	
	for(i =0; i <= TRY_COUNT; i++)//try TRY_COUNT times if fail
		{	
			ret = write_data(reg_addr, pdata, data_length);
			if(!ret)
				break;
				else if(TRY_COUNT == i)
					return ret;		
		}		
	return 0;
}

unsigned char read_cw(unsigned char reg_addr, unsigned char *pdata, unsigned char data_length)
{
	unsigned char i;
	unsigned char ret;	
	for(i =0; i <= TRY_COUNT; i++)//try TRY_COUNT times if fail
		{	
			ret = read_data(reg_addr, pdata, data_length);
			if(!ret)
				break;
				else if(TRY_COUNT == i)
					return ret;		
		}		
	return 0;
}


//check bat. infomation
unsigned char check_bat_info(void)
{
	unsigned char i;
	unsigned char *wdata,*rdata;
	rdata = temp_data;
	wdata = cw_bat_config_info;
	for(i = 0; i < SIZE_BATINFO; i++)
		{
			if(*rdata != *wdata)
				return 1;
			rdata++;
			wdata++;
		}
	return 0;
}

//cw2015 initialize							
unsigned char cw_init(void)
{	
	unsigned char ret;
	unsigned char reg_val;
					
	//check sleep status
	ret = read_cw(REG_MODE, &reg_val, 1);
	if(ret)
		return ret;		
	//cw2015 wake up	
	if((reg_val & MODE_SLEEP_MASK) == MODE_SLEEP)
		{	
			reg_val = MODE_NORMAL;	
			ret = write_cw(REG_MODE, &reg_val, 1);
			if(ret)
				return ret;	
		}
	//check config updata flag
	ret = read_cw(REG_CONFIG, &reg_val, 1);
	if(ret)
		return ret;			
	if(!(reg_val & CONFIG_UPDATE_FLG))	
		{			
			//write bat. info.
			ret = write_cw(REG_BATINFO, cw_bat_config_info, SIZE_BATINFO);
			if(ret)
				return ret;
		}
		else
			{	
				//read bat. infomation		
				ret = read_cw(REG_BATINFO, temp_data, SIZE_BATINFO);
				if(ret)
					return ret;		
					
				//compare
				ret = check_bat_info();
				if(ret)
					{
						//write bat. info.
						ret = write_cw(REG_BATINFO, cw_bat_config_info, SIZE_BATINFO);
						if(ret)
							return ret;								
					}
							
			}
	//read bat. infomation		
	ret = read_cw(REG_BATINFO, temp_data, SIZE_BATINFO);
	if(ret)
		return ret;		
					
	//compare
	ret = check_bat_info();
	if(ret)
		return ret;	
											
	//set update flag	
	reg_val = 0;
	reg_val |= CONFIG_UPDATE_FLG;				
	ret = write_cw(REG_CONFIG, &reg_val,1);
	if(ret)
		return ret;
									
	//restart cw2015
	reg_val = MODE_RESTART;
	ret = write_cw(REG_MODE, &reg_val, 1);
	if(ret)
		return ret;					
		
	delay_t(30);//delay 100us
	

	//reset(wake up) cw2015	
	reg_val = MODE_NORMAL;
	ret = write_cw(REG_MODE, &reg_val,1);
	if(ret)
		return ret;
								
	return 0;
					
}