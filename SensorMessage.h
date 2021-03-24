/**
 * @file SensorMessage.h
 * @author Brian Almaguer (brianharo2000@gmail.com)
 * @brief Libarary for creating a return message comprised of sensordata. Sensor data is specific to LPG Rocket Engine Project.
 * @version 0.1
 * @date 2021-02-26
 * 
 * @copyright Copyright (c) 2021 LiquidPropulsionGroup
 * 
 */
#ifndef SensorMessage_h
#define SensorMessage_h

#include "Arduino.h"

/**
 * @brief 
 * 
 */
class SensorMessage
{
  public:
    /**
     * @brief Construct a new Sensor Message object
     * 
     * @param startCount 
     */
    SensorMessage(int startCount);

    /**
     * @brief Builds and sends a serial information.
     * 
     */
    void Send();

    uint16_t PT_HE;                   ///< 16 bit unsigned integer representing the Helium presurrant supply
    uint16_t PT_Purge;                ///< 16 bit unsigned integer representing the Nitrogen purge supply
    uint16_t PT_Pneu;                 ///< 16 bit unsigned integer representing the Nitrogen pneumatic supply
    uint16_t PT_FULE_PV;              ///< 16 bit unsigned integer representing the Gas above fuel in pressure vessel
    uint16_t PT_LOX_PV;               ///< 16 bit unsigned integer representing the Gas above LOX in pressure vessel
    uint16_t PT_FUEL_INJ;             ///< 16 bit unsigned integer representing the Fuel pressure before entering chamber
    uint16_t PT_CHAM;                 ///< 16 bit unsigned integer representing the Chamber pressure
    uint16_t TC_FUEL_PV;              ///< 16 bit unsigned integer representing the Gas above fuel in pressure vessel (possible surface mount)
    uint16_t TC_LOX_PV;               ///< 16 bit unsigned integer representing the Gas above LOX in pressure vessel (possible surface mount)
    uint16_t TC_LOX_Valve_Main;       ///< 16 bit unsigned integer representing the External sensor for valve chill in and force
    uint16_t RC_LOX_Level;            ///< 16 bit unsigned integer representing the Capacitive level sensor of LOX in pressure vessel
    uint16_t FT_Thrust;               ///< 16 bit unsigned integer representing the Load cell that measures thrust of engine
    
  private:
    /**
     * @brief Set the Buffer object
     * 
     */
    void SetBuffer();

    uint8_t count;                    ///< Counts the number of messages being sent
    char buff[225];                   ///< Maximum char array of a sensor message
};

#endif
