# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.



## GitHub repository structure

   ```c
   YOUR_PROJECT        // PlatfomIO project
   ├── include         // Included files
   ├── lib             // Libraries
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```

## Recommended README.md file structure

### Team members

* Bohdan Tsariuchenko (responsible for xxx)
* Kasatkin Alexey (responsible for xxx)

## Hardware description

### Joystick

* GND to GND 
* +5V to +5V
* Vrx and Vry to analog pins A0, A1 

### Rotation encoder

* GND to GND
* +5V to +5V
* CLK and DT to digital pins 11, 12
* SW to digital pin 2



## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...
