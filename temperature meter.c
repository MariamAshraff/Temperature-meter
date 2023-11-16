/*
 * temperature meter.c
 *
 * Created: 11/13/2023 2:44:46 AM
 *  Author: VTE
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include "LED.h"
#include "BUZZER.h"
char read_val;
unsigned short temperatue,volt;
int main(void)
{
	LCD_vInit();
	ADC_vinit();
	LED_vInit('C',0);
	BUZZER_vInit('C',1);
	LCD_vSend_string("temp=");
	while(1)
	{
		volt=ADC_Read()*2.5;
		temperatue=(ADC_Read()*0.25);
		if (volt>=1000)
		{
			LED_vTurnOff('C',0);
			BUZZER_vTurnOff('C',1);
			temperatue=(volt-1000)/10;
			
			if(temperatue<10)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char(temperatue+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_string("C  ");
				LCD_movecursor(2,3);
				LCD_vSend_string("    Cold   ");
			}
			else if( temperatue<100)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char((temperatue/10)+48);
				LCD_vSend_char((temperatue%10)+48);
				LCD_vSend_char(0XDF);
				LCD_vSend_string("C  ");
				if (temperatue<=20)
				{
					LCD_movecursor(2,3);
					LCD_vSend_string("    Mild    ");
				}
				else if (temperatue<=30)
				{
					LCD_movecursor(2,3);
					LCD_vSend_string("Mildly Warm");
				}
				else if (temperatue<55)
				{
				LCD_movecursor(2,3);
				LCD_vSend_string("    Hot    ");
				}
				
				else
				{
					LED_vToggle('C',0);
					BUZZER_vTurnOn('C',1);
					LCD_movecursor(2,3);
					LCD_vSend_string("   fire    ");
				}					
			
			}
			else 
			{
				LCD_movecursor(1,6);
				LCD_vSend_char(temperatue/100+48);
				LCD_vSend_char((temperatue/10)%10+48);
				LCD_vSend_char(temperatue%10+48);
				LCD_vSend_char(0XDF);
				LCD_vSend_char('C');
				LED_vTurnOn('C',0);
				BUZZER_vTurnOn('C',1);
				LCD_movecursor(2,3);
				LCD_vSend_string("    fire   ");
			}
		}
		else
		{
			LED_vTurnOff('C',0);
			BUZZER_vTurnOff('C',1);
			LCD_movecursor(2,3);
			LCD_vSend_string("  Very Cold  ");
			temperatue=((1000-volt)/10)+1;
			if(temperatue<10)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char('-');
				LCD_vSend_char(temperatue+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_string("C  ");
			}
			else 
			{
				LCD_movecursor(1,6);
				LCD_vSend_char('-');
				LCD_vSend_char((temperatue/10)+48);
				LCD_vSend_char((temperatue%10)+48);
				LCD_vSend_char(0XDF);
				LCD_vSend_string("C  ");
				
			}
		}			
		
	}
}