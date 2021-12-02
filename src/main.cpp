/** @file main.cpp
 *    This file contains the programing necessary for an
 *    automatic drum set. 
 * 
 *  @author Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date   28 Nov 2021 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "taskshare.h"         // Header for inter-task shared data
#include "taskqueue.h"         // Header for inter-task data queues
#include "shares.h"            // Header for shares used in this project
#include "sensor_tasks.h"           // Header for tasks recording drum input
#include "playback_tasks.h"         // Header for tasks playing the drums

/// A share which holds boolean value for if the program should continue to record data
Share<bool> listening ("Recording Times");

/// A queue which holds a bunch of data taken by a measurement task
Queue<uint32_t> strike_timeB (100, "Bass Strike Times");
/// A queue which holds a bunch of data taken by a measurement task
Queue<uint32_t> strike_timeS (100, "Bass Strike Times");


/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates
 *           the tasks which will be run.
 */
void setup () 
{
    // Start the serial port, wait a short time, then say hello. Use the
    // non-RTOS delay() function because the RTOS hasn't been started yet
    Serial.begin (115200);
    delay (2000);
    Serial << endl << endl << "Hello, I'm ready to jam" << endl;

    listening.put(true);
    
    // Create a task which records bass drum input
    xTaskCreate (bass_listen_task,
                 "BassLis",                       // Task name for printouts
                 4096,                            // Stack size: Not sure how big I should make this
                 NULL,                            // Parameters for task fn.
                 5,     //was 3                          // Priority: May need to revisit this (also not sure if we can have two tasks at the same priority)
                 NULL);                           // Task handle
    // // Create a task which records snare drum input
    xTaskCreate (snare_listen_task,
                 "SnareLis",
                 4096,                            // Not sure how big I should make this
                 NULL,
                 5,    //was 3                           // May need to revisit this (also not sure if we can have two tasks at the same priority)
                 NULL);
    // Create a task which plays the bass drum
    xTaskCreate (bass_play_task,
                 "BassPlay",
                 4096,                            // Not sure how big I should make this
                 NULL,
                 3,                               // May need to revisit this (also not sure if we can have two tasks at the same priority)
                 NULL);
    // Create a task which plays the snare drum
    xTaskCreate (snare_play_task,
                 "SnarePlay",
                 4096,                            // Not sure how big I should make this
                 NULL,
                 3,  // was 5                             // May need to revisit this (also not sure if we can have two tasks at the same priority)
                 NULL);
    // If using an STM32, we need to call the scheduler startup function now;
    // if using an ESP32, it has already been called for us
    #if (defined STM32L4xx || defined STM32F4xx)
        vTaskStartScheduler ();
    #endif
}
/** @brief   Arduino's low-priority loop function, which we don't use.
 *  @details A non-RTOS Arduino program runs all of its continuously running
 *           code in this function after @c setup() has finished. When using
 *           FreeRTOS, @c loop() implements a low priority task on most
 *           microcontrollers and crashes on some others, so we'll not use it.
 */
void loop () 
{
}