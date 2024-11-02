/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  * @author			: Tran Ba Thanh - 20213731 - IoT02 K66
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TFT_SCK_Pin GPIO_PIN_5
#define TFT_SCK_GPIO_Port GPIOA
#define TFT_MISO_Pin GPIO_PIN_6
#define TFT_MISO_GPIO_Port GPIOA
#define TFT_MOSI_Pin GPIO_PIN_7
#define TFT_MOSI_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

// Touch function's pins
#define T_IRQ_Pin 			GPIO_PIN_1
#define T_IRQ_GPIO_Port 	GPIOB
#define T_DO_Pin 			GPIO_PIN_2
#define T_DO_GPIO_Port 		GPIOB
#define T_DIN_Pin	 		GPIO_PIN_13
#define T_DIN_GPIO_Port 	GPIOB
#define T_CS_Pin 			GPIO_PIN_12
#define T_CS_GPIO_Port 		GPIOB
#define T_CLK_Pin 			GPIO_PIN_0
#define T_CLK_GPIO_Port 	GPIOB

// TFT screen's pins
#define RESET_Pin 			GPIO_PIN_0
#define RESET_GPIO_Port 	GPIOA
#define DC_Pin	 			GPIO_PIN_1
#define DC_GPIO_Port 		GPIOA
#define CS_Pin 				GPIO_PIN_2
#define CS_GPIO_Port 		GPIOA

// IDK wtf is this
#define READ_X 				0xD0
#define READ_Y 				0x90

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
