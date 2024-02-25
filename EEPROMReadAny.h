#ifndef _EEPROMAnything
#define _EEPROMAnything
#include <I2CMultiEEPROM.h>
#include <EEPROM.h>
#include <Arduino.h>  // for type definitions
template <typename T> int EEPROM_writeAnything(I2CMultiEEPROM * i2cme, int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
	  i2cme->XWrite(ee++, *p++);
    return i;
}

template <typename T> int EEPROM_readAnything(I2CMultiEEPROM * i2cme, int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = i2cme->XRead(ee++);
    return i;
}

template <typename T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <typename T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}

#endif
