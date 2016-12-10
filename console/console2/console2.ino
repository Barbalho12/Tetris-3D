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
#define NUMBER_OBJECT 7

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//Tipo generico de peça 
typedef struct{
  int x = 0;
  int y = 0;
  int typeObject;
  int currentPosition[SIZE_OBJECT];
}Object;

char BOTTON_CODE[] = {'L','R','F','B', 'A','C','D','E','F','G'};

//Variavel aleatória para escolher o formato no reset
long randNumber;

//É usado para incializar os diferentes tipos
int objects[NUMBER_OBJECT][SIZE_OBJECT] =  {411,412,419,420,475,476,483,484, //[]
                                            347,348,355,356,419,420,483,484, //L
                                            347,348,355,356,411,412,475,476, //L-inv
                                            403,404,411,412,475,476,483,484, //Z
                                            411,412,419,420,467,468,483,484, //Z-inv
                                            403,404,411,412,419,420,475,476, //T
                                            291,292,355,356,419,420,483,484};//I

bool enable = true;
byte cube[512];
Object currentObject;

void setup(){
    
    Serial.begin(9600);
    lcd.begin(16, 2); 
    printDisplayLine1("Iniciando..");

    clearCube();
    resetObject();

    Timer1.initialize(1500000);
    Timer1.attachInterrupt(updateGame);

    randomSeed(analogRead(0));
}

void loop() {
    
}

bool resetObject(){
  currentObject = randomObject();
  return setObject();
}

/*Cria um objeto ramdomicmente: 0,1,2,3 */
Object randomObject(){
  randNumber = random(7);
  Object object;
  object.typeObject = randNumber;
  for(int i = 0; i < SIZE_OBJECT; i++){
     object.currentPosition[i] = objects[randNumber][i]; 
  }
  return object;
}

/**(desce toda estrutura)*/
void downAll(){
  for(int i = 64; i < 512; i++){
    if(cube[i] == 1){
      cube[i-64] = 1;
      cube[i] = 0;
    }
  }
}

/*Verifica se a camada está preenchida se sim *(desce toda estrutura), 
e executa novamente para a próxima camada*/
void verifyCompleteLayer(){
  for(int i = 0; i < 63; i++){
    if(cube[i] == 0){
      return false;
    }else if(i == 63){
      downAll();
      i=0;
    }
  }
}

void updateGame(){
  if(enable){
    if (!standardMotion()){
      verifyCompleteLayer();
      if(!resetObject()){
        printDisplayLine1("Game Over");
        enable = false;
      }else{ 
        printDisplayLine2(String(millis()/1000));
      }
    }
    sendSettings();
  }
}

bool setObject(){
  for(int i = 0; i < SIZE_OBJECT; i++){
    if(cube[currentObject.currentPosition[i]] == 0){
      cube[currentObject.currentPosition[i]] = 1;
    }else{
      return false;
    }
  }
  return true;
}

bool standardMotion(){
  int newPosition;
  for(int i = 0; i < SIZE_OBJECT; i++){
    newPosition = currentObject.currentPosition[i] - 64;
    for(int j = 0; j < SIZE_OBJECT; j++){
      if(newPosition == currentObject.currentPosition[j]){
        continue;
      }
    }
    if(!(newPosition >= 0 && cube[newPosition] == 0)){
      return false;
    }
  }
  for(int i = 0; i < SIZE_OBJECT; i++){
    newPosition = currentObject.currentPosition[i] - 64;
    cube[currentObject.currentPosition[i]] = 0;
    currentObject.currentPosition[i] = newPosition;
    cube[currentObject.currentPosition[i]] = 1;
  }
  return true;
}

void move_left(){
  if(currentObject.x > -3){
    for(int i = 0; i < SIZE_OBJECT; i++){
      int newPosition = currentObject.currentPosition[i] - 8;
      if(newPosition >= 0 && cube[newPosition] == 0){
        cube[currentObject.currentPosition[i]] = 0;
        currentObject.currentPosition[i] = newPosition;
        cube[currentObject.currentPosition[i]] = 1;
      }
    }
    currentObject.x--;
  }
}

void move_right(){
  if(currentObject.x < 3){
    for(int i = SIZE_OBJECT-1; i >= 0; i--){
      int newPosition = currentObject.currentPosition[i] + 8;
      if(newPosition >= 0 && cube[newPosition] == 0){
        cube[currentObject.currentPosition[i]] = 0;
        currentObject.currentPosition[i] = newPosition;
        cube[currentObject.currentPosition[i]] = 1;
      }
    }
    currentObject.x++;
  }
}

void move_front(){
  if(currentObject.y < 3){
    for(int i = SIZE_OBJECT-1; i >= 0; i--){
      int newPosition = currentObject.currentPosition[i] + 1;
      if(newPosition >= 0 && cube[newPosition] == 0){
        cube[currentObject.currentPosition[i]] = 0;
        currentObject.currentPosition[i] = newPosition;
        cube[currentObject.currentPosition[i]] = 1;
      }
    }
    currentObject.y++;
  }
}

void move_back(){
  if(currentObject.y > -3){
    for(int i = 0; i < SIZE_OBJECT; i++){
      int newPosition = currentObject.currentPosition[i] - 1;
      if(newPosition >= 0 && cube[newPosition] == 0){
        cube[currentObject.currentPosition[i]] = 0;
        currentObject.currentPosition[i] = newPosition;
        cube[currentObject.currentPosition[i]] = 1;
      }
    }
    currentObject.y--;
  }
  
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
          printDisplayLine1("MOVE LEFT");
          move_left();
          break;
      case MOVE_RIGHT:
          printDisplayLine1("MOVE RIGHT");
          move_right();
          break;
      case MOVE_FRONT:
          printDisplayLine1("MOVE FRONT");
          move_front();
          break;
      case MOVE_BACK:
          printDisplayLine1("MOVE BACK");
          move_back();
          break;
      case MOVE_L_ROTATE_X:
          printDisplayLine1("MOVE L ROTATE X");
          move_l_rotate_x();
          break;
      case MOVE_R_ROTATE_X:
          printDisplayLine1("MOVE R ROTATE X");
          move_r_rotate_x();
          break;
      case MOVE_L_ROTATE_Y:
          printDisplayLine1("MOVE L ROTATE Y");
          move_l_rotate_y();
          break;
      case MOVE_R_ROTATE_Y:
          printDisplayLine1("MOVE R ROTATE Y");
          move_r_rotate_y();
          break;
      case MOVE_L_ROTATE_Z:
          printDisplayLine1("MOVE L ROTATE Z");
          move_l_rotate_z();
          break;
      case MOVE_R_ROTATE_Z:
          printDisplayLine1("MOVE R ROTATE Z");
          move_r_rotate_z();
          break;
      default:
          printDisplayLine1("MOVE ERROR");
          break;
    }
  }
}

void clearCube(){
  for(int i = 0; i < 512; i++){
    cube[i] = 0;
  }
}

void sendSettings(){

  byte x = 0;
  for(int i = 0; i < 512; i++){
    if(cube[i] == 1){
      bitSet(x, i%8);
    }else{
      bitClear(x, i%8);
    }
  
    if((i%8 == 7)){
      Serial.write(x);
    }
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

