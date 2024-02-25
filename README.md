# EEPROMAnything Library

The EEPROMAnything library is a highly flexible Arduino library designed to extend the EEPROM functionality, allowing for easy reading and writing of any data type to both internal EEPROM and external EEPROM devices using the I2CMultiEEPROM library. This library abstracts the complexity of dealing with EEPROM data storage, offering a straightforward way to store and retrieve structured data.

## Features

- Seamless integration with the I2CMultiEEPROM library for external EEPROM devices.
- Direct support for the Arduino's built-in EEPROM.
- Generic template functions to read and write any data type, simplifying code and reducing errors.
- Compatibility with Arduino and other AVR-based microcontroller boards.

## Installation

To use the EEPROMAnything library, ensure you have the I2CMultiEEPROM library installed.

1. Download the EEPROMAnything library code.
2. Include both `EEPROMAnything.h` and `I2CMultiEEPROM.h` in your Arduino project.

## Usage

Before using EEPROMAnything functions, you must include the library header and, if using external EEPROMs, create an instance of the I2CMultiEEPROM class.

### Example

```cpp
#include <EEPROMAnything.h>
#include <I2CMultiEEPROM.h>

// Create an I2CMultiEEPROM instance if using external EEPROM
int eepromSizes[] = {512}; // Example external EEPROM size
I2CMultiEEPROM externalEEPROM(1024, 512, eepromSizes);

struct MyData {
  int sensorValue;
  float temperature;
};

void setup() {
  Serial.begin(9600);
  MyData data = {100, 36.5};

  // Write data to internal EEPROM
  EEPROM_writeAnything(0, data);

  // Write data to external EEPROM
  EEPROM_writeAnything(&externalEEPROM, 0, data);
}

void loop() {
  MyData data;
  
  // Read data from internal EEPROM
  EEPROM_readAnything(0, data);
  Serial.print("Internal - Sensor: ");
  Serial.print(data.sensorValue);
  Serial.print(", Temp: ");
  Serial.println(data.temperature);

  // Read data from external EEPROM
  EEPROM_readAnything(&externalEEPROM, 0, data);
  Serial.print("External - Sensor: ");
  Serial.print(data.sensorValue);
  Serial.print(", Temp: ");
  Serial.println(data.temperature);

  delay(10000); // Delay to make serial output readable
}
```

## API Reference

- `int EEPROM_writeAnything(I2CMultiEEPROM* i2cme, int ee, const T& value)`: Write any data type to external EEPROM.
- `int EEPROM_readAnything(I2CMultiEEPROM* i2cme, int ee, T& value)`: Read any data type from external EEPROM.
- `int EEPROM_writeAnything(int ee, const T& value)`: Write any data type to the Arduino's internal EEPROM.
- `int EEPROM_readAnything(int ee, T& value)`: Read any data type from the Arduino's internal EEPROM.

## Contributing

Contributions to the EEPROMAnything library are welcome. Please feel free to fork the repository, make improvements, and submit pull requests.

## License

This library is open-source and can be freely used in personal and commercial projects.

## Acknowledgments

This library is designed to make EEPROM data handling easier for Arduino enthusiasts, enabling complex data storage solutions without the need for cumbersome byte-level operations.
