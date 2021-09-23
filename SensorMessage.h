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

    float PT_HE;                   ///< 16 bit unsigned integer representing the Helium presurrant supply [psi]
    uint16_t PT_Purge;                ///< 16 bit unsigned integer representing the Nitrogen purge supply [psi]
    uint16_t PT_Pneu;                 ///< 16 bit unsigned integer representing the Nitrogen pneumatic supply [psi]
    uint16_t PT_FUEL_PV;              ///< 16 bit unsigned integer representing the Gas above fuel in pressure vessel [psi]
    uint16_t PT_LOX_PV;               ///< 16 bit unsigned integer representing the Gas above LOX in pressure vessel [psi]
    uint16_t PT_FUEL_INJ;             ///< 16 bit unsigned integer representing the Fuel pressure before entering chamber [psi]
    uint16_t PT_CHAM;                 ///< 16 bit unsigned integer representing the Chamber pressure [psi]
    uint16_t TC_FUEL_PV;              ///< 16 bit unsigned integer representing the Gas above fuel in pressure vessel (possible surface mount) [K]
    uint16_t TC_LOX_PV;               ///< 16 bit unsigned integer representing the Gas above LOX in pressure vessel (possible surface mount) [K]
	uint16_t TC_WATER_IN;			  ///< 16 bit unsigned integer representing the Water inlet temperature (Compression Probe) [K]
	uint16_t TC_WATER_OUT;			  ///< 16 bit unsigned integer representing the Water outlet temperature (Surface Mount) [K]
	uint16_t TC_CHAM_SENSOR;		  ///< 16 bit unsigned integer representing the temperature near the chamber PT [K]
    uint16_t TC_LOX_Valve_Main;       ///< 16 bit unsigned integer representing the External sensor for valve chill in and force [K]
    uint16_t RC_LOX_Level;            ///< 16 bit unsigned integer representing the Capacitive level sensor of LOX in pressure vessel [F]
    uint16_t FT_Thrust;               ///< 16 bit unsigned integer representing the Load cell that measures thrust of engine [lbf]
    
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
