/*
 * uartcom.h
 *
 *  Created on: Mar 27, 2024
 *      Author: shakil
 */

#ifndef INC_UARTCOM_UARTCOM_H_
#define INC_UARTCOM_UARTCOM_H_


#include "main.h"
#include "string.h"


#define BUFF_SIZE 256

extern UART_HandleTypeDef huart1;



// Define custom data structure for UART communication
typedef struct {
    uint32_t err;      // dont change this
    float perchenterror;// float error
    int number;
    uint8_t onebyte;
    uint32_t checkSum; // Checksum for error code
} myData;

/**
 * @brief Initialize UART communication.
 *
 * This function initializes UART communication by configuring UART settings
 * and preparing buffers for transmission and reception.
 */
void uartcomInit(void);


#endif /* INC_UARTCOM_UARTCOM_H_ */
