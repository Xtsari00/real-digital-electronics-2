/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/



/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

#define Astate PB2

int pos = 0;
int xpos;
int ypos;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
   // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    

int main(void)
{
    int A_last_state;
    int Encpush;

    // Display first custom character at address 0
    lcd_putc(0);
    // Initialize display
    lcd_init(LCD_DISP_ON);

    // Put string(s) on LCD screen
    lcd_gotoxy(0, 0);
    lcd_puts("PRH");

    lcd_gotoxy(4 ,0);
    lcd_puts("00:00");
   
    lcd_gotoxy(10 ,0);
    lcd_puts("UTC+1");
  
    lcd_gotoxy(0 ,1);
    lcd_puts("LON");

    lcd_gotoxy(4 ,1);
    lcd_puts("23:00");

    lcd_gotoxy(10 ,1);
    lcd_puts("UTC+0");

    ADMUX = ADMUX | (1<<REFS0);
    // Select input channel ADC0 (voltage divider pin)
    ADMUX = ADMUX &~((1<<MUX3) | (1<< MUX2) | (1<<MUX1) | (1<<MUX0));
    // Enable ADC module
    ADCSRA |= (1<<ADEN);  
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);  
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<< ADPS1) | (1<<ADPS0);
  
   
    // Configuration of 8-bit Timer/Counter2 for Stopwatch update
    A_last_state = GPIO_read(&PINB, Astate);



    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM1_overflow_1s();
    TIM1_overflow_interrupt_enable();


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/

ISR(TIMER1_OVF_vect)
{
  // Start ADC conversion
  if (pos == 0) 
    {
      ADMUX = ADMUX |= (1<<MUX0);
      ADCSRA |= (1<<ADSC);
      ypos = ADC;
    }
    else 
    {
      ADMUX = ADMUX &= ~(1<<MUX0);
      ADCSRA |= (1<<ADSC);
      xpos = ADC;
    }

}


ISR(ADC_vect)
{
    static int mins1  = 0;
    static int mins2  = 2;
    static int hours1 = 0;
    static int hours2 = 4;
    static int minsL1 = 0;
    static int minsL2 = 0;
    static int hourL1 = 0;
    static int hourL2 = 0;

    char string[2];                 // String for converted numbers by itoa()

    if (xpos > 700) 
    {
      mins1++;
    }

    if (xpos < 300)
    {
      mins2++;
    }

    if (ypos < 300)
    { 
      hours2++;
    }

    if (ypos > 700) 
    {
      hours1++;
    }


    if (mins2 == 10)
      {
        mins1++;  
        mins2 = 0;
      }
         
    
    if (mins1 == 6) 
      {
        mins1 = 0;
        hours2++;
      }
      
          
    if (hours1 == 2)
      {
        if (hours2 == 4) 
        {
          hours1 = 0;
          hours2 = 0;
        }
      }
      else if (hours2 == 10)
      {
        hours1++;
        hours2 = 0;
      }

    if (hours1 == 2)
    {
      if (hours2 > 5)
      hours1 = 0;
    }  

    if (hours1 == 3)
      hours1 = 0;

    lcd_gotoxy(4 ,0);
    itoa (hours1, string, 10);
    lcd_puts(string);

    lcd_gotoxy(5 ,0);
     itoa (hours2, string, 10);
    lcd_puts(string);

    lcd_gotoxy(7 ,0);
     itoa (mins1, string, 10);
    lcd_puts(string);

    lcd_gotoxy(8 ,0);
     itoa (mins2, string, 10);
    lcd_puts(string);

    if (pos == 0)
      pos = 1;
    else
      pos = 0;
    
    
    hourL2 = hours2 - 1;
    hourL1 = hours1;


    if (hours2 == 0)
    {
      hourL2 = 9;
      hourL1 = hours1 - 1;
        if (hours1 == 0)
        {
          hourL1 = 2;
        }
    }


    lcd_gotoxy(4 ,1);
    itoa (hourL1, string, 10);
    lcd_puts(string);

    lcd_gotoxy(5 ,1);
    itoa (hourL2, string, 10);
    lcd_puts(string);

    lcd_gotoxy(7 ,1);
     itoa (mins1, string, 10);
    lcd_puts(string);

    lcd_gotoxy(8 ,1);
     itoa (mins2, string, 10);
    lcd_puts(string);
    
}