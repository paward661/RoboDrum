
/** @file sensor_tasks.cpp
 *  This file contains tasks which record drum strokes on a sensor
 * 
 *  @author  Patrick Ward
 *  @date    2021-NOV-28 Original file
 */
#include "sensor_tasks.h"
#include "sensor_driver.h"
/** @brief   Task which records user input to the bass drum
 *  @details This task records the drum strokes on the bass drum and sends it to the bass_play_task()
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void bass_listen_task (void* p_params)
{
    (void)p_params;            // Does nothing but shut up a compiler warning
    sensor base_sensor(A0,300); // Creates a sensor object for the base
    for (;;)
    {
        if (STATE == WAITING){
            if (base_sensor.check()){
                STATE = RECORD;
            }
        }else if (STATE == RECORD){
            if ()
        }
        // Delay the given number of RTOS ticks until beginning to run this
        // task loop again. The resulting timing is not accurate, as the time
        // it took to run the task adds to this interval and accumulates
        vTaskDelay (2500);
    }
}
/** @brief   Task which records user input to the snare drum
 *  @details This task records the drum strokes on the snare drum and sends it to the snare_play_task()
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void snare_listen_task (void* p_params)
{
    (void)p_params;            // Does nothing but shut up a compiler warning
    for (;;)
    {
        Serial << endl;
        // Delay the given number of RTOS ticks to run about twice a minute
        vTaskDelay (30000);
    }
}