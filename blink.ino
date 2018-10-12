#include <Keypad.h>

// include the library code:
#include <LiquidCrystal.h>



// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char transFrom[] = {'D', '#', '0', '*', 'C', '9', '8', '7', 'B', '6', '5', '4', 'A', '3', '2', '1'};
char transTo0[] =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', ' '};
char transTo1[] =  {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
char transTo2[] =  {'1', '2', '3', '*', '4', '5', '6', '#', '7', '8', '9', '!', '0', ' '};

byte customChar0[] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte customChar1[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100
};

byte customChar2[] = {
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000
};

byte customChar3[] = {
  B00000,
  B01010,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000
};

int count = 0;
int shift = 0;
char returnChar;
int arrayLoop;
boolean escape = false;

byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.createChar(0, customChar0);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);

  
  lcd.clear();
  lcd.setCursor(0, 0);
  count = 0;
  shift = 0;
  initShift();
}

void loop() {

  char key = keypad.getKey();

  if(key) {
    setKeyPlace(count);
    if(key == '1') {
      handleShift();
    } else if(key == '2') {
        lcd.write((byte)2); 
        count++;
    } else {
        count++;
        lcd.print(translateKey(key));
    }
     
  }
}

void setKeyPlace(int c) {
    if (c >= 31) {
      lcd.setCursor(15, 1);
    } else if (c <= 15) {
      lcd.setCursor(c, 0);
  } else if(c >= 16) {
      lcd.setCursor((c - 16), 1);
  }
}

void handleShift(){
  lcd.setCursor(15, 1);
  if(shift == 0) {
    shift = 1;
    lcd.write((byte)1);
  } else if(shift == 1) {
    shift = 2;
    lcd.print("#");
  } else if(shift == 2){
    shift = 0;
    lcd.write((byte)0);
  }
  }

void initShift(){

  lcd.setCursor(15, 1);
  shift = 0;
  lcd.write((byte)0);
  lcd.setCursor(0, 0);
  
}

char translateKey (char c) {
  int aL = 0;
  escape = false;
  for(aL = 0; escape == false; aL++){
    if(transFrom[aL] == c){
      if(shift == 0){
        return transTo0[aL];
      } else if(shift == 1) {
        return transTo1[aL];
      } else if(shift == 2) {
        return transTo2[aL];
      } else {
        return '!';
      }
      escape = true;
    }
  }
}
