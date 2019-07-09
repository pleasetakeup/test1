# pn532
The PN532 is a highly integrated transmission module for contactless communication at 13.56 MHz including microcontroller functionality based on an 80C51 core with 40 Kbytes of ROM and 1 Kbytes of RAM. 
The PN532 combines a modulation and demodulation concept completely integrated for different kinds of contactless communication methods and protocols at 13.56 MHz with an easy-to-use firmware for the different supported modes and the required host controller interfaces. 
This example is for pn532 chip reads and writes CARDS.
## DFRobot_PN532 Library for Arduino
---------------------------------------------------------

Provide an Arduino library to control the nfc module to get data from card and writes data  to card .

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Support](#support)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++	

#include <DFRobot_PN532.h

/*!
 * @brief read a page of data from the target card which  type is mifareclassic(there are 16 bytes of data per page).
 * @param The number of pages that you want to read data.
 * @param A buffer that stores data.
 * @return Status code. 
 */   
	 uint8_t readData(uint8_t *buffer,uint8_t block);

/*!
 * @brief read a data from the  page which you want.
 * @param page: the number of pages you want to read data.
 * @param num: the offset of the data that you want. 
 * @return a data from the card. 
 */  
     int  readData(int page, uint8_t num);
/*!
 * @brief write a data to card which  type is mifareclassic.
 * @param page: the number of pages you want to writes the data.
 * @param num: the offset of the data. 
 * @param data: the data content.
 */  
     void  writeData (int page, uint8_t num ,uint8_t data);
/*!
 * @brief find out if there is a card which  type is mifareclassic. 
 * @return True means find out a card.
 */ 
     bool  scan(void);
/*!
 * @brief find out if there is a specific card which  type is mifareclassic.
 * @param a string of card Numbers.
 * @return True means success.
 */   
     bool  scan(String nfcuid);
/*!
 * @brief get the id of the card .
 * @return  the card's id.
 */  
     String  readUid();
/*!
 * @brief write sixteen data on the card which  type is mifareclassic.
 * @param block: the number of pages you want to write data on.
 * @param data[]: the name of arry name which has sixteen data . 
 */  
     bool  writeData(int block, uint8_t data[]);
/*!
 * @brief read a set of data on the card which  type is Ultralight.
 * @param block: the number of pages you want to read.
 * @param *buffer: A buffer that stores data . 
 * @return error or correct message code
 */
	 uint8_t readUltralight(uint8_t *buffer,uint8_t block);
/*!
 * @brief Write a set of data into the card which  type is Ultralight.
 * @param block: the number of pages you want to write data on.
 * @param *buffer: the name of arry name which has four data . 
 * @return error or correct message code
 */
	 bool  writeUltralight(int block, uint8_t data[]);
/*!
 * @brief Reads a set of data from a card which  type is NTAG.
 * @param block: the number of pages you want to read.
 * @param *buffer:  A buffer that stores data . 
 * @return error or correct message code.
 */
	 uint8_t readNTAG(uint8_t *buffer,uint8_t block);
/*!
 * @brief Write a set of data into the card which  type is NTAG.
 * @param block: the number of pages you want to write data on.
 * @param *buffer: the name of arry name which has four data . 
 * @return error or correct message code
 */
	 bool  writeNTAG(int block, uint8_t data[]);
/*!
 * @brief Read the basic information of the card.
 */
	 struct card getAQTA（）;
	 
```
## Support
TYPE                | read and write   | Can be accurately identified？ | Remarks
------------------- | :--------------: | :----------------------------: |-----
Mifareclassic S50   |      √           |      √                         | 
Mifareclassic S70   |      √           |      √                         |                         
NTAG 213            |      √           |                                |        
NTAG 215            |      √           |                                |    
NTAG 216            |      √           |                                |          
Ultralight          |      √           |                                |           


## Compatibility

MCU                | iic          | uart         | Remarks
------------------ | :----------: | :----------: |-----
ESP32              |      √       |      √       |             
micro:bit          |      √       |              |              
Arduino uno        |      √       |              |           
Arduino mega 2560  |      √       |      √       |

## History

- data 2019-6-10
- version V0.1


## Credits

Written by fengli(1074485750@qq.com), 2017. (Welcome to our [website](https://www.dfrobot.com/))
