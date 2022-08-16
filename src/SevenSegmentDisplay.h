#ifndef SevenSegmentDisplay_H
#define SevenSegmentDisplay_H

class SevenSegmentDisplay{
    private:
    int customisedCharsSize = 0;
    int customisedChars[15][8]; // Array to store customised character with a limit of 15 customised characters
    int pins[7];
    int dp; 
    byte chars[28][8] = {
        //{'v', a, b, c, d, e, f, g} // Format: v --> value
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
    void begin(int a, int b, int c, int d, int e, int f, int g, int dpPin);
    void setState(int state=LOW);
    void createChar(byte customCharacters[]);
    void writeCustomChar(byte value);
    void writeChar(byte value);
    void writeString(String value, int delayPeriod=1500);
};

#endif