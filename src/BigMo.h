/** @file BigMo.h
 *  This file contains a class which actuates the larger drum motor to strike.
 * 
 *  @author  Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>

/** @brief   Class which implements a motor driver object for a power transistor
 * @details  Initalizes power transistor pins and contains the functionality to 
 *           command motor strikes. 
 */
class BigMotorStrike
{
  protected:
    // Holds microcontroller logic pin for the power transistor
    uint8_t pinNumber;
    
  public:
    // Class object constructor
    BigMotorStrike(uint8_t p1);
    // Commands motor to strike
    void big_motor_strike(void);
};
