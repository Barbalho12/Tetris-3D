// Define move buttons
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5

// Define rotate buttons
#define L_ROTATE_X 6  // Rotate axis x to left
#define R_ROTATE_X 7  // Rotate axis x to right
#define L_ROTATE_Y 8  // Rotate axis y to left
#define R_ROTATE_Y 9  // Rotate axis y to right
#define L_ROTATE_Z 10 // Rotate axis z to left
#define R_ROTATE_Z 11 // Rotate axis z to right


void setup() {
  Serial.begin(9600);

  // Setting move buttons
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(FRONT, INPUT);
  pinMode(BACK, INPUT);

  // Setting rotate buttons
  pinMode(L_ROTATE_X, INPUT);
  pinMode(R_ROTATE_X, INPUT);
  pinMode(L_ROTATE_Y, INPUT);
  pinMode(R_ROTATE_Y, INPUT);
  pinMode(L_ROTATE_Z, INPUT);
  pinMode(R_ROTATE_Z, INPUT);
}

void loop() {
  // Reading move buttons signals
  int left = digitalRead(LEFT);
  int right = digitalRead(RIGHT);
  int front = digitalRead(FRONT);
  int back = digitalRead(BACK);

  // Reading rotate buttons signals
  int l_rotate_x = digitalRead(L_ROTATE_X);
  int r_rotate_x = digitalRead(R_ROTATE_X);
  int l_rotate_y = digitalRead(L_ROTATE_Y);
  int r_rotate_y = digitalRead(R_ROTATE_Y);
  int l_rotate_z = digitalRead(L_ROTATE_Z);
  int r_rotate_z = digitalRead(R_ROTATE_Z);
  
  if(left == 0){
    Serial.println("LEFT");
    delay(250);
  }

  if(right == 0){
    Serial.println("RIGHT");
    delay(250);
  }
  
  if(front == 0){
    Serial.println("FRONT");
    delay(250);
  }

  if(back == 0){
    Serial.println("BACK");
    delay(250);
  }

  if(l_rotate_x == 0){
    Serial.println("ROTATION: X-LEFT");
    delay(250);
  }

  if(r_rotate_x == 0){
    Serial.println("ROTATION: X-RIGHT");
    delay(250);
  }

  if(l_rotate_y == 0){
    Serial.println("ROTATION: Y-LEFT");
    delay(250);
  }

  if(r_rotate_y == 0){
    Serial.println("ROTATION: Y-RIGHT");
    delay(250);
  }

  if(l_rotate_z == 0){
    Serial.println("ROTATION: Z-LEFT");
    delay(250);
  }

  if(r_rotate_z == 0){
    Serial.println("ROTATION: Z-RIGHT");
    delay(250);
  }
}
