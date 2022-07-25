#include"SevenSegmentDisplay.h"

void SevenSegmentDisplay::init(int a, int b, int c, int d, int e, int f, int g, int dpPin){
    pins[0] = a,
    pins[1] = b,
    pins[2] = c,
    pins[3] = d,
    pins[4] = e,
    pins[5] = f,
    pins[6] = g,
    dp = dpPin;
    for (int x=0; x < 7; x++){
        int p = pins[x];
        pinMode(p, OUTPUT);
    }
    pinMode(dp, OUTPUT);
}

void SevenSegmentDisplay::setState(int state=LOW){
    for (int x=0; x < 7; x++){
        int p = pins[x];
        digitalWrite(p, state);   
    }    
    delay(500);
}

void SevenSegmentDisplay::writeChar(byte value){
    for (int x=0; x < 28; x++){
        if(chars[x][0] == value){
            for (int y=0; y<7; y++){
                int pin = pins[y];
                int v = chars[x][y+1];
                digitalWrite(pin, v);
            }
            break;
        }
    }
}

void SevenSegmentDisplay::writeString(String value, int delayPeriod=1500){
    int stringSize = value.length();
    byte characters[stringSize];
    for (int x=0; x<stringSize; x++){
        characters[x] = (char) value[x]; // Narrow casting characters in string variable to char array
    }
    for (int x=0; x<stringSize; x++){
        writeChar(characters[x]);
        delay(delayPeriod);
        setState();
    }
}