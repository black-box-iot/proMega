/***************************************************|
|            MEGACORE AVR 64-PIN PINOUT             |
|        https://github.com/MCUdude/MegaCore        |
|                                                   |
| This file is used when compiling for:             |
| ATmega2561/V                                      |
| ATmega1281/V                                      |
| ATmega128/A                                       |
| ATmega64/A                                        |
| ATmega165/A/P/PA                                  |
| ATmega325/A/P/PA                                  |
| ATmega645/A/P                                     |
| ATmega169/A/P/PA                                  |
| ATmega329/A/P/PA                                  |
| ATmega649/A/P                                     |
|                                                   |
|***************************************************/


#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define MEGACORE
#define MCUDUDE_MEGACORE

// Current pinout
#define MEGACORE_64_PIN_AVR_PINOUT

// Digital pins
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define NUM_DIGITAL_PINS           (54)

#else // ATmega64/128, AT90CAN32/64/128, ATmega165/325/645, ATmega169/329/649
  #define NUM_DIGITAL_PINS           (53)
#endif

// PWM pins
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) || defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
  #define digitalPinHasPWM(p)      (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15))
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define digitalPinHasPWM(p)      (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15) || ((p) == 53))
#else // ATmega165/325/645, ATmega169/329/649
  #define digitalPinHasPWM(p)      (((p) >= 12 && (p) <= 15))
#endif

// Builtin LED
#define LED_BUILTIN   (13)
static const uint8_t LED = LED_BUILTIN;

// Analog pins
#define PIN_A0   (45)
#define PIN_A1   (46)
#define PIN_A2   (47)
#define PIN_A3   (48)
#define PIN_A4   (49)
#define PIN_A5   (50)
#define PIN_A6   (51)
#define PIN_A7   (52)
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define NUM_ANALOG_INPUTS          (8)
#define analogInputToDigitalPin(p) (((p) < 8) ? (p) + 45 : -1)
#define analogPinToChannel(p)      ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 45 ? (p) - 45 : -1)

// SPI defs
#define PIN_SPI_SS    (8)
#define PIN_SPI_SCK   (9)
#define PIN_SPI_MOSI  (10)
#define PIN_SPI_MISO  (11)
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t SCK  = PIN_SPI_SCK;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;

// i2c
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)  || defined(__AVR_AT90CAN32__)  \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__) || defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2561__)
  #define PIN_WIRE_SCL  (18)
  #define PIN_WIRE_SDA  (19)
#else // ATmega165/325/645, ATmega169/329/649
  #define PIN_WIRE_SCL  (4)
  #define PIN_WIRE_SDA  (5)
#endif
static const uint8_t SCL = PIN_WIRE_SCL;
static const uint8_t SDA = PIN_WIRE_SDA;

// Interrupts
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)  || defined(__AVR_AT90CAN32__)  \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__) || defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2561__)
  #define EXTERNAL_NUM_INTERRUPTS    (8)
  #define digitalPinToInterrupt(p)   (((p) >= 4 && (p) <= 7) ? (p) : ((p) >= 18 && (p) <= 21) ? (p) - 18 : NOT_AN_INTERRUPT)
#else // ATmega165/325/645, ATmega169/329/649
  #define EXTERNAL_NUM_INTERRUPTS    (1)
  #define digitalPinToInterrupt(p)   ((p) == 19 ? 0 : NOT_AN_INTERRUPT)
#endif


// PCINT
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define digitalPinToPCICR(p)    ((((p) >= 8) && ((p) <= 15)) || ((p) == 0) ? (&PCICR) : ((uint8_t*)0))
  #define digitalPinToPCICRbit(p) ((((p) >= 8) && ((p) <= 15)) ? 0 : ((((p) == 0)  ? 1 : 0)))
  #define digitalPinToPCMSK(p)    ((((p) >= 8) && ((p) <= 15)) ? (&PCMSK0) : ((((p) == 0)  ? (&PCMSK1) : ((uint8_t*)0))))
  #define digitalPinToPCMSKbit(p) ((((p) >= 8) && ((p) <= 15)) ? ((p) - 8) : (((p) ==  0) ? 1 : 0))
