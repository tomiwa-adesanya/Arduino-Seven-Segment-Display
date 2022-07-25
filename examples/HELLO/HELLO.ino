#include<SevenSegmentDisplay.h>

#define a 11
#define b 10
#define c 5
#define d 6
#define e 7
#define f 12
#define g 13
#define dp 4

/*
    Change the defined values (a, b, c, d, e, f, g, dp) to the respective arduino pins onto which the Seven segment display device pins (a, b, c, d, e, f, g, and dp) are connected to 
*/


SevenSegmentDisplay device;

void setup(){
    device.begin(
        a, b, c, d, e, f, g, dp
    )
}

void loop(){
    String info="HELLO"; // String to display on the Seven Segment display device
    device.writeString(info); // Use the .writeChar(char value) method to write a single char
}