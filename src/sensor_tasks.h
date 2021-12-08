/** @file sensor_tasks.h
 *  This file contains tasks which record drum strokes on a sensor
 * 
 *  @author  Patrick Ward, Daniel Turn, and Sachin Gokhale
 *  @date    2021-NOV-28 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>
#include "sensor_driver.h"
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "shares.h"
// Bass sensor recording task
void bass_listen_task (void* p_params);
// Snare sensor recording task
void snare_listen_task (void* p_params);