#elif defined(__AVR_ATmega165__) || defined(__AVR_ATmega165A__)  || defined(__AVR_ATmega165P__)  \
|| defined(__AVR_ATmega165PA__)  || defined(__AVR_ATmega325__)   || defined(__AVR_ATmega325A__)  \
|| defined(__AVR_ATmega325P__)   || defined(__AVR_ATmega325PA__) || defined(__AVR_ATmega645__)   \
|| defined(__AVR_ATmega645A__)   || defined(__AVR_ATmega645P__)  || defined(__AVR_ATmega169__)   \
|| defined(__AVR_ATmega169A__)   || defined(__AVR_ATmega169P__)  || defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega329__)    || defined(__AVR_ATmega329A__)  || defined(__AVR_ATmega329P__)  \
|| defined(__AVR_ATmega329PA__)  || defined(__AVR_ATmega649__)   || defined(__AVR_ATmega649A__)  \
|| defined(__AVR_ATmega649P__)
  #define digitalPinToPCICR(p)    (((p) >= 0) && ((p) <= 15) ? (&EIMSK) : (uint8_t*)0)
  #define digitalPinToPCICRbit(p) (((p) >= 0) && ((p) <= 7)  ? (PCIE0) : ((p) >= 8) && ((p) <= 15) ? (PCIE1) : 0)
  #define digitalPinToPCMSK(p)    (((p) >= 0) && ((p) <= 7)  ? (&PCMSK0) : ((p) >= 8) && ((p) <= 15) ? (&PCMSK1) : ((uint8_t*)0))
  #define digitalPinToPCMSKbit(p) (((p) >= 0) && ((p) <= 7)  ? (p) : ((p) >= 8) && ((p) <= 15) ? ((p) - 8) : 0)
#endif

