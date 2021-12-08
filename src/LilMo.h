/** @file LilMo.h
 *  This file contains a class which actuates the smaller drum motor to strike.
 * 
 *  @author  Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date    2021-NOV-29 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>
/** @brief   Class which implements a motor driver for a small car door linear actuator
 * @details  Checks if the current digital value at the pin is above a certain threshold
 *           and gets the current value
 */
class LilMotorStrike

{
  protected:
    /// Stores the brake pin for the motor driver chip
    uint8_t brake_pin;
    /// Stores the direction pin for the motor driver chip
    uint8_t Dir_pin;
    /// Stores the PWM pin for the motor driver chip
    uint8_t PWM_pin;

  public:
    // Class object constructor
    LilMotorStrike(uint8_t Brake, uint8_t Dir, uint8_t PWM);
    // Commands the linear actuator to fully ectend and then retract
    void lil_motor_strike(void);
};
