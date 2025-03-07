/*
 * ICM45686_HAL.h
 *
 *  Created on: Dec 17, 2024
 *      Author: aoi25
 */

#ifndef INC_ICM45686_HAL_H_
#define INC_ICM45686_HAL_H_

#include <cstdint>
#include "spi.h"

class ICM45686_HAL {

	public:

		enum class REGISTER: uint8_t{

			ACCEL_DATA_X1_UI = 0x00,
			PWR_MGMT0        = 0x10,
			ACCEL_CONFIG     = 0x1B,
			GYRO_CONFIG 	 = 0x1C,
			WHO_AM_I   		 = 0x72
		};

		ICM45686_HAL(SPI_HandleTypeDef* SpiPin, GPIO_TypeDef* CsPinType, uint16_t CsPinNum);

		void Write(ICM45686_HAL::REGISTER, uint8_t* Command, uint8_t Len);
		void Read(ICM45686_HAL::REGISTER, uint8_t* Receive_buffer, uint8_t Len);

	private:

		SPI_HandleTypeDef* SpiPin;
		GPIO_TypeDef* CsPinType;
		uint16_t CsPinNum;
};

#endif /* INC_ICM45686_HAL_H_ */