#define PIN_PE0 0
#define PIN_PE1 1
#define PIN_PE2 2
#define PIN_PE3 3
#define PIN_PE4 4
#define PIN_PE5 5
#define PIN_PE6 6
#define PIN_PE7 7
#define PIN_PB0 8
#define PIN_PB1 9
#define PIN_PB2 10
#define PIN_PB3 11
#define PIN_PB4 12
#define PIN_PB5 13
#define PIN_PB6 14
#define PIN_PB7 15
#define PIN_PG3 16
#define PIN_PG4 17
#define PIN_PD0 18
#define PIN_PD1 19
#define PIN_PD2 20
#define PIN_PD3 21
#define PIN_PD4 22
#define PIN_PD5 23
#define PIN_PD6 24
#define PIN_PD7 25
#define PIN_PG0 26
#define PIN_PG1 27
#define PIN_PC0 28
#define PIN_PC1 29
#define PIN_PC2 30
#define PIN_PC3 31
#define PIN_PC4 32
#define PIN_PC5 33
#define PIN_PC6 34
#define PIN_PC7 35
#define PIN_PG2 36
#define PIN_PA7 37
#define PIN_PA6 38
#define PIN_PA5 39
#define PIN_PA4 40
#define PIN_PA3 41
#define PIN_PA2 42
#define PIN_PA1 43
#define PIN_PA0 44
#define PIN_PF0 45
#define PIN_PF1 46
#define PIN_PF2 47
#define PIN_PF3 48
#define PIN_PF4 49
#define PIN_PF5 50
#define PIN_PF6 51
#define PIN_PF7 52
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define PIN_PG5 53
#endif

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
  (uint16_t) &DDRE,
  (uint16_t) &DDRF,
  (uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
  (uint16_t) &PORTE,
  (uint16_t) &PORTF,
  (uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
  NOT_A_PIN,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
  (uint16_t) &PINE,
  (uint16_t) &PINF,
  (uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
  PE, // PE0 ** D0
  PE, // PE1 ** D1
  PE, // PE2 ** D2
  PE, // PE3 ** D3
  PE, // PE4 ** D4
  PE, // PE5 ** D5
  PE, // PE6 ** D6
  PE, // PE7 ** D7
  PB, // PB0 ** D8
  PB, // PB1 ** D9
  PB, // PB2 ** D10
  PB, // PB3 ** D11
  PB, // PB4 ** D12
  PB, // PB5 ** D13
  PB, // PB6 ** D14
  PB, // PB7 ** D15
  PG, // PG3 ** D16
  PG, // PG4 ** D17
  PD, // PD0 ** D18
  PD, // PD1 ** D19
  PD, // PD2 ** D20
  PD, // PD3 ** D21
  PD, // PD4 ** D22
  PD, // PD5 ** D23
  PD, // PD6 ** D24
  PD, // PD7 ** D25
  PG, // PG0 ** D26
  PG, // PG1 ** D27
  PC, // PC0 ** D28
  PC, // PC1 ** D29
  PC, // PC2 ** D30
  PC, // PC3 ** D31
  PC, // PC4 ** D32
  PC, // PC5 ** D33
  PC, // PC6 ** D34
  PC, // PC7 ** D35
  PG, // PG2 ** D36
  PA, // PA7 ** D37
  PA, // PA6 ** D38
  PA, // PA5 ** D39
  PA, // PA4 ** D40
  PA, // PA3 ** D41
  PA, // PA2 ** D42
  PA, // PA1 ** D43
  PA, // PA0 ** D44
  PF, // PF0 ** D45 ** A0
  PF, // PF1 ** D46 ** A1
  PF, // PF2 ** D47 ** A2
  PF, // PF3 ** D48 ** A3
  PF, // PF4 ** D49 ** A4
  PF, // PF5 ** D50 ** A5
  PF, // PF6 ** D51 ** A6
  PF, // PF7 ** D52 ** A7
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  PG, // PG5 ** D53
#endif
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
  _BV(0), // PE0 ** D0
  _BV(1), // PE1 ** D1
  _BV(2), // PE2 ** D2
  _BV(3), // PE3 ** D3
  _BV(4), // PE4 ** D4
  _BV(5), // PE5 ** D5
  _BV(6), // PE6 ** D6
  _BV(7), // PE7 ** D7
  _BV(0), // PB0 ** D8
  _BV(1), // PB1 ** D9
  _BV(2), // PB2 ** D10
  _BV(3), // PB3 ** D11
  _BV(4), // PB4 ** D12
  _BV(5), // PB5 ** D13
  _BV(6), // PB6 ** D14
  _BV(7), // PB7 ** D15
  _BV(3), // PG3 ** D16
  _BV(4), // PG4 ** D17
  _BV(0), // PD0 ** D18
  _BV(1), // PD1 ** D19
  _BV(2), // PD2 ** D20
  _BV(3), // PD3 ** D21
  _BV(4), // PD4 ** D22
  _BV(5), // PD5 ** D23
  _BV(6), // PD6 ** D24
  _BV(7), // PD7 ** D25
  _BV(0), // PG0 ** D26
  _BV(1), // PG1 ** D27
  _BV(0), // PC0 ** D28
  _BV(1), // PC1 ** D29
  _BV(2), // PC2 ** D30
  _BV(3), // PC3 ** D31
  _BV(4), // PC4 ** D32
  _BV(5), // PC5 ** D33
  _BV(6), // PC6 ** D34
  _BV(7), // PC7 ** D35
  _BV(2), // PG2 ** D36
  _BV(7), // PA7 ** D37
  _BV(6), // PA6 ** D38
  _BV(5), // PA5 ** D39
  _BV(4), // PA4 ** D40
  _BV(3), // PA3 ** D41
  _BV(2), // PA2 ** D42
  _BV(1), // PA1 ** D43
  _BV(0), // PA0 ** D44
  _BV(0), // PF0 ** D45 ** A0
  _BV(1), // PF1 ** D46 ** A1
  _BV(2), // PF2 ** D47 ** A2
  _BV(3), // PF3 ** D48 ** A3
  _BV(4), // PF4 ** D49 ** A4
  _BV(5), // PF5 ** D50 ** A5
  _BV(6), // PF6 ** D51 ** A6
  _BV(7), // PF7 ** D52 ** A7
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  _BV(5), // PG5 ** D53
#endif
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, // PE0 ** D0
  NOT_ON_TIMER, // PE1 ** D1
  NOT_ON_TIMER, // PE2 ** D2
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)  || defined(__AVR_AT90CAN32__)  \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__) || defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2561__)
  TIMER3A,      // PE3 ** D3
  TIMER3B,      // PE4 ** D4
  TIMER3C,      // PE5 ** D5
