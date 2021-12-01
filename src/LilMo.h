/** @file LilMo.h
 *  This file contains a class which actuates the smaller drum motor to strike.
 * 
 *  @author  Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>

class LilMotorStrike
{
  protected:
    uint8_t brake_pin;
    uint8_t Dir_pin;
    uint8_t PWM_pin;

  public:
    LilMotorStrike(uint8_t Brake, uint8_t Dir, uint8_t PWM);
    void lil_motor_strike(void);
};
