# STM32_ICM45686_SPI

HAL_SPIを使ってICM45686と通信できるコードです

SPIMasterモードのみ対応しています

I2C通信で使いたい方はこちら[I2C通信バージョン](https://github.com/aoi-256/STM32_ICM45686_I2C)

## 使い方

- STM32CubeIDEでSPIxとGPIO_Outputを設定する
  
| 設定するピン | ICM45686のピン |
| ---- | ---- | 
| SPIx_SCK | SCLK |
| SPIx_MISO | SDIO / SDI|
| SPIx_MOSI | SDO |
| GPIO_Output | CS|

- 画像のようにSPIxとGPIO_Outputを設定する

### SPIx
![スクリーンショット (523)](https://github.com/user-attachments/assets/18a65c35-e5ac-44ad-bde8-39bff4f3e202)

### GPIO
![スクリーンショット (524)](https://github.com/user-attachments/assets/9b6fa7a5-01f7-4c71-8bcd-4ae6d936491b)

## サンプルコード

起動時に1回だけ実行する部分（設定）とメインループで実行する部分（値の取得）をそれぞれの環境に合わせて書いてください

Config()の設定項目はenumで定義してあるため、STM32CubeIDEを使っている場合は

```icm.Mode::```まで入力すると候補が出てきます

```cpp
#include "ICM45686.h"

ICM45686 icm(&hspi1, GPIOB, GPIO_PIN_6);

int16_t AccelData[3] = {};
int16_t GyroData[3]  = {};

int main(void){

  icm.Connection();
	icm.Accel_Config(icm.Mode::low_noize, icm.Accel_Scale::scale_02g, icm.ODR::rate_6400hz);
	icm.Gyro_Config(icm.Mode::low_noize, icm.Gyro_Scale::scale_0250dps, icm.ODR::rate_6400hz);

  while(1){

    icm.Get_Data(AccelData, GyroData);
  }
}
```
