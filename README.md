# Cubet (CUBID-19) 
Cubet, a small single color led cube, build during the Covid-19 Quarantine

I always wanted a LED Cube. I started with the Schematic and Layout in January, and the PCB came together with COVID, so I had plenty of time to solder.
I gave my cube the name of Cubet (catalan word for small cube), but CUBID is also a good name :)

The microcontroller is a Samd21, with native USB, so no FTDI or similar is needed. It' a simple Arduino  compatible board.
It uses 74HC595 Shift Register.

:warning: The README is still in working process
:warning: The Software works, but the animations must be still coded


## Getting Started

* Install KiCad and make changes to the schematic/layout (if needed)
* Get the PCB from your favourite Producer
* Solder all the components
* Flash the Bootloader (if needed)
* Flash the Software

#### Prerequisites


* A lot of time 
* Patience
* More patience
* Soldering skill
* JTAG Programmer (I used an J_-LINK EDU Mini)
* Lots of time 



### Installing 
#### Flashing the Bootloader
#### Flashing the Software

## Built With

* [KiCad](http://www.kicad-pcb.org)
* [PlatformIO](http://platformio.org)o


## Authors

## License

This project is licensed under the Apache License - see the [LICENSE.md](LICENSE.md) file for tedtails

## Acknowledgments

[LED-Cube] (https://github.com/fuchsalex/LED-Cube)
[Mini KiCad Tutorial] (https://github.com/MalphasWats/hawk)
[KiCad Freerouting] (https://github.com/miho/freerouting)
[Gerber Export] (https://jnduli.co.ke/prepare-kicad-pcb-elecrow.html)
[PCB from Elecrow] (https://www.elecrow.com/pcb-manufacturing.html)
[SAMD21 GDB] (https://learn.adafruit.com/debugging-the-samd21-with-gdb/setup)
[SAMD21 Bootloader Protection] (https://roamingthings.de/posts/use-j-link-to-change-the-boot-loader-protection-of-a-sam-d21)
[Programming a SAMD bootloader using JLink & Linux] (https://hackaday.io/page/5997-programming-a-samd-bootloader-using-jlink-linux)


## Changes
Changes for the next version
* RGB LEDs
* ESP32 for Blueetoth and WLAN
* SPI, I2C and UART connectors for hardware upgrades
* Battery connector
* Maybe a 12x12x12 and a 16x16x16 version
