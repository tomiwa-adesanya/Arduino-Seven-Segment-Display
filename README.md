# About Seven Segment Display Device

A Seven Segment display device is an electronic display device that consists of 7 LED segements labelled from **a to g**.
The 7 LED Segments are arranged in a way to show specific decimal numerals or characters by lighting up difference combinations of the LED segments. 


## Diagram of a Seven Segement display Device

![seven-segment-device](/data/images/diagram.png)

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
  
# About SevenSegmentDisplay library
  
SevenSegmentDisplay library is an arduino library that contains a SevenSegmentDisplay class with defined methods to automate the process of writing characters and values to a Seven Segment display device.

SevenSegmentDisplay comes with 28 predefined characters that can be displayed on a Seven Segment device without having to customise them yourself

    The predefined characters that can be displayed include: 

        Decimal numerals: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

        Alphabets(case-sensitive): A, b, C, d, E, F, H, I, J, L, n, O, P, q, r, S, t, U
  
SevenSegmentDisplay object methods include:
* `init(int a, int b, int c, int d, int e, int f, int g, int dpPin)` initializes attributes of class and configures pin mode of each pin. To be called in the setup() function.
* `setState(int state=LOW)` sets state all pins of the Seven Segment device to the same value. Value can either be LOW(0) or HIGH(1). 
* `createCustomChar(byte customCharacters[])` Creates user customised character that can be displayed on a Seven Segment Display device.

  Custom char is assigned a character(e.g 'v','+', e.t.c) or an int (e.g 1, 10, e.t.c) which is placed at index 0 of customCharacters[] passed as argument.
  
  The assigned character is used to refer to the customised character in the .writeCustomChar() method to display character on the device.
  
  byte array should be of length 8, with the remaining 7 values(index 1 to 7) as the state value (0 or 1) to be written to each of the seven segments (a to g) respectively.
* `writeCustomChar(byte value)` Displays customised character to device using the value assigned to the customised character.
* `writeChar(byte value)` displays a single character on device. This method is implemented by the writeString method to display multiple characters.
* `writeString(String value, int delayPeriod)` Displays each character in string value one at a time with a delay period inbetween each charcter displayed. 

  Note that there is a limit to the characters that can be displayed by a seven segment display device, for example it'd be impossible to display alphabet 'K'
  
## Getting started
  
Required components:
  * Seven Segment display device
  * Resistor (220 Ohms)
  * Jumper wires
  * Breadboard
  * Arduino Uno

  
First of all download the [zip file](), and install it with an Arduino IDE. Navigate to [how to install arduino libraries](#how-to-install-an-arduino-library-in-arduino-ide) to learn how to do so.

Within your Arduino sketch: 
 
```cpp
#include<SevenSegmentDisplay.h>

/*
  variables a - g, and dp should be replaced by their following pin values
*/

#define a 0 
#define b 0
#define c 0 
#define d 0
#define e 0
#define f 0
#define g 0
#define dp 0
 
SevenSegmentDisplay device;

/*
  To create customised character '-'
*/
byte custom1[] = {'-', 0, 0, 0, 0, 0, 0, 1}; 
 
void setup(){
  device.init(a, b, c, d, e, f, g, dp);
}

void loop(){
  device.writeChar('-'); // Display custom1
  delay(2500);
  device.setState(LOW); // Turns off all LED after 2.5 seconds;
  device.writeString("HELLO", 2500); // Displays characters H E L L O to device with a 2.5 seconds gap
  delay(2500);
  device.setState(LOW);
  delay(2500);
} 
```

## How to install an Arduino library in Arduino IDE

Step 1: 

![in your Arduino IDE toolbar click Sketch](/data/images/installation-step1.png)

Step 2:

![select add "Include Library" the "add .zip Library"](/data/images/installation-step2.png)

Step 3:

![navigate to library directory, select library and click "open"](/data/images/installation-step3.png)