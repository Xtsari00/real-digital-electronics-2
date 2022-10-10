# Lab 2: Bohdan Tsariuchenko 

### GPIO control registers

1. Complete the table for DDRB and PORTB control register values.

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state, high-impedance |
   | 0 | 1 | input| no| | Pull-up resistor activated
   | 1 | 0 | output| yes | low-level|
   | 1 | 1 | output | no | high-level|

### GPIO library

2. Complete the table with code sizes from three versions of the blink application.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style     | 480 |
   | Registers         | 182 |
   | Library functions | 182 |

### Traffic light

3. Scheme of traffic light application with one red/yellow/green light for cars, one red/green light for pedestrians, and one push button. Connect AVR device, LEDs, resistors, push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

  IMG_4893.HEIC![image](https://user-images.githubusercontent.com/99403641/194919921-9ee5d0dc-0399-41db-a5a2-227564e57c00.png)
