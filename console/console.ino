#include <LiquidCrystal.h> 


// Define move buttons
#define MOVE_LEFT 2
#define MOVE_RIGHT 3
#define MOVE_FRONT 4
#define MOVE_BACK 5

// Define rotate buttons
#define MOVE_L_ROTATE_X 6  // Rotate axis x to left
#define MOVE_R_ROTATE_X 7  // Rotate axis x to right
#define MOVE_L_ROTATE_Y 8  // Rotate axis y to left
#define MOVE_R_ROTATE_Y 9  // Rotate axis y to right
#define MOVE_L_ROTATE_Z 10 // Rotate axis z to left
#define MOVE_R_ROTATE_Z 11 // Rotate axis z to right

char BOTTON_CODE[] = {'L','R','F','B', 'A','C','D','E','F','G'};

const int RECEIVE_PIN = 8;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2); 
}


void move_left(){
  
}

void move_right(){
  
}

void move_front(){
  
}

void move_back(){
  
}

void loop() {
    printDisplay("teste", String(millis()/1000));
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char) Serial.read();

    switch(inChar){
      case MOVE_LEFT:
          move_left();
          break;
      case MOVE_RIGHT:
          move_right();
          break;
      case MOVE_FRONT:
          move_front();
          break;
      case MOVE_BACK:
          move_back();
          break;
      default:
          break;
    }
    Serial.println(inChar);
  }
}

void printDisplay(String text1, String text2){
    lcd.setCursor(0,0); 
    lcd.print(text1);
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print(text2);
}

