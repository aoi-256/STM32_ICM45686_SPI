/*
 * ICM45686_HAL.cpp
 *
 *  Created on: Dec 17, 2024
 *      Author: aoi25
 */

#include <ICM45686_HAL.h>

ICM45686_HAL::ICM45686_HAL(SPI_HandleTypeDef *SPI_Pin){

	//使用するピンの情報を受け取る
	this->SPI_Pin = SPI_Pin;

}

void ICM45686_HAL::Write(ICM45686_HAL::REGISTER REGISTER_ADDR, uint8_t* Command, uint8_t Len){

	uint8_t REG = uint8_t(REGISTER_ADDR) & 0x7F;
	HAL_SPI_TransmitReceive(&hspi1, &REG, Command, Len, 100);
}

void ICM45686_HAL::Read(ICM45686_HAL::REGISTER REGISTER_ADDR, uint8_t* Command, uint8_t Len){

	uint8_t REG = uint8_t(REGISTER_ADDR) | 0x80;
	HAL_SPI_TransmitReceive(&hspi1, &REG, Command, Len, 100);
}

