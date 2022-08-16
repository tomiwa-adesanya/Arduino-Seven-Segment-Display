# About Seven Segment Display Device

A Seven Segment display device is an electronic display device that consists of 7 LED segements labelled from **a to g**.
The 7 LED Segments are arranged in a way to show specific decimal numerals or characters by lighting up difference combinations of the LED segments. 


## Diagram of a Seven Segement display Device

![seven-segment-device](/images/diagram.png)

  Based on the diagram of the Seven Segment display device above:
  * Pin 7 lights up the "a" LED segment.
  * Pin 6 lights up the "b" LED segment.
  * Pin 4 lights up the "c" LED segment.
  * Pin 2 lights up the "d" LED segment.
  * Pin 1 lights up the "e" LED segment.
  * Pin 9 lights up the "f" LED segment.
  * Pin 10 lights up the "g" LED segment.
  * Pin 5 lights up the "dp" LED segment.
  * Pins 3 and 8 are referred to as common(COM) pins. Either of them can be used.
  
  The LED arrangement form an figure 8 which makes it possible to display all decimal numeric characters from 0 to 9.
  To display "1" on the display device for example, simply set the digital state of pins 7 and 6 to High. 
  
 #About SevenSegmentDisplay library
  
 SevenSegmentDisplay library is an arduino library that contains a SevenSegmentDisplay class with defined methods to automate the process of writing
 characters and values to a Seven Segment display device.
  
 Methods of class include:
 * `begin(int a, int b, int c, int d, int e, int f, int g, int dpPin)` :initializes attributes of class and configures pin mode of each pin. 
  To be called in the setup() function.
 * `setState(int state=LOW)` : sets the state of all 7 LEDs to the same state. HIGH to turn all LEDs on and LOW to turn all LEDs off.
 * `createChar(byte customChar[])` : creates and stores user customised character that can be displayed on the device.
 * `writeCustomChar(byte value)` : displays stored user customised character on the device.
 * `writeChar(byte value)` : displays built-in character on the display device.
 * `writeString(String value, int delayPeriod)` : displays characters of a String value one at a time with a periodic gap between each character displayed.
  The time period/delay is specified by the delayPeriod argument.
  
 ## Getting started
  
 Required components:
  * Seven Segment display device
  * Resistor (220 Ohms)
  * Jumper wires
  * Breadboard
  * Arduino Uno

  
First of all download the [zip file](), and add it to your Arduino sketch. 
  
Within your Arduino sketch: 
 
```cpp
#include<SevenSegmentDisplay.h>

#define a 0
#define b 0
#define c 0 
#define d 0
#define e 0
#define f 0
#define g 0
#define dp 0
 
SevenSegmentDisplay device;

/*To create customised character
   --
     |
   --
     |
   --
   
   NOTE: this character is already included in the class and doesn't actually have to be redefined. This is just an example.
*/
byte custom1[] = {'3', 1, 1, 1, 1, 0, 0, 1}; 
 
void setup(){
  device.init(a, b, c, d, e, f, g, dp);
}

void loop(){
  device.writeChar('3'); // Display custom1
  delay(2500);
  device.setState(LOW); // Turns off all LED after 2.5 seconds;
  device.writeString("HELLO", 2500); // Displays characters H E L L O to device with a 2.5 seconds gap
} 
```
