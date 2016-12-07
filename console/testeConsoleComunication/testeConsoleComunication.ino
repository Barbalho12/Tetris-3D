
byte cube[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','7','8','9','.',',','+'};


//  cube[0] = 170;
//  cube[8] = 24;
//  cube[16] = 170;
//  cube[24] = 24;
//  cube[32] = 170;
//  cube[40] = 24;
//  cube[48] = 170;
//  cube[56] = 24;

byte x = 0b00011000;
byte y = 0b00011000;
byte z = 0b00000000;

//byte cube[512];

void setup() {
//  for(int i = 0; i < 512; i++){
//    cube[i] = 0;
//  }
  
  
  Serial.begin(9600);
  for(int i = 0; i < 48/8; i++){
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
     Serial.write(0);
  }
   Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   Serial.write(x);
   Serial.write(y);
   
   Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   
   Serial.write(x);
   Serial.write(y);
      Serial.write(0);
   Serial.write(0);
   Serial.write(0);
   
}


void loop() {
//    for(int i = 0; i <= 63; i++){
//      Serial.write(170);
//      Serial.write(24);
//    }
//    delay(1500);
}
