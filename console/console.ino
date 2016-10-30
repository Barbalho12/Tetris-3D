#include <LiquidCrystal.h> 
#include <IRremote.h>

#define MOVE_LEFT     0x8c22657a
#define MOVE_RIGHT    0x8c22657b
#define MOVE_FRONT    0x8c22657c
#define MOVE_BACK     0x8c22657d

const int RECEIVE_PIN = 8;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
IRrecv irrecv(RECEIVE_PIN);
decode_results results;

void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2); 
    irrecv.enableIRIn(); // Start the receiver
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
    verifyIrReciever();
}


void verifyIrReciever(){
    if (irrecv.decode(&results)) {

      unsigned long  value = results.value;

      switch(value){
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

      

      //TESTE
      String valueText(value, HEX);
      if(valueText != "FFFFFFFF" && valueText != "ffffffff"){
          Serial.println(valueText);
      }
      /////

      
      
      irrecv.resume(); // Receive the next value
    }
}

void printDisplay(String text1, String text2){
    lcd.setCursor(0,0); 
    lcd.print(text1);
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print(text2);
}

