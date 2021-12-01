/** @file BigMo.h
 *  This file contains a class which actuates the larger drum motor to strike.
 * 
 *  @author  Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>

class BigMotorStrike
{
  protected:
    uint8_t pinNumber;
    

  public:
    BigMotorStrike(uint8_t p1);
    void big_motor_strike(void);
};
