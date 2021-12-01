/** @file playback_tasks.cpp
 *  This file contains tasks which time and play drum strokes.
 * 
 *  @author  Sachin Gokhale
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

  uint8_t STATE = 0;
  uint8_t WAITING = 0;
  uint8_t PLAY = 1;
  BigMotorStrike bigMo(10);
  uint32_t val = 0;
  for (;;)
  {
    if (STATE == WAITING)
    {
      vTaskDelay(1000);
      if (listening.get() == false)
      {
        STATE = PLAY;
        bigMo.big_motor_strike();
        vTaskDelay(1000);
      }
    }
    else if (STATE == PLAY)
    {
      val = strike_timeB.get();
      vTaskDelay(val);
      bigMo.big_motor_strike();
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

  uint8_t STATE = 0;
  uint8_t WAITING = 0;
  uint8_t PLAY = 1;
  LilMotorStrike lilMo(9,12,3);
  uint32_t val = 0;
  for (;;)
  {
    if (STATE == WAITING)
    {
      vTaskDelay(2000);
      Serial.println(listening.get());
      if (listening.get() == false)
      {
        STATE = PLAY;
        lilMo.lil_motor_strike();
        vTaskDelay(1000);
      }
    }
    else if (STATE == PLAY)
    {
      val = strike_timeS.get();
      vTaskDelay(val);
      lilMo.lil_motor_strike();
    }
    else{}
  }
}