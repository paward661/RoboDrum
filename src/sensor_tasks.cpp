
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

    sensor base_sensor(A5,100); // Creates a sensor object for the base (Pin,Threshold)

    bool ran = false;
    uint32_t time;
    uint32_t last;

    for (;;)
    {
        if (STATE == WAITING){
            if (!ran){
                vTaskDelay(25);
                //Serial.println(base_sensor.get());
                if (base_sensor.check()){
                    STATE = RECORD;
                    time = millis();
                    last = time;
                    if (first.get() == 0){
                        first.put(2);
                        first_time.put(time);
                    }else{
                        strike_timeB.put(time - first_time.get());
                    }
                    ran = true;
                    Serial.println("ouch on my bass");
                    vTaskDelay(200);
                }
            }else{
                vTaskDelay(80000);
            }
        }else if (STATE == RECORD){
            time = millis();
            if (time-last <= 5000 && listening.get()){
                if (base_sensor.check()){
                    Serial.println("basstime:");
                    // Serial.println(time-last);
                    strike_timeB.put(time-last); 
                    last = time;
                    vTaskDelay(200);
                }
            } else {
                STATE = WAITING;
                listening.put(false);
                Serial.println("escape my bass");
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

    sensor snare_sensor(A4,1000); // Creates a sensor object for the snare (Pin,Threshold)
    //Serial.println("At Snare Sensor Task");
    
    bool ran = false;
    uint32_t time;
    uint32_t last;

    for (;;)
    {
        if (STATE == WAITING){
            if (!ran){
                vTaskDelay(100);
                //Serial.println(snare_sensor.get());
                if (snare_sensor.check()){
                    STATE = RECORD;
                    time = millis();
                    last = time;
                    if (first.get() == 0){
                        first.put(1);
                        first_time.put(time);
                    }else{
                        strike_timeB.put(time - first_time.get());
                    }
                    ran = true;
                    Serial.println("ouch on my snare");
                    vTaskDelay(200);
                }
            }else{
                vTaskDelay(80000);
            }
        }else if (STATE == RECORD){
            time = millis();
            if (time-last <= 5000 && listening.get()){
                if (snare_sensor.check()){
                    strike_timeB.put(time-last); 
                     Serial.println("snaretime:");
                    // Serial.println(time-last);
                    // Serial.println(snare_sensor.get());
                    last = time;
                    vTaskDelay(180);
                }
            } else {
                STATE = WAITING;
                listening.put(false);
                Serial.println("escape my snare");
            }
        }else{}
    }
}