/*
 * App.c
 *
 *  Created on: Oct 9, 2022
 *      Author: abdoa
 */

#include "std_types.h"
#include "Timer0.h"
#include "ADC.h"
#include "DcMotor.h"
#include "LCD.h"
#include "lm35_sensor.h"

int main(){
	ADC_ConfigType Config_var={internal_volt,FCPU_8};

	PWM_Timer0_init();
	ADC_init(&Config_var);
	LCD_init();
	DcMotor_Init();

	char *state,on[]={"ON "},off[]={"OFF"};
	char temp ;
	while(1){

		LCD_displayStringRowColumn(0, 3, "FAN is ");
		LCD_displayStringRowColumn(1, 3, "Temp = ");
		temp =LM35_getTemperature();

		if(temp<30){
			DcMotor_Rotate(Stop, 0);
			state=off;
			LCD_moveCursor(0, 11);
			LCD_displayString(state);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			if(temp<10)LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
			LCD_displayString("C");


		}

		else if(temp>=30 && temp<60){
			DcMotor_Rotate(Clockwise, 25);
			state=on;
			LCD_moveCursor(0, 11);
			LCD_displayString(state);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			LCD_displayString("C");
		}

		else if(temp>=60 && temp<90){
			DcMotor_Rotate(Clockwise, 50);
			state=on;
			LCD_moveCursor(0, 11);
			LCD_displayString(state);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			LCD_displayString("C");
		}
		else if(temp>=90 &&  temp<120){
			DcMotor_Rotate(Clockwise, 75);
			state=on;
			LCD_moveCursor(0, 11);
			LCD_displayString(state);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			if(temp<100)LCD_displayCharacter(' ');
			LCD_displayString("C");
		}
		else{
			DcMotor_Rotate(Clockwise, 100);
			state=on;
			LCD_moveCursor(0, 11);
			LCD_displayString(state);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayString("C");

		}



	}
}
