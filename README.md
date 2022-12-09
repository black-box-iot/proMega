

An Arduino core for most 64 and 100 pin AVRs, all running [Optiboot flash](#write-to-own-flash). This core requires at least Arduino IDE v1.6, where v1.8.5+ is recommended. <br/>
If you're into "native" AVR programming, I'm happy to tell you that all relevant keywords are being highlighted by the IDE through a separate keywords file.


# Table of contents
* [Supported microcontrollers](#supported-microcontrollers)
* [Supported clock frequencies](#supported-clock-frequencies)
* [Printf support](#printf-support)
* [Pin macros](#pin-macros)
* [PROGMEM with flash sizes greater than 64kB](#progmem-with-flash-sizes-greater-than-64kb)
* [Write to own flash](#write-to-own-flash)
* **[How to install](#how-to-install)**
  - [Boards Manager Installation](#boards-manager-installation)
  - [Manual Installation](#manual-installation)
  - [PlatformIO](#platformio)


## Supported microcontrollers:

* ATmega128
* ATmega64

<br/>

## Printf support
Unlike the official Arduino cores, BLACKBOX has printf support out of the box. If you're not familiar with printf you should probably [read this first](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm). It's added to the Print class and will work with all libraries that inherit Print. Printf is a standard C function that lets you format text much easier than using Arduino's built-in print and println. Note that this implementation of printf will NOT print floats or doubles. This is a limitation of the avr-libc printf implementation on AVR microcontrollers, and nothing I can easily fix.

If you're using a serial port, simply use `Serial.printf("Milliseconds since start: %ld\n", millis());`. Other libraries that inherit the Print class (and thus supports printf) are the LiquidCrystal LCD library and the U8G2 graphical LCD library.


## Pin macros
Note that you don't have to use the digital pin numbers to refer to the pins. You can also use some predefined macros that maps "Arduino pins" to the port and port number:

```c++
// Use PIN_PE0 macro to refer to pin PE0 (Arduino pin 0)
digitalWrite(PIN_PE0, HIGH);

// Results in the exact same compiled code
digitalWrite(0, HIGH);

```

## PROGMEM with flash sizes greater than 64kB
The usual `PROGMEM` attribute stores constant data such as string arrays to flash and is great if you want to preserve the precious RAM. However, PROGMEM will only store content in the lower section, from 0 and up to 64kB. If you want to store data in other sections, you can use `PROGMEM1` (64 - 128kB), `PROGMEM2` (128 - 192kB), or `PROGMEM3` (192 - 256kB), depending on the chip you're using.
Accessing this data is not as straight forward as with `PROGMEM`, but it's still doable:

```c
const char far_away[] PROGMEM1 = "Hello from far away!\n"; // (64  - 128kB)
const char far_far_away[] PROGMEM2 = "Hello from far, far away!\n"; // (128 - 192kB)
const char far_far_far_away[] PROGMEM3 = "Hello from far, far, far away!\n"; // (192 - 256kB)

void print_progmem()
{
  uint8_t i;
  char c;

  // Print out far_away
  for(i = 0; i < sizeof(far_away); i++)
  {
    c = pgm_read_byte_far(pgm_get_far_address(far_away) + i);
    Serial.write(c);
  }

  // Print out far_far_away
  for(i = 0; i < sizeof(far_far_away); i++)
  {
    c = pgm_read_byte_far(pgm_get_far_address(far_far_away) + i);
    Serial.write(c);
  }
  // Print out far_far_far_away
  for(i = 0; i < sizeof(far_far_far_away); i++)
  {
    c = pgm_read_byte_far(pgm_get_far_address(far_far_far_away) + i);
    Serial.write(c);
  }
}

```


## Write to own flash
BLACKBOX uses Optiboot Flash, a bootloader that supports flash writing within the running application, thanks to the work of [@majekw](https://github.com/majekw).
This means that content from e.g. a sensor can be stored in the flash memory directly without the need of external memory. Flash memory is much faster than EEPROM, and can handle at least 10 000 write cycles before wear becomes an issue.


## How to install
#### Boards Manager Installation
This installation method requires Arduino IDE version 1.6.4 or greater.
* Open the Arduino IDE.
* Open the **File > Preferences** menu item.
* Enter the following URL in **Additional Boards Manager URLs**: `https://black-box-iot.github.io/package_black_box_pro_mega_index.json`
* Open the **Tools > Board > Boards Manager...** menu item.
* Wait for the platform indexes to finish downloading.
* Scroll down until you see the **BLACKBOX** entry and click on it.
* Click **Install**.
* After installation is complete close the **Boards Manager** window.

#### Manual Installation
Click on the "Download ZIP" button in the upper right corner. Extract the ZIP file, and move the extracted folder to the location "**~/Documents/Arduino/hardware**". Create the "hardware" folder if it doesn't exist.
Open Arduino IDE, and a new category in the boards menu called "BLACKBOX" will show up.

#### PlatformIO
[PlatformIO](http://platformio.org) is an open source ecosystem for IoT development and supports BLACKBOX.





