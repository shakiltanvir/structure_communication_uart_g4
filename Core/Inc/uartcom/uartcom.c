/*
 * uartcom.c
 *
 *  Created on: Mar 27, 2024
 *      Author: shakil
 */

#include "uartcom/uartcom.h"

// Define buffer size for transmit and receive buffers
uint8_t txBuff[BUFF_SIZE];
uint8_t rxBuff[BUFF_SIZE];



// Define UART handle and data structures
UART_HandleTypeDef huart1;



myData txData, rxData;



// Function prototypes
uint32_t calculateChecksum(uint32_t num);
//void sendData(uint32_t error);
void sendData(myData *data);
void uartcomInit(void);



// Callback function for UART reception event
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	//data received
    // Convert byte array to structure
    memcpy(&rxData, rxBuff, sizeof(rxData));
    // Verify checksum
    if (rxData.checkSum != calculateChecksum(rxData.err)) {
        // If checksum mismatch detected, handle error
        // For example, setting error values
		memset(&rxData, '0', sizeof(rxData));
    }


    // Populate data structure with error value
    txData.perchenterror = -56.6;
    txData.number = 50650;
    txData.onebyte = 0x3F;
	txData.err = 50; // Example value
    txData.checkSum = calculateChecksum(txData.err);


    sendData(&txData);

    // Start listening for next incoming data
	HAL_UARTEx_ReceiveToIdle_IT(&huart1, rxBuff, BUFF_SIZE);
}



// Function to send data over UART
void sendData(myData *data){

    // Convert structure to byte array
    // Convert structure to byte array
    memcpy(txBuff, data, sizeof(txData));

    // Transmit data
    HAL_UART_Transmit_IT(&huart1, txBuff, sizeof(txBuff));

    /*****************Send Data Information*******************/
}


// Function to convert a uint32_t number to its two's complement representation
uint32_t calculateChecksum(uint32_t num) {
    // Flip all the bits
    num = ~num;
    // Add 1 to the least significant bit
    num += 1;
    return num;
}


// Initialization function for UART communication
void uartcomInit(void){
	// Start listening for incoming data
	  HAL_UARTEx_ReceiveToIdle_IT(&huart1, rxBuff, BUFF_SIZE);
	// Transmit initial data (if needed)
	  HAL_UART_Transmit_IT(&huart1, txBuff, sizeof(txBuff));
}
