
/*
 * ADC.h
 *
 *  Created on: Oct 8, 2022
 *      Author: abdoa
 */


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

typedef enum{
	FCPU_2=1,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Prescaler;

typedef enum{
	AREF,AVCC,internal_volt=3

}ADC_ReferenceVolatge;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
