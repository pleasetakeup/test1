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
   @brief Constructor  当触摸采用XPT2046芯片时，可以调用此构造函数
   @param cs  SPI片选信号
   @param rst  复位信号
   @param irq  中断信号
*/
DFRobot_Touch_GTXXXX touch;

/**
   @brief Constructor  当屏采用硬件SPI通信，驱动IC是st7789，屏幕分辨率是240x320时，可以调用此构造函数
   @param dc  SPI通信的命令/数据线引脚
   @param cs  SPI通信的片选引脚
   @param rst  屏的复位引脚
*/
DFRobot_ILI9488_320x480_HW_SPI screen(TFT_DC, TFT_CS, TFT_RST);
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


void drawT(uint8_t dir , uint8_t pointnum) {
  if (dir == 0 && pointnum == 1) {
    screen.fillTriangle(screen.width() / 2, screen.height() / 20, screen.width() / 2 - 15, screen.height() / 20 + 24, screen.width() / 2 + 15, screen.height() / 20 + 24, 0xf800);
    screen.fillRect(screen.width() / 2 - 8, screen.height() / 20 + 24, 16, 70, 0xf800);
    delay(500);
    screen.fillTriangle(screen.width() / 2, screen.height() / 20, screen.width() / 2 - 15, screen.height() / 20 + 24, screen.width() / 2 + 15, screen.height() / 20 + 24, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8, screen.height() / 20 + 24, 16, 70, ui.bgColor);
  }
  else if (dir == 1 && pointnum == 1) {
    screen.fillTriangle(screen.width() - 20, screen.height() / 2, screen.width() - 50, screen.height() / 2 - 15, screen.width() - 50, screen.height() / 2 + 15, 0xf800);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8, 70, 16, 0xf800);
    delay(500);
    screen.fillTriangle(screen.width() - 20, screen.height() / 2, screen.width() - 50, screen.height() / 2 - 15, screen.width() - 50, screen.height() / 2 + 15, ui.bgColor);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8, 70, 16, ui.bgColor);

  }
  else if (dir == 2 && pointnum == 1) {
    screen.fillTriangle(screen.width() / 2, screen.height() - 50, screen.width() / 2 - 15, screen.height() - 50 - 30, screen.width() / 2 + 15, screen.height() - 50 - 30, 0xf800);
    screen.fillRect(screen.width() / 2 - 8, screen.height() - 50 - 30 - 70, 16, 70, 0xf800);
    delay(500);
    screen.fillTriangle(screen.width() / 2, screen.height() - 50, screen.width() / 2 - 15, screen.height() - 50 - 30, screen.width() / 2 + 15, screen.height() - 50 - 30, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8, screen.height() - 50 - 30 - 70, 16, 70, ui.bgColor);
  }
  else if (dir == 3 && pointnum == 1) {
    screen.fillTriangle(20, screen.height() / 2, 20 + 30, screen.height() / 2 - 15, 20 + 30, screen.height() / 2 + 15, 0xf800);
    screen.fillRect(20 + 30, screen.height() / 2 - 8, 70, 16, 0xf800);
    delay(500);
    screen.fillTriangle(20, screen.height() / 2, 20 + 30, screen.height() / 2 - 15, 20 + 30, screen.height() / 2 + 15, ui.bgColor);
    screen.fillRect(20 + 30, screen.height() / 2 - 8, 70, 16, ui.bgColor);
  }
  else if (dir == 0 && pointnum == 2) {
    screen.fillTriangle(screen.width() / 2 - 15, screen.height() / 20, screen.width() / 2 - 15 - 15, screen.height() / 20 + 24, screen.width() / 2 + 15 - 15, screen.height() / 20 + 24, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() / 2 - 8 - 15, screen.height() / 20 + 24, 16, 70, COLOR_RGB565_GREEN);

    screen.fillTriangle(screen.width() / 2 + 15, screen.height() / 20, screen.width() / 2 - 15 + 15, screen.height() / 20 + 24, screen.width() / 2 + 15 + 15, screen.height() / 20 + 24, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() / 2 - 8 + 15, screen.height() / 20 + 24, 16, 70, COLOR_RGB565_GREEN);
    delay(500);
    screen.fillTriangle(screen.width() / 2 - 15, screen.height() / 20, screen.width() / 2 - 15 - 15, screen.height() / 20 + 24, screen.width() / 2 + 15 - 15, screen.height() / 20 + 24, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8 - 15, screen.height() / 20 + 24, 16, 70, ui.bgColor);

    screen.fillTriangle(screen.width() / 2 + 15, screen.height() / 20, screen.width() / 2 - 15 + 15, screen.height() / 20 + 24, screen.width() / 2 + 15 + 15, screen.height() / 20 + 24, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8 + 15, screen.height() / 20 + 24, 16, 70, ui.bgColor);

  }
  else if (dir == 1 && pointnum == 2) {
    screen.fillTriangle(screen.width() - 20, screen.height() / 2 - 15, screen.width() - 50, screen.height() / 2 - 15 - 15, screen.width() - 50, screen.height() / 2 + 15 - 15, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8 - 15, 70, 16, COLOR_RGB565_GREEN);
    screen.fillTriangle(screen.width() - 20, screen.height() / 2 + 15, screen.width() - 50, screen.height() / 2 - 15 + 15, screen.width() - 50, screen.height() / 2 + 15 + 15, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8 + 15, 70, 16, COLOR_RGB565_GREEN);
    delay(500);
    screen.fillTriangle(screen.width() - 20, screen.height() / 2 - 15, screen.width() - 50, screen.height() / 2 - 15 - 15, screen.width() - 50, screen.height() / 2 + 15 - 15,  ui.bgColor);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8 - 15, 70, 16,  ui.bgColor);
    screen.fillTriangle(screen.width() - 20, screen.height() / 2 + 15, screen.width() - 50, screen.height() / 2 - 15 + 15, screen.width() - 50, screen.height() / 2 + 15 + 15,  ui.bgColor);
    screen.fillRect(screen.width() - 50 - 70, screen.height() / 2 - 8 + 15, 70, 16,  ui.bgColor);
  }
  else if (dir == 2 && pointnum == 2) {
    screen.fillTriangle(screen.width() / 2 - 15, screen.height() - 50, screen.width() / 2 - 15 - 15, screen.height() - 50 - 30, screen.width() / 2 + 15 - 15, screen.height() - 50 - 30, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() / 2 - 8 - 15, screen.height() - 50 - 30 - 70, 16, 70, COLOR_RGB565_GREEN);
    screen.fillTriangle(screen.width() / 2 + 15, screen.height() - 50, screen.width() / 2 - 15 + 15, screen.height() - 50 - 30, screen.width() / 2 + 15 + 15, screen.height() - 50 - 30, COLOR_RGB565_GREEN);
    screen.fillRect(screen.width() / 2 - 8 + 15, screen.height() - 50 - 30 - 70, 16, 70, COLOR_RGB565_GREEN);
    delay(500);
    screen.fillTriangle(screen.width() / 2 - 15, screen.height() - 50, screen.width() / 2 - 15 - 15, screen.height() - 50 - 30, screen.width() / 2 + 15 - 15, screen.height() - 50 - 30, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8 - 15, screen.height() - 50 - 30 - 70, 16, 70, ui.bgColor);
    screen.fillTriangle(screen.width() / 2 + 15, screen.height() - 50, screen.width() / 2 - 15 + 15, screen.height() - 50 - 30, screen.width() / 2 + 15 + 15, screen.height() - 50 - 30, ui.bgColor);
    screen.fillRect(screen.width() / 2 - 8 + 15, screen.height() - 50 - 30 - 70, 16, 70, ui.bgColor);
  }
  else if (dir == 3 && pointnum == 2) {
    screen.fillTriangle(20, screen.height() / 2 - 15, 20 + 30, screen.height() / 2 - 15 - 15, 20 + 30, screen.height() / 2 + 15 - 15, COLOR_RGB565_GREEN);
    screen.fillRect(20 + 30, screen.height() / 2 - 8 - 15, 70, 16, COLOR_RGB565_GREEN);
    screen.fillTriangle(20, screen.height() / 2 + 15, 20 + 30, screen.height() / 2 - 15 + 15, 20 + 30, screen.height() / 2 + 15 + 15, COLOR_RGB565_GREEN);
    screen.fillRect(20 + 30, screen.height() / 2 - 8 + 15, 70, 16, COLOR_RGB565_GREEN);
    delay(500);
    screen.fillTriangle(20, screen.height() / 2 - 15, 20 + 30, screen.height() / 2 - 15 - 15, 20 + 30, screen.height() / 2 + 15 - 15, ui.bgColor);
    screen.fillRect(20 + 30, screen.height() / 2 - 8 - 15, 70, 16, ui.bgColor);
    screen.fillTriangle(20, screen.height() / 2 + 15, 20 + 30, screen.height() / 2 - 15 + 15, 20 + 30, screen.height() / 2 + 15 + 15, ui.bgColor);
    screen.fillRect(20 + 30, screen.height() / 2 - 8 + 15, 70, 16, ui.bgColor);
  }
  else if (dir == 10 && pointnum == 0) {
    screen.drawCircleHelper(screen.width() / 2, screen.height() / 2, 100, 10, COLOR_RGB565_BLUE);
    screen.fillTriangle(screen.width() / 2 - 100, screen.height() / 2 - 24, screen.width() / 2 - 100 - 14, screen.height() / 2, screen.width() / 2 - 100 + 14, screen.height() / 2, COLOR_RGB565_BLUE);
    screen.fillTriangle(screen.width() / 2 + 100, screen.height() / 2 + 24, screen.width() / 2 + 100 - 14, screen.height() / 2, screen.width() / 2 + 100 + 14, screen.height() / 2, COLOR_RGB565_BLUE);
    delay(500);
    screen.drawCircleHelper(screen.width() / 2, screen.height() / 2, 100, 10, ui.bgColor);
    screen.fillTriangle(screen.width() / 2 - 100, screen.height() / 2 - 24, screen.width() / 2 - 100 - 14, screen.height() / 2, screen.width() / 2 - 100 + 14, screen.height() / 2,  ui.bgColor);
    screen.fillTriangle(screen.width() / 2 + 100, screen.height() / 2 + 24, screen.width() / 2 + 100 - 14, screen.height() / 2, screen.width() / 2 + 100 + 14, screen.height() / 2,  ui.bgColor);

  }
  else if (dir == 10 && pointnum == 1) {
    screen.drawCircleHelper(screen.width() / 2, screen.height() / 2, 100, 5, COLOR_RGB565_BLUE);
    screen.fillTriangle(screen.width() / 2 - 100, screen.height() / 2 + 24, screen.width() / 2 - 100 - 14, screen.height() / 2, screen.width() / 2 - 100 + 14, screen.height() / 2, COLOR_RGB565_BLUE);
    screen.fillTriangle(screen.width() / 2 + 100, screen.height() / 2 - 24, screen.width() / 2 + 100 - 14, screen.height() / 2, screen.width() / 2 + 100 + 14, screen.height() / 2, COLOR_RGB565_BLUE);
    delay(500);
    screen.drawCircleHelper(screen.width() / 2, screen.height() / 2, 100, 5, ui.bgColor);
    screen.fillTriangle(screen.width() / 2 - 100, screen.height() / 2 + 24, screen.width() / 2 - 100 - 14, screen.height() / 2, screen.width() / 2 - 100 + 14, screen.height() / 2, ui.bgColor);
    screen.fillTriangle(screen.width() / 2 + 100, screen.height() / 2 - 24, screen.width() / 2 + 100 - 14, screen.height() / 2, screen.width() / 2 + 100 + 14, screen.height() / 2, ui.bgColor);

  }
}
void   refresh() {
  DFRobot_UI:: eGesture_t gesture = ui.getGestures();
  /* if (gesture != ui.NONE) {
     Serial.println(gesture);
    }
  */
  switch (gesture) {

    case ui.DUPGLIDE : {
        drawT(0, 2);
      } break;
    case ui.DRIGHTGLIDE : {
        drawT(1, 2);
      } break;
    case ui.DDOWNGLIDE : {
        drawT(2, 2);
      } break;
    case ui.DLEFTGLIDE : {
        drawT(3, 2);
      } break;
    case ui.SUPGLIDE : {
        drawT(0, 1);
      } break;
    case ui.SRIGHTGLIDE : {
        drawT(1, 1);
      } break;
    case ui.SDOWNGLIDE : {
        drawT(2, 1);
      } break;
    case ui.SLEFTGLIDE : {
        drawT(3, 1);
      } break;
    case ui.DWROTATE : {
        drawT(10, 0);
      } break;
    case ui.DCWROTATE : {
        drawT(10, 1);
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

}


void loop()
{

  refresh();
}