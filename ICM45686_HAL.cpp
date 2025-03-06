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

	uint8_t REG = uint8_t(REGISTER_ADDR) | 0x00;
	
	//書き込み先のレジスタを指定
	HAL_SPI_Transmit(&hspi1, &REG, 1, 1000);
	//データを書き込み
    	HAL_SPI_Transmit(&hspi1, Command, Len, 1000);
}

void ICM45686_HAL::Read(ICM45686_HAL::REGISTER REGISTER_ADDR, uint8_t* Buffer, uint8_t Len){

	uint8_t REG = uint8_t(REGISTER_ADDR) | 0x80;
	//読み取りたいレジスタを指定
	HAL_SPI_Transmit(ICM20948_SPI, &REG, 1, 1000);
	//データを受信
	HAL_SPI_Receive(ICM20948_SPI, Buffer, Len, 1000);
}

