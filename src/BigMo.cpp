/** @file BigMo.cpp
 *  This file contains a class which actuates the larger drum motor to strike.
 * 
 *  @author  Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include "BigMo.h"
#include <PrintStream.h>
#include <iostream>

/** @brief   Constructor function.
 *  @details This task initializes the pinNumber variable to the appropriate pin value.
 */
BigMotorStrike::BigMotorStrike(uint8_t p1)
{
  pinNumber = p1;
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
