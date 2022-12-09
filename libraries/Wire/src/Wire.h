#ifndef WIRE_H
#define WIRE_H

#include <avr/io.h>
#include <Arduino.h>

#if defined(TWCR)    // TWI hardware
  #include "TwoWire/TwoWire.h"

#elif defined(USICR) // USI hardware
  #include "USIWire/USIWire.h"

#endif

#endif
