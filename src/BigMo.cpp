/** @file BigMo.cpp
 *  This file contains a motor driver class which actuates the larger drum motor to strike.
 * 
 *  @author  Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>

#include <PrintStream.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "BigMo.h"

/** @brief   Constructor function.
 *  @details This task initializes the pinNumber variable to the appropriate pin value.
 *  @param   p1 a uint8_t varaible that holds the arduino pin that provides the logical
 *           signal to the transistor
 */
BigMotorStrike::BigMotorStrike(uint8_t p1)
{
  // Holds the arduino pin that logically controls the transistor
  pinNumber = p1;
  // establish power transistor gate
  pinMode(pinNumber, OUTPUT); //transistor gate
}

/** @brief   Task which strikes the bigger drum.
 *  @details This task actuates the larger motor to strike the kick drum.
 */
void BigMotorStrike::big_motor_strike(void)
{
  digitalWrite(pinNumber, HIGH);
  vTaskDelay(200);
  digitalWrite(pinNumber, LOW);
}