#else // ATmega165/325/645, ATmega169/329/649
  NOT_ON_TIMER, // PE3 ** D3
  NOT_ON_TIMER, // PE4 ** D4
  NOT_ON_TIMER, // PE5 ** D5
#endif
  NOT_ON_TIMER, // PE6 ** D6
  NOT_ON_TIMER, // PE7 ** D7
  NOT_ON_TIMER, // PB0 ** D8
  NOT_ON_TIMER, // PB1 ** D9
  NOT_ON_TIMER, // PB2 ** D10
  NOT_ON_TIMER, // PB3 ** D11
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
  TIMER0,       // PB4 ** D12
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__) || defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__)     || defined(__AVR_AT90CAN128__)
  TIMER2A,      // PB4 ** D12
#else // ATmega165/325/645, ATmega169/329/649
  TIMER0A,      // PB4 ** D12
#endif
  TIMER1A,      // PB5 ** D13
  TIMER1B,      // PB6 ** D14
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)  || defined(__AVR_AT90CAN32__)  \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__) || defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2561__)
  TIMER1C,      // PB7 ** D15
#else // ATmega165/325/645, ATmega169/329/649
  TIMER2A,      // PB7 ** D15
#endif
  NOT_ON_TIMER, // PG3 ** D16
  NOT_ON_TIMER, // PG4 ** D17
  NOT_ON_TIMER, // PD0 ** D18
  NOT_ON_TIMER, // PD1 ** D19
  NOT_ON_TIMER, // PD2 ** D20
  NOT_ON_TIMER, // PD3 ** D21
  NOT_ON_TIMER, // PD4 ** D22
  NOT_ON_TIMER, // PD5 ** D23
  NOT_ON_TIMER, // PD6 ** D24
  NOT_ON_TIMER, // PD7 ** D25
  NOT_ON_TIMER, // PG0 ** D26
  NOT_ON_TIMER, // PG1 ** D27
  NOT_ON_TIMER, // PC0 ** D28
  NOT_ON_TIMER, // PC1 ** D29
  NOT_ON_TIMER, // PC2 ** D30
  NOT_ON_TIMER, // PC3 ** D31
  NOT_ON_TIMER, // PC4 ** D32
  NOT_ON_TIMER, // PC5 ** D33
  NOT_ON_TIMER, // PC6 ** D34
  NOT_ON_TIMER, // PC7 ** D35
  NOT_ON_TIMER, // PG2 ** D36
  NOT_ON_TIMER, // PA7 ** D37
  NOT_ON_TIMER, // PA6 ** D38
  NOT_ON_TIMER, // PA5 ** D39
  NOT_ON_TIMER, // PA4 ** D40
  NOT_ON_TIMER, // PA3 ** D41
  NOT_ON_TIMER, // PA2 ** D42
  NOT_ON_TIMER, // PA1 ** D43
  NOT_ON_TIMER, // PA0 ** D44
  NOT_ON_TIMER, // PF0 ** D45 ** A0
  NOT_ON_TIMER, // PF1 ** D46 ** A1
  NOT_ON_TIMER, // PF2 ** D47 ** A2
  NOT_ON_TIMER, // PF3 ** D48 ** A3
  NOT_ON_TIMER, // PF4 ** D49 ** A4
  NOT_ON_TIMER, // PF5 ** D50 ** A5
  NOT_ON_TIMER, // PF6 ** D51 ** A6
  NOT_ON_TIMER, // PF7 ** D52 ** A7
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  TIMER0B,      // PG5 ** D53
#endif
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#if defined(UBRR1H)
  #define SERIAL_PORT_HARDWARE1       Serial1
  #define SERIAL_PORT_HARDWARE_OPEN1  Serial1
#endif

#endif
