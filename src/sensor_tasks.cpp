
/** @file sensor_tasks.cpp
 *  This file contains tasks which record drum strokes on a sensor
 * 
 *  @author  Patrick Ward
 *  @date    2021-NOV-28 Original file
 */
#include "sensor_tasks.h"
/** @brief   Task which records user input to the bass drum
 *  @details This task records the drum strokes on the bass drum and sends it to the bass_play_task()
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void bass_listen_task (void* p_params)
{
    (void)p_params;            // Does nothing but shut up a compiler warning

    uint8_t STATE = 0;
    uint8_t WAITING = 0;
    uint8_t RECORD = 1;

    sensor base_sensor(A5,30); // Creates a sensor object for the base

    bool ran = false;
    uint32_t time;
    uint32_t last;

    for (;;)
    {
        vTaskDelay(100);
        if (STATE == WAITING){
            if (!ran){
                Serial.println(base_sensor.get());
                if (base_sensor.check()){
                    STATE = RECORD;
                    time = millis();
                    last = time;
                    ran = true;
                }
            }
        }else if (STATE == RECORD){
            time = millis();
            if (time-last <= 5000 && listening.get()){
                if (base_sensor.check()){
                    Serial.println(time-last); //print time
                    strike_timeB.put(time-last);
                    last = time;
                }
            } else {
                STATE = WAITING;
                listening.put(false);
            }
        }else{}
    }
}
/** @brief   Task which records user input to the snare drum
 *  @details This task records the drum strokes on the snare drum and sends it to the snare_play_task()
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void snare_listen_task (void* p_params)
{
    (void)p_params;            // Does nothing but shut up a compiler warning

    uint8_t STATE = 0;
    uint8_t WAITING = 0;
    uint8_t RECORD = 1;

    sensor snare_sensor(A4,30); // Creates a sensor object for the base
    Serial.println("At Snare Sensor Task");
    
    bool ran = false;
    uint32_t time;
    uint32_t last;

    for (;;)
    {
        vTaskDelay(100);
        if (STATE == WAITING){
            if (!ran){
                Serial.println(snare_sensor.get());
                if (snare_sensor.check()){
                    STATE = RECORD;
                    time = millis();
                    last = time;
                    ran = true;
                    Serial.println("ouch");

                }
            }
        }else if (STATE == RECORD){
            time = millis();
            if (time-last <= 5000 && listening.get()){
                if (snare_sensor.check()){
                    Serial.println(time-last);
                    strike_timeS.put(time-last);
                    last = time;
                }
            } else {
                STATE = WAITING;
                listening.put(false);
                Serial.println("escape");
            }
        }else{}
    }
}