/** @file playback_tasks.h
 *  This file contains tasks which time and play drum strokes.
 * 
 *  @author  Sachin Gokhale
 *  @date    2021-NOV-30 Original file
 */

#include <Arduino.h>
#include <PrintStream.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "LilMo.h"
#include "BigMo.h"
#include "shares.h"

void bass_play_task(void* p_params);
void snare_play_task(void* p_params);
