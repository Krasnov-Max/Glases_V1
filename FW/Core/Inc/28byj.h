#include "stm32l0xx_ll_system.h"
#include "stm32l0xx_ll_cortex.h"
#include "stm32l0xx_ll_utils.h"
#include "stm32l0xx_ll_gpio.h"
#include "main.h"

#define BLUE      M1_Pin
#define ORANGE    M2_Pin
#define YELLOW    M3_Pin
#define PINK      M4_Pin

#define HIGH      1
#define LOW       0



void digitalWrite(uint16_t PIN, uint8_t Level)
{
if (Level) 
  {
    LL_GPIO_SetOutputPin(Motor_Port, PIN);
  } else
      {
        LL_GPIO_ResetOutputPin(Motor_Port, PIN);
      }
}

const int stepDelay = 3;

void Step( int steps)
{
  int16_t i;
  int16_t tmp;
  uint8_t revers = false;
  if (steps <0) 
  {
    tmp = steps*-1;
    revers = true;
  } else {tmp = steps;};
  
  if (revers)
  {
    for (i=0; i<tmp; i++)
    {
      digitalWrite(ORANGE, HIGH);
      digitalWrite(YELLOW, LOW);
      digitalWrite(PINK, LOW);
      digitalWrite(BLUE, LOW);
      LL_mDelay(stepDelay);
      digitalWrite(ORANGE, LOW);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(PINK, LOW);
      digitalWrite(BLUE, LOW);
      LL_mDelay(stepDelay);
      digitalWrite(ORANGE, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(PINK, HIGH);
      digitalWrite(BLUE, LOW);
      LL_mDelay(stepDelay);
      digitalWrite(ORANGE, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(PINK, LOW);
      digitalWrite(BLUE, HIGH);
      LL_mDelay(stepDelay);
    }
  } else
    {
      for (i=0; i<tmp; i++)
        {
          digitalWrite(ORANGE, LOW);
          digitalWrite(YELLOW, LOW);
          digitalWrite(PINK, LOW);
          digitalWrite(BLUE, HIGH);
          LL_mDelay(stepDelay);
          digitalWrite(ORANGE, LOW);
          digitalWrite(YELLOW, LOW);
          digitalWrite(PINK, HIGH);
          digitalWrite(BLUE, LOW);
          LL_mDelay(stepDelay);
          digitalWrite(ORANGE, LOW);
          digitalWrite(YELLOW, HIGH);
          digitalWrite(PINK, LOW);
          digitalWrite(BLUE, LOW);
          LL_mDelay(stepDelay);
          digitalWrite(ORANGE, HIGH);
          digitalWrite(YELLOW, LOW);
          digitalWrite(PINK, LOW);
          digitalWrite(BLUE, LOW);
          LL_mDelay(stepDelay);
        }  
    }
    digitalWrite(BLUE, LOW);
    digitalWrite(ORANGE, LOW);
    digitalWrite(PINK, LOW);
    digitalWrite(YELLOW, LOW);
}
