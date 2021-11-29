/** @file sensor_tasks.h
 *  This file contains tasks which record drum strokes on a sensor
 * 
 *  @author  Patrick Ward
 *  @date    2021-NOV-28 Original file
 */
#include <Arduino.h>
#include <PrintStream.h>
#include "sensor.h"
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
void bass_listen_task (void* p_params);
void snare_listen_task (void* p_params);