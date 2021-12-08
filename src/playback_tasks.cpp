/** @file playback_tasks.cpp
 *  This file contains tasks which time and play drum strokes.
 * 
 *  @author  Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date    2021-NOV-30 Original file
 */
#include "playback_tasks.h"


/** @brief   Task which plays back the user input to the bass drum
 *  @details This task takes the recorded user input from bass_listen_task and initiates 
 *           playback with appropriate strikeTiming.
 *  @param   p_params A pointer to function parameters which we don't use.
 */

void bass_play_task (void* p_params)
{
  (void)p_params;                 // shut up compiler warning

  // Contains the current state value
  uint8_t STATE = 0;
  // Defines a waiting state value for the playback task
  uint8_t WAITING = 0;
  // Defines a playing state value for the playback task
  uint8_t PLAY = 1;
  // Creates a motor object for the bass drum
  BigMotorStrike bigMo(10);
  // Stores strike timing
  uint32_t val = 0;

  for (;;)
  {
    // This state waits for the recording tasks to finish
    if (STATE == WAITING)
    {
      vTaskDelay(1000);
      if (listening.get() == false)
      {
        STATE = PLAY;
        //bigMo.big_motor_strike();
        vTaskDelay(1000);
      }
    }
    // This state plays all the drum strikes from the bass recording task
    else if (STATE == PLAY)
    {
      bigMo.big_motor_strike();
      val = strike_timeB.get();
      vTaskDelay(val);
    }
    else{}
  }
}

/** @brief   Task which plays back the user input to the snare drum
 *  @details This task takes the recorded user input from snare_listen_task and initiates 
 *           playback with appropriate strikeTiming.
 *  @param  p_params A pointer to function parameters which we don't use.
 */
 
void snare_play_task (void* p_params)
{
  (void)p_params;                 // shut up compiler warning

  // Contains the current state value
  uint8_t STATE = 0;
  // Defines a waiting state value for the playback task
  uint8_t WAITING = 0;
  // Defines a playing state value for the playback task
  uint8_t PLAY = 1;
  // Creates one of the motor driver objects for the snare drum
  LilMotorStrike lilMo1(9,12,3);
  // Creates one of the motor driver objects for the snare drum
  LilMotorStrike lilMo2(8,13,11);
  // Stores strike timing
  uint32_t val = 0;
  // Used for switching between drum sticks
  bool a = true;

  for (;;)
  {
    // This state waits for the recording tasks to finish
    if (STATE == WAITING)
    {
      vTaskDelay(2000);
      //Serial.println(listening.get());
      if (listening.get() == false)
      {
        STATE = PLAY;
        //lilMo1.lil_motor_strike();
        vTaskDelay(1000);
      }
    }
    //This State plays using one snare motor at a time alternating back and forth
    else if (STATE == PLAY)
    {
      if (a){
        lilMo2.lil_motor_strike();
        a = false;
        val = strike_timeS.get();
        vTaskDelay(val);
      }else{
        lilMo1.lil_motor_strike();
        a = true;
        val = strike_timeS.get();
        vTaskDelay(val);
      }
    }
    else{}
  }
}