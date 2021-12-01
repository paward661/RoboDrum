/** @file LilMo.cpp
 *  This file contains a class which actuates the smaller drum motor to strike.
 * 
 *  @author  Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "LilMo.h"

/** @brief   Constructor function.
 *  @details This task initializes the pinNumber variable to the appropriate pin value.
 */
LilMotorStrike::LilMotorStrike(uint8_t Brake, uint8_t Dir, uint8_t PWM)
{
    brake_pin = Brake;
    Dir_pin = Dir;
    PWM_pin = PWM;

  //establish motor direction toggle pins
  pinMode(Dir_pin, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(brake_pin, OUTPUT); //brake (disable) CH A

  digitalWrite(brake_pin, LOW);  //ENABLE CH A
}

/** @brief   Task which strikes the smaller drum.
 *  @details This task actuates the smaller motor to strike the snare drum.
 */
void LilMotorStrike::lil_motor_strike(void)
{

  //start down
  digitalWrite(brake_pin, LOW); //Disengage the Brake for Channel A
  digitalWrite(Dir_pin, LOW);   //Sets direction of CH A
  analogWrite(PWM_pin, 255);   //Moves CH A
  
  //strike time
  vTaskDelay(100);
  
  //go back
  digitalWrite(Dir_pin, HIGH);   //Sets direction of CH A
  analogWrite(PWM_pin, 255);   //Moves CH A
  
  //recoil time
  vTaskDelay(40);    
  
  //stop
  digitalWrite(brake_pin, HIGH); //Engage the Brake for Channel A
}
