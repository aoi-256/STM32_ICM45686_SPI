/* * ICM45686_HAL.cpp
 *
 *  Created on: Dec 17, 2024
 *      Author: aoi25
 */

#include <ICM45686_HAL.h>
#include "gpio.h"

ICM45686_HAL::ICM45686_HAL(SPI_HandleTypeDef *SPI_Pin){

	//使用するピンの情報を受け取る
	this->SPI_Pin = SPI_Pin;

}

void ICM45686_HAL::Write(ICM45686_HAL::REGISTER REGISTER_ADDR, uint8_t* Command, uint8_t Len){

	uint8_t TxBuffer[2] = {};

	for(uint8_t i=0; i<Len; i++){

	TxBuffer[0] = ((uint8_t)REGISTER_ADDR + i) | 0x00;
	TxBuffer[1] = Command[i];

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

    HAL_SPI_Transmit(&hspi1, TxBuffer, 2, 1000);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

	}
}

void ICM45686_HAL::Read(ICM45686_HAL::REGISTER REGISTER_ADDR, uint8_t* Buffer, uint8_t Len){

	uint8_t TxBuffer[2] = {};
	uint8_t RxBuffer[2] = {};

	for(uint8_t i=0; i<Len; i++){

		TxBuffer[0] = (uint8_t(REGISTER_ADDR) + i) | 0x80;
		TxBuffer[1] = 0x00;

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

		HAL_SPI_TransmitReceive(&hspi1, TxBuffer, RxBuffer, 2, 100);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

		Buffer[i] = RxBuffer[1];
	}
}
