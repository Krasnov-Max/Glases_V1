#ifndef TELESCOPECOVER_H_
#define TELESCOPECOVER_H_

#include "main.h"
#include "28byj.h"

//const int LimiterPin = 8;
//const int LimiterTimer = 280;

//bool limiterError = false;

volatile uint8_t coverClosed = false;
volatile int32_t Steps;

uint8_t isCoverCloseLimit() 
{
    return LL_GPIO_IsInputPinSet(LIMIT_GPIO_Port, LIMIT_Pin);
}

void openCover() 
{
  if (coverClosed == true) 
    {
      if (!LL_GPIO_IsInputPinSet(DIR_GPIO_Port, DIR_Pin)) {Step(Steps*-1);} else {Step(Steps);}
    }
	if(!isCoverCloseLimit())
	  {
      coverClosed = false;
  	}
	return;
}

void closeCover() 
{
	if(coverClosed == false) {
		while (!isCoverCloseLimit())
      {
        if (!LL_GPIO_IsInputPinSet(DIR_GPIO_Port, DIR_Pin)) {Step(Steps);} else {Step(Steps*-1);}
      }
  coverClosed = true;
	}
}

void initCover()
{
  uint8_t i;
  if (!LL_GPIO_IsInputPinSet(DIR_GPIO_Port, DIR_Pin)) {Step(-180);} else {Step(180);}
	LL_mDelay(5000);
  while (!isCoverCloseLimit())
  {
    Steps++;
    if (!LL_GPIO_IsInputPinSet(DIR_GPIO_Port, DIR_Pin)) {Step(1);} else {Step(-1);}
  }
  coverClosed = true;
}


#endif /* TELESCOPECOVER_H_ */
