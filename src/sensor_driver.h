/** @file sensor_driver.h
 *  This file contains the sensor class that measure drum impacts
 * 
 *  @author  Patrick Ward
 *  @date    2021-NOV-29 Original file
 */

#include <Arduino.h>

/** @brief   Class which implements a pizo-electric sensor object
 * @details  Checks if the current digital value at the pin is above a certain threshold
 *           and gets the current value
 */

class sensor

{
    protected:
        // Stores the digital value threshold for a strike
        uint16_t thresh;
        // Stores the Nucleo pin
        uint8_t Pin;

    public:
    // The class constructor
    sensor(uint8_t P1, uint16_t threshold);
    // Checks if the digital value is above the threshold
    bool check (void);
    // Gets the current digital value at the pin
    uint16_t get (void);
}

