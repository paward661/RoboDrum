/** @file sensor_driver.cpp
 * This file contains the definition of a sensor driver class
 * 
 * @author Patrick Ward, Daniel Turn, and Sachin Gokhale
 * @date  2021-Nov-29
 */
#include "sensor_driver.h"

/** @brief   Creates a pizo-electric sensor object 
 * @details  This constructor establishes variables with class-wide
 *           scope and creates a class object
 * @param    P1 uint8_t pin object
 * @param    threshold uint16_t digital threshold to signify a strike to record
 */
sensor::sensor(uint8_t P1, uint16_t threshold)
{
    // Stores the digital value threshold for a strike
    thresh = threshold;
    // Stores the Nucleo pin
    Pin = P1;
    Serial.println("snare sense constructed");
}

/** @brief   Adds a data point to the stat tracking object
 * @details  This function takes in no parameters and checks the digital 
 *           value to see if it is larger than the threshold
 * @return   a boolean value of true for a digital value above the threshold and
 *           false for a digital value below the threshold
 */
bool sensor::check (void)
{
    // Stores the digital value of the pin
    uint8_t val = analogRead(Pin);
    
    if (val >= thresh) {
        return true;
    } else {
        return false;
    }
}

/** @brief   Adds a data point to the stat tracking object
 * @details  This function takes in no parameters and reads the digital value of the pin
 * @return   val a uint16_t that holds the digital value of the pin
 */
uint16_t sensor::get(void)
{
    // Stores the digital value of the pin
    uint8_t val = analogRead(Pin);
    return val;
}
