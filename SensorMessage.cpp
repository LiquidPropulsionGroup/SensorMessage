/**
 * @file SensorMessage.cpp
 * @author Brian Almaguer (brianharo2000@gmail.com)
 * @brief Library for flashing SensorMessage code.
 * @version 0.1
 * @date 2021-02-26
 * 
 * @copyright Copyright (c) 2021 LiquidPropulsionGroup
 * 
 */

#include "Arduino.h"
#include "SensorMessage.h"

/**
 * @brief Construct a new Sensor Message:: Sensor Message object
 * 
 * @param startCount 
 */
SensorMessage::SensorMessage(int startCount)
{
    count = startCount;
}

/**
 * @brief Builds and sends a serial information.
 * 
 */
void SensorMessage::Send()
{
    this->SetBuffer();
    Serial.println(buff);
}

/**
 * @brief Set the Buffer object
 * 
 */
void SensorMessage::SetBuffer()
{
    sprintf(buff, "{\"PT_HE\":%hu,\"PT_Purge\":%hu,\"PT_Pneu\":%hu,\"PT_FULE_PV\":%hu,\"PT_LOX_PV\":%hu,\"PT_FUEL_INJ\":%hu,\"PT_CHAM\":%hu,\"TC_FUEL_PV\":%hu,\"TC_LOX_PV\":%hu,\"TC_LOX_Valve_Main\":%hu,\"RC_LOX_Level\":%hu,\"FT_Thrust\":%hu}",
            this->PT_HE, this->PT_Purge, this->PT_Pneu, this->PT_FULE_PV, this->PT_LOX_PV, this->PT_FUEL_INJ, this->PT_CHAM, this->TC_FUEL_PV, this->TC_LOX_PV, this->TC_LOX_Valve_Main, this->RC_LOX_Level, this->FT_Thrust);
            this->count++;
}