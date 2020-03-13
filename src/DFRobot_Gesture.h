#ifndef __DFROBOT_GESTURE_H
#define __DFROBOT_GESTURE_H

#include "Arduino.h"

#define POINT 3

class DFRobot_Gesture{
public:
typedef struct{
    uint16_t pointx[POINT];
	uint16_t pointy[POINT];
	uint8_t id;
	uint8_t pressed;
}sTouchRecord_t;

typedef struct{
	uint16_t x[5];
	uint16_t y[5];
	
}sTouchMessage_t;
typedef enum {
	SCLICK,//0
	DDOUBLECLICK,//1
	DLONGPRESSED,//2
	SLEFTGLIDE,//3
	SRIGHTGLIDE,//4
	SDOWNGLIDE,//5
	SUPGLIDE,//6
    DUPGLIDE,//7
    DDOWNGLIDE,//8
    DLEFTGLIDE,//9
    DRIGHTGLIDE,//10
    SHRINK,//11
    MAGNIFY,	 //12
	DWROTATE,//13
	DCWROTATE,//14
	DCLICK,//15
	TCLICK,//16
	TLEFTGLIDE,//17
	RIGHTGLIDE,//18
	TDOWNGLIDE,//19
	TUPGLIDE,//20
	WCLICK,//21
    PCLICK,//22
    NONE,//23
}eGesture_t;

typedef enum{
	  UPL,
	  DOWNL,
	  LEFTL,
	  RIGHTL,
	  NOCHANGE,
	  UNIDENTIFIABLE,
}eDirection_t;

typedef enum{
	  LETTUP,
	  LEFTDOWN,
	  RIGHTUP,
	  RIGHTDOWN,
	  UP,
	  DOWN,
	  LEFT,
	  RIGHT,
	  CLICK, 
	  UNABLE,
}eDir_t;

eGesture_t gesture(String str);
eGesture_t twoFingers(uint8_t release,uint8_t number);

uint16_t clickCount();
virtual uint8_t stringToPoint(String str)=0;
eGesture_t getGestureOne(uint8_t pointOne);
eGesture_t getGestureTwo(eDir_t pointOne,eDir_t pointTwo);
eGesture_t getGestureThree(uint8_t pointOne,uint8_t pointTwo,uint8_t pointThree);
eGesture_t getGestureFour(uint8_t pointOne,uint8_t pointTwo,uint8_t pointThree,uint8_t pointFour);
eGesture_t getGestureFive(uint8_t pointOne,uint8_t pointTwo,uint8_t pointThree,uint8_t pointFour,uint8_t pointFive);
eDirection_t  directionX(uint16_t x1,uint16_t x2,uint16_t x3);
eDirection_t  directionY(uint16_t y1,uint16_t y2,uint16_t y3);
eDir_t  pointe(int point1);
uint8_t bfDistance();
uint8_t judgeRotate();
uint16_t maxp(uint16_t num1,uint16_t num2,uint16_t num3);
uint16_t minp(uint16_t num1,uint16_t num2,uint16_t num3);
sTouchMessage_t tpDev;
private:
  sTouchRecord_t touchge[5];
  sTouchRecord_t touchgeT[5];
  uint8_t lastPN = 0; 
  uint8_t release = 0;
  uint16_t change;
  int16_t change_x;
  int16_t change_y;
  int distance;
  uint8_t point ;
  eGesture_t lastGesture;
  uint8_t longpressed;
  uint16_t click_oldx,click_oldy;
  long long timer1,timer2;
  long timer3= 0;
  uint8_t click = 0;
  uint16_t distance_click ;
  
};


#endif