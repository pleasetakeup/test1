/*!
   @file UI_keypad.ino
   @brief 屏幕中央存在几个文字，可以通过两指手势中的放大，缩小，上滑，下滑来控制它
   @n 本示例支持的主板有Arduino Uno, Leonardo,Mega2560, FireBeetle-ESP32, FireBeetle-ESP8266, FireBeetle-M0

   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2019-12-6
   @get from https://www.dfrobot.com
   @url https://github.com/DFRobot/DFRobot_GDL/src/DFRpbot_UI
*/

#include "DFRobot_UI.h"
#include "Arduino.h"
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"
/*M0*/
#if defined ARDUINO_SAM_ZERO
#define TFT_DC  7
#define TFT_CS  5
#define TFT_RST 6
#define TOUCH_CS 2
/*ESP32 and ESP8266*/
#elif defined(ESP32) || defined(ESP8266)
#define TFT_DC  D3
#define TFT_CS  D4
#define TFT_RST D5
#define TOUCH_CS D6
/*AVR系列主板*/
#else
#define TFT_DC  40
#define TFT_CS  41
#define TFT_RST 42
#define TOUCH_CS 5
#endif

/**
   @brief Constructor  当触摸采用gt系列芯片时，可以调用此构造函数
*/
DFRobot_Touch_GTXXXX touch;

/**
   @brief Constructor  当屏采用硬件SPI通信，驱动IC是st7789，屏幕分辨率是240x320时，可以调用此构造函数
   @param dc  SPI通信的命令/数据线引脚
   @param cs  SPI通信的片选引脚
   @param rst  屏的复位引脚
*/
DFRobot_ILI9488_320x480_HW_SPI screen(TFT_DC, TFT_CS, TFT_RST);
//DFRobot_ILI9341_240x320_HW_SPI screen(TFT_DC,TFT_CS,TFT_RST);
//DFRobot_ST7789_240x320_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
/*M0主板下DMA传输*/
//DFRobot_ST7789_240x240_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
//DFRobot_ST7789_240x320_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);

/**
   @brief 构造函数
   @param gdl 屏幕对象
   @param touch 触摸对象
*/
DFRobot_UI ui(&screen, &touch);

uint8_t fontSize = 2;
uint16_t fontColor = COLOR_RGB565_YELLOW;
uint8_t fontLen = 4 * fontSize * 8;
char * font = "DFRC";
uint8_t fontHeight = fontSize * 8;
uint16_t posx =  screen.width() / 2 - fontLen / 2;
uint16_t posy = (screen.height() - fontHeight) / 2;
void refresh() {
  DFRobot_UI:: eGesture_t gesture = ui.getGestures();
  /*if(gesture != ui.NONE){
    Serial.println(gesture);
    }
  */
  switch (gesture) {
    case ui.SHRINK : {
        screen.fillRect(posx, posy, 5 * fontSize * 8, fontSize * 8, ui.bgColor);
        fontSize--;
        if (fontSize <= 1) fontSize = 1;
        //  posx = screen.width()/2-4*fontSize*2;
        // posy = screen.height()/2-fontSize*4;
        ui.drawString(posx, posy,  font, fontColor , ui.bgColor, fontSize, 0);
      }; break;
    case ui.MAGNIFY : {

        screen.fillRect(posx, posy, 5 * fontSize * 8, fontSize * 8, ui.bgColor);
        fontSize++;
        if (fontSize >= 7) fontSize = 7;
        //posx = screen.width()/2-5*fontSize*2;
        // posy = screen.height()/2-fontSize*4;
        ui.drawString(posx, posy, font, fontColor , ui.bgColor, fontSize, 0);
      } break;
    case ui.DUPGLIDE : {
        screen.fillRect(posx, posy, 5 * fontSize * 8, fontSize * 8, ui.bgColor);
        posy -= 10 ;
        ui.drawString(posx, posy, font, fontColor , ui.bgColor, fontSize, 0);
      } break;
    case ui.DDOWNGLIDE : {
        screen.fillRect(posx, posy, 5 * fontSize * 8, fontSize * 8, ui.bgColor);
        posy += 10;
        ui.drawString(posx, posy, font, fontColor , ui.bgColor, fontSize, 0);
      } break;
    case ui.NONE: {
        return;
      }
  }
}

void setup()
{

  Serial.begin(9600);

  ui.begin();
  ui.drawString(screen.width() / 2 - fontLen / 2, (screen.height() - fontHeight) / 2, font, fontColor , ui.bgColor, fontSize, 0);


}


void loop()
{
  refresh();

}