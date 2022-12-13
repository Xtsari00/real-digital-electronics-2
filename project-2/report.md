# Projekt-2 Motor rotation

PWM signal generation. Application of two or more Servo motors SG90.

## Project structure

   ```c
   YOUR_PROJECT        // PlatfomIO project
   ├── include         // Included files
   │   └── timer.h     // Include Interrupts
   ├── lib             // Libraries
   │   └── gpio        // Library for controlling GPIO pins
   │     └── gpio.h
   │     └── gpio.c                   
   ├── src             // Source file(s)
   │   └── main.c
   ├── test     
   ├── platformio.ini  // Project Configuration File
   └── report.md       // Report of this project
   ```

## Team members

* Bohdan Tsariuchenko (responsible for code, schematic and video)
* Kasatkin Alexey (responsible for code, schematic and video)

## Description of the hardware connection
### The first Servo motor SG90
* GND to GND
* V+ to +5V
* SIG to digital pin 9, which generated pwm signal

### Second Servo motor SG90
* GND to GND
* V+ to +5V
* SIG to digital pin 9, which generated pwm signal

![image](https://user-images.githubusercontent.com/99403641/207333823-ff0152bc-980c-4dc5-b27e-08ee8bdcb350.png)


Photo. 1 - Connection in the SimulIDE program

![IMG_5112](https://user-images.githubusercontent.com/99403641/207384070-fdf339b7-17d1-48d1-ab74-e6aeb7e71be6.jpg)

Photo. 2 - Real connection 

## Software description

Using the PCINT0_vect interrupt, which responds to pressing the connected button, we change the value of the MOVE parameter and thus determine which motor will move.

By setting the registers and the TIMER1_ovf_vect interrupt, we set the generation of the PWM signal that controls the Servo SG90 motors. According to the technical sheet, the 10th mode was used for generation. The upper limit of the PWM signal is determined by ICR1, the value of which is 2500 for a 64-bit prescaler. Thanks to this, we set my output signal to 50 Hz. The alternation of the generated signal determines the position of the motor arm. With the help of internet articles and then empirically, the values for the lowest and highest position of the engine were determined. For the lowest value, i.e. At 0° it is necessary for the positive pulse to last approximately 1 ms, for 90° 1.5 ms and for 180° a positive pulse of approx. 2 ms is required. The calculations are shown in the attached fig. 2.

Obr. 2 - Výpočty hodnôt použitých pri nastavení generovania PWM signálu

## Video
https://youtube.com/shorts/XYn5CBHAyrE?feature=share

## References

1. [ATmega328P datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf)
2. https://lastminuteengineers.com/servo-motor-arduino-tutorial/
