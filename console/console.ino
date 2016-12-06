#include <LiquidCrystal.h> 

// Define move buttons
#define MOVE_LEFT 'L'
#define MOVE_RIGHT 'R'
#define MOVE_FRONT 'F'
#define MOVE_BACK 'B'

// Define rotate buttons
#define MOVE_L_ROTATE_X 'A'  // Rotate axis x to left
#define MOVE_R_ROTATE_X 'C'  // Rotate axis x to right
#define MOVE_L_ROTATE_Y 'D'  // Rotate axis y to left
#define MOVE_R_ROTATE_Y 'E'  // Rotate axis y to right
#define MOVE_L_ROTATE_Z 'G' // Rotate axis z to left
#define MOVE_R_ROTATE_Z 'H' // Rotate axis z to right

char BOTTON_CODE[] = {'L','R','F','B', 'A','C','D','E','F','G'};


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2); 
    printDisplayLine1("Iniciando..");
}


void move_left(){
  
}

void move_right(){
  
}

void move_front(){
  
}

void move_back(){
  
}

void move_l_rotate_x(){
  
}

void move_r_rotate_x(){
  
}

void move_l_rotate_y(){
  
}
  
void move_r_rotate_y(){
  
}

void move_l_rotate_z(){
  
}

void move_r_rotate_z(){
  
}




void loop() {
    printDisplayLine2(String(millis()/1000));
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
      case MOVE_L_ROTATE_X:
          move_l_rotate_x();
          break;
      case MOVE_R_ROTATE_X:
          move_r_rotate_x();
          break;
      case MOVE_L_ROTATE_Y:
          move_l_rotate_y();
          break;
      case MOVE_R_ROTATE_Y:
          move_r_rotate_y();
          break;
      case MOVE_L_ROTATE_Z:
          move_l_rotate_z();
          break;
      case MOVE_R_ROTATE_Z:
          move_r_rotate_z();
          break;
      default:
          break;
    }
    Serial.println(inChar);
    printDisplayLine1(String(inChar));
  }
}

void printDisplayLine1(String text){
    lcd.setCursor(0,0);
    lcd.print(text);
    for(int i = 0; i < 16-text.length(); i++){
      lcd.print(" ");
    }
}

void printDisplayLine2(String text){
    lcd.setCursor(0,1); 
    lcd.print(text);
    for(int i = 0; i < 16-text.length(); i++){
      lcd.print(" ");
    }
}

void printDisplay(String text1, String text2){
    printDisplayLine1(text1);
    printDisplayLine1(text2);
}

