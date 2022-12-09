/*
  usi_io.h - definitions for TWI/I2C via USI
  Copyright (c) 2017 Puuu.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef USI_IO_h
#define USI_IO_h

#include <avr/io.h>

#if defined(__AVR_ATmega165__)   || defined(__AVR_ATmega165A__)  || defined(__AVR_ATmega165P__)   \
|| defined(__AVR_ATmega165PA__)  || defined(__AVR_ATmega325__)   || defined(__AVR_ATmega325A__)   \
|| defined(__AVR_ATmega325P__)   || defined(__AVR_ATmega325PA__) || defined(__AVR_ATmega3250__)   \
|| defined(__AVR_ATmega3250A__)  || defined(__AVR_ATmega3250P__) || defined(__AVR_ATmega3250PA__) \
|| defined(__AVR_ATmega645__)    || defined(__AVR_ATmega645A__)  || defined(__AVR_ATmega645P__)   \
|| defined(__AVR_ATmega6450__)   || defined(__AVR_ATmega6450A__) || defined(__AVR_ATmega6450P__)  \
|| defined(__AVR_ATmega169__)    || defined(__AVR_ATmega169A__)  || defined(__AVR_ATmega169P__)   \
|| defined(__AVR_ATmega169PA__)  || defined(__AVR_ATmega329__)   || defined(__AVR_ATmega329A__)   \
|| defined(__AVR_ATmega329P__)   || defined(__AVR_ATmega329PA__) || defined(__AVR_ATmega3290__)   \
|| defined(__AVR_ATmega3290A__)  || defined(__AVR_ATmega3290P__) || defined(__AVR_ATmega3290PA__) \
|| defined(__AVR_ATmega649__)    || defined(__AVR_ATmega649A__)  || defined(__AVR_ATmega649P__)   \
|| defined(__AVR_ATmega6490__)   || defined(__AVR_ATmega6490A__) || defined(__AVR_ATmega6490P__)
  #define DDR_USI DDRE
  #define PORT_USI PORTE
  #define PIN_USI PINE
  #define PORT_USI_SDA PORTE5
  #define PORT_USI_SCL PORTE4
  #define PIN_USI_SDA PINE5
  #define PIN_USI_SCL PINE4
  #define USI_START_VECTOR USI_START_vect
  #define USI_OVERFLOW_VECTOR USI_OVERFLOW_vect
#endif

#ifndef USI_START_COND_INT
  #define USI_START_COND_INT USISIF
#endif

#ifndef DDR_USI_CL
  #define DDR_USI_CL DDR_USI
  #define PORT_USI_CL PORT_USI
  #define PIN_USI_CL PIN_USI
#endif

#endif
