# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.



## GitHub repository structure

   ```c
   PROJECT        // PlatfomIO project
   ├── include
   │  └── timer.h       
   ├── lib             // Libraries
   │  └── gpio
   │       └── gpio.c
   │       └── gpio.h
   │
   │   └── lcd
   │        └── lcd.definitions.h
   │        └── lcd.h
   │        └── lcd.c
   │
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   ├── platformio.ini  // Project Configuration File
   └── report.md       // Report of this project
   ```

## Recommended README.md file structure

### Team members

* Bohdan Tsariuchenko (responsible for xxx)
* Kasatkin Alexey (responsible for xxx)

## Hardware description

### Joystick

* GND to GND 
* +5V to +5V
* Vrx and Vry we connect to analog pins A0, A1 

### Rotation encoder

* GND to GND
* +5V to +5V
* CLK and DT to digital pins 11, 12
* SW to digital pin 2

### Digilent PmodCLP LCD modul 

* GND to GND 
* VCC to +5V J2
* pins 7,10 to digital pins 4, 7
* RW to GND
* Rs and En to digital pins 8 and 9

<img width="708" alt="Screenshot 2022-12-04 at 19 59 34" src="https://user-images.githubusercontent.com/99403641/205509958-d04eb5fd-29b5-4b95-9282-72a58216b41c.png">


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...