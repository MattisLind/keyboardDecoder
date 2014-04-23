#include <Keypad.h>

const byte ROWS = 11; //eleven rows
const byte COLS = 8; //eight columns COLUMNS is active LOW outputs
char keys[ROWS][COLS] = {
  {32,   33,  34,   ']',  '[',  '_',   ':',  '-'}, 
  {'+',  41,  42,    43,   44, 'p',    ';',  '0'},
  {'\\',  49,  50,  'l',   52, 'o',    '\\',  '9'},
  {'/',  ' ', 58,   'k',  '@', 'i',   '^',  '8'},
  {64,   'm', 66,   'j',   68, 'u',    70,  '7'},
  {'>',  'n', 74,   'h',   76, 'y',    78,  '6'},
  {'.', 'b', 82,   'g',   84, 't',  0x0d,  '5'},
  {',',  'v', 90,   'f',   92, 'r',  0x1b,  '4'},
  {96,   'c', 98,   'd',  100, 'e',   102,  '3'},
  {104,  'x', 0x0a, 's', 0x7f, 'w',   110,  '2'},
  {112,  'z', 114,  'a',  9, 'q',   118,  '1'}
};

char shiftKeys[ROWS][COLS] = {
  {32,   33,  34,   '}',  '{',  '-',   '*',  '='}, 
  {'+',  41,  42,    43,   44, 'P',    '+',  '0'},
  {'|',  49,  50,  'L',   52, 'O',    '|',  ')'},
  {'?',  ' ', 58,   'K',  '|', 'I',   '~',  '('},
  {64,   'M', 66,   'J',   68, 'U',    70,  '\''},
  {'>',  'N', 74,   'H',   76, 'Y',    78,  '&'},
  {'>', 'B', 82,   'G',   84, 'T',  0x0d,  '%'},
  {'<',  'V', 90,   'F',   92, 'R',  0x1b,  '$'},
  {96,   'C', 98,   'D',  100, 'E',   102,  '#'},
  {104,  'X', 0x0a, 'S', 0x7f, 'W',   110,  '"'},
  {112,  'Z', 114,  'A',  9, 'Q',   118,  '!'}
};

char ctrlKeys[ROWS][COLS] = {
  {32,   33,  34,   27,  29,  31,   ':',  '-'}, 
  {'+',  41,  42,    43,   44,  16,    ';',  '0'},
  {28,  49,  50,   12,   52,  15,     28,  '9'},
  {'/',  ' ', 58,    11,   0,   9,    30,  '8'},
  {64,    13, 66,    10,   68,  21,    70,  '7'},
  {'>',   14, 74,    8,   76,  25,    78,  '6'},
  {'.',   2, 82,     7,   84,  20,  0x0d,  '5'},
  {',',   22, 90,    6,   92,  18,  0x1b,  '4'},
  {96,    3, 98,     4,  100,   5,   102,  '3'},
  {104,  24 , 0x0a,  19, 0x7f,  23,   110,  '2'},
  {112,  26 , 114,   1,  9,  17,   118,  '1'}
};


byte rowPins[ROWS] = {10, 11, 12, 13, 14, 15, 16, 17, 18,19,23}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {0, 1, 2, 3, 4, 5, 6, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, 21, makeKeymap(shiftKeys), 22, makeKeymap(ctrlKeys));

void setup(){
  Serial.begin(9600);
  DDRA = B11111111;
  PORTA= B00000000;
  pinMode (20, INPUT_PULLUP);
}

void loop(){
  char key = keypad.getKey();
  if (key != NO_KEY){
    if (!digitalRead(20)) {
      Serial.print("Key ");
      Serial.print(key, DEC);
      Serial.print(" ");
      if (key>31) Serial.write(key);
      Serial.println("");
    }
    key =  ~key;  // Is it active low or active high?
    key = key & 0x7F;
    PORTA = key;
    delay(1);
    digitalWrite(31,1);
    digitalWrite(31,0);
  }
}


