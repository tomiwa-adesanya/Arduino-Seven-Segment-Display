#ifndef SevenSegmentDisplay_H
#define SevenSegmentDisplay_H

/* 
    SevenSegmentDisplay comes with 28 predefined characters that can be displayed on a Seven Segment device without having to customise them yourself
    The predefined characters are: 
        Decimal numerals: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        Alphabets(case-sensitive): A, b, C, d, E, F, H, I, J, L, n, O, P, q, r, S, t, U
*/

class SevenSegmentDisplay{
    private:
    int customisedCharsSize = 0;
    int pins[7];
    int dp; 
    byte customisedChars[15][8]; // Array to store customised character with a limit of 15 customised characters
    byte chars[28][8] = {
        //{'v', a, b, c, d, e, f, g} // Format: v is the ASCII equivalence of specified character. e.g 'A' would be stored as 65
        {'0', 1, 1, 1, 1, 1, 1, 0}, // 0 
        {'1', 0, 1, 1, 0, 0, 0, 0}, // 1
        {'2', 1, 1, 0, 1, 1, 0, 1}, // 2
        {'3', 1, 1, 1, 1, 0, 0, 1}, // 3 
        {'4', 0, 1, 1, 0, 0, 1, 1}, // 4   
        {'5', 1, 0, 1, 1, 0, 1, 1}, // 5  
        {'6', 1, 0, 1, 1, 1, 1, 1}, // 6
        {'7', 1, 1, 1, 0, 0, 0, 0}, // 7      
        {'8', 1, 1, 1, 1, 1, 1, 1}, // 8
        {'9', 1, 1, 1, 0, 0, 1, 1}, // 9    
        {'A', 1, 1, 1, 0, 1, 1, 1}, // 10 
        {'b', 0, 0, 1, 1, 1, 1, 1}, // 11
        {'C', 1, 0, 0, 1, 1, 1, 0}, // 12  
        {'d', 0, 1, 1, 1, 1, 0, 1}, // 13 
        {'E', 1, 0, 0, 1, 1, 1, 1}, // 14  
        {'F', 1, 0, 0, 0, 1, 1, 1}, // 15      
        {'H', 0, 1, 1, 0, 1, 1, 1}, // 16                  
        {'I', 0, 1, 1, 0, 0, 0, 0}, // 17    
        {'J', 0, 1, 1, 1, 1, 0, 0}, // 18  
        {'L', 0, 0, 0, 1, 1, 1, 0}, // 19
        {'n', 0, 0, 1, 0, 1, 0, 1}, // 20  
        {'O', 1, 1, 1, 1, 1, 1 ,0}, // 21
        {'P', 1, 1, 0, 0, 1, 1, 1}, // 22  
        {'q', 1, 1, 1, 0, 0, 1, 1}, // 23
        {'r', 1, 0, 0, 1, 1, 1, 0}, // 24  
        {'S', 1, 0, 1, 1, 0, 1, 1}, // 25  
        {'t', 0, 0, 0, 1, 1, 1, 1}, // 26  
        {'U', 0, 1, 1, 1, 1, 1, 0}, // 27  
    };
    
    public:
    void init(int a, int b, int c, int d, int e, int f, int g, int dpPin);
    void setState(int state=LOW);
    void writeChar(byte value);
    void writeString(String value, int delayPeriod=1500);
    void createCustomChar(byte customCharacters[]);
    void writeCustomChar(byte value);
};


// SevenSegmentDisplay methods definition

void SevenSegmentDisplay::init(int a, int b, int c, int d, int e, int f, int g, int dpPin){
    // initializes attributes of class and configures pin mode of each pin. 
    // To be called in the setup() function
    pins[0] = a,
    pins[1] = b,
    pins[2] = c,
    pins[3] = d,
    pins[4] = e,
    pins[5] = f,
    pins[6] = g,
    this->dp = dpPin; // datapoint pin
    for (int x=0; x < 7; x++){
        int p = pins[x];
        pinMode(p, OUTPUT);
    }
    pinMode(dp, OUTPUT);
}

void SevenSegmentDisplay::setState(int state){
    // sets state all pins of the Seven Segment device to the same value. Value can either be LOW(0) or HIGH(1)
    for (int x=0; x < 7; x++){
        int p = pins[x];
        digitalWrite(p, state);   
    }    
    delay(500);
}

void SevenSegmentDisplay::writeChar(byte value){
    // displays a single character on device. 
    // This method is implemented by the writeString method to display multiple characters
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

void SevenSegmentDisplay::writeString(String value, int delayPeriod){
    // Displays each character in string value one at a time with a delay period inbetween each charcter displayed
    // Note that there is a limit to the characters that can be displayed by a seven segment display device, for example it'd be impossible to display alphabet 'K'
    int stringSize = value.length(); // number of characters in string value
    byte characters[stringSize];
    for (int x=0; x<stringSize; x++){
        characters[x] = (char) value[x]; // Narrow casting characters in string variable to byte array of character ASCII equivalence
    }
    for (int x=0; x<stringSize; x++){
        writeChar(characters[x]);
        delay(delayPeriod);
        setState();
    }
}

void SevenSegmentDisplay::createCustomChar(byte customCharacters[]){
    /*
     Creates user customised character that can be displayed on a Seven Segment Display device
     Custom char is assigned a character(e.g 'v','+', e.t.c) or an int (e.g 1, 10, e.t.c)
     The assigned character is used to refer to the customised character in the .writeCustomChar() method to display character on the device.
     The assigned character should be first on the byte array passed as argument.
     byte array should be of length 8, with the remaining 7 values as the state value (0 or 1) to be written to each of the seven segments (a to g) respectively
    */ 
    for (int index=0; index < 8; index++){
        this->customisedChars[this->customisedCharsSize][index] = customCharacters[index]; 
    }
    this->customisedCharsSize++;
}

void SevenSegmentDisplay::writeCustomChar(byte value){
    // Displays customised character to device using the value assigned to the character
    for (int i=0; i<this->customisedCharsSize; i++){
        if(this->customisedChars[i][0] == value){
            for (int index=0; index<7; index++){
                int pin = pins[index];
                int v = this->customisedChars[i][index+1];
                digitalWrite(pin, v);
            }
            break;
        }
    }
}

#endif