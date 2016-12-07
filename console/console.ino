#include <LiquidCrystal.h> 
#include "TimerOne.h"

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
#define SIZE_OBJECT 8

char BOTTON_CODE[] = {'L','R','F','B', 'A','C','D','E','F','G'};

byte cube[512];

int objectCube[] = {411,412,419,420,475,476,483,484};

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){

  
    Serial.begin(9600);
    lcd.begin(16, 2); 
    printDisplayLine1("Iniciando..");

    clearCube();
    setObject(objectCube);
    sendSettings();

    Timer1.initialize(1500000);
    Timer1.attachInterrupt(updateGame);
}

void loop() {
    
}

void updateGame(){
  printDisplayLine2(String(millis()/1000));

  if (standardMotion(objectCube)){
    //Fazer alguma coisa
  }else{
    printDisplayLine1("You Lose!");
    clearCube();
  }
  sendSettings();
}

bool setObject(int object[]){
  for(int i = 0; i < SIZE_OBJECT; i++){
    if(cube[object[i]] == 0){
      cube[object[i]] = 1;
    }else{
      return false;
    }
  }
  return true;
}

bool standardMotion(int object[]){
  //int sizeObject = sizeof(object)/sizeof(int); //FORMA DINÂMICA
  for(int i = 0; i < SIZE_OBJECT; i++){
    int newPosition = object[i] - 64;
    if(newPosition >= 0 && cube[newPosition] == 0){
      cube[object[i]] = 0;
      object[i] = newPosition;
      cube[object[i]] = 1;
    }else{
      return false;
    }
  }
  return true;
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
    //Serial.println(inChar);
    printDisplayLine1(String(inChar));
  }
}

void clearCube(){
  for(int i = 0; i < 512; i++){
    cube[i] = 0;
  }
}

void sendSettings(){
  for(int i = 0; i < 512; i++){
    Serial.write(cube[i]);
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

