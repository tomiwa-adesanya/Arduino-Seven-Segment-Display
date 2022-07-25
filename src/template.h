class SevenSegmentDisplay{
    public:
    int pins[7];
    int dp;
    byte chars[28][8] {
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
    void begin(int a, int b, int c, int d, int e, int f, int g, int dpPin){
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
    void setState(int state=LOW){
        for (int x=0; x < 7; x++){
            int p = pins[x];
            digitalWrite(p, state);
        }
        delay(500);
    }
    void writeChar(byte value){
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
    void writeString(String value, int delayPeriod=1500){
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
};