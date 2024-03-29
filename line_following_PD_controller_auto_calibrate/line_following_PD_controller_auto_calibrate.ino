/*
 This is for Line Follower
 using PID Controller for LinerBot
 with Auto Calibrate Sensor
 Maker Line for cytron for line sensor
 by Duokino
 */

//sensor
#define VR A0     //Potentiometer
int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;
int S5 = 0;

//Pin declaration for TB6612FNG

//Motor Right
#define PWMB 10 //Speed control
#define BIN1 12 //Direction
#define BIN2 11 //Direction

//Motor Left
#define PWMA 3 //Speed control
#define AIN1 5 //Direction
#define AIN2 4 //Direction

int mode = 0;
boolean buttonPressed = false;

int motorSpeed;
int error;
int position;

    int BaseSpeed = 120;
    float Kp = 0.06; 
    float Kd = 4; 
    float Ki = 0.000; 
    int integral = 0;
    int lastError = 0; 
    int MotorA_Speed = 0; 
    int MotorB_Speed = 0; 
    int offset = 2000;


void setup() {
  
  pinMode (VR, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
  pinMode (A5, INPUT);

  //Motor Driver Pin Setup
  pinMode (PWMB,OUTPUT);
  pinMode (BIN1,OUTPUT);
  pinMode (BIN2,OUTPUT);
  pinMode (PWMA,OUTPUT);
  pinMode (AIN1,OUTPUT);
  pinMode (AIN2,OUTPUT);

  Serial.begin (9600);

  melody();

  while (mode < 1) button();

  calibrate();

  done();

  mode = 0;
  while (mode < 1) button();
  delay(100);

}

void loop() {

  //read sensor
  S1 = digitalRead(A1);
  S2 = digitalRead(A2);
  S3 = digitalRead(A3);
  S4 = digitalRead(A4);
  S5 = digitalRead(A5);
  
  if (S1 == 0 && S2 == 0 && S3 == 1 && S4 == 0 && S5 == 0) position = 2000;
  else if (S1 == 1 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) position = 3500;
  else if (S1 == 0 && S2 == 1 && S3 == 0 && S4 == 0 && S5 == 0) position = 2500;
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 1 && S5 == 0) position = 1500;
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 1) position = 500;

  else if (S1 == 1 && S2 == 1 && S3 == 0 && S4 == 0 && S5 == 0) position = 2800;
  else if (S1 == 0 && S2 == 1 && S3 == 1 && S4 == 0 && S5 == 0) position = 2100;
  else if (S1 == 0 && S2 == 0 && S3 == 1 && S4 == 1 && S5 == 0) position = 1900;
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 1 && S5 == 1) position = 1200;

  else if (S1 == 0 && S2 == 1 && S3 == 1 && S4 == 1 && S5 == 0) position = 2000;
  else if (S1 == 1 && S2 == 1 && S3 == 1 && S4 == 0 && S5 == 0) position = 2100;
  else if (S1 == 0 && S2 == 0 && S3 == 1 && S4 == 1 && S5 == 1) position = 1900;

  if (position <= 1500){
    if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) position = 0;
    }

  else if (position >= 2500){
    if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) position = 4000;
    }

  //variable to be adjust
  //Kp = analogRead(VR)/700;
  //Serial.print("Kp = ");
  //Serial.println(Kp);

  //Kd = analogRead(VR)/700;
  //Serial.print("Kd = ");
  //Serial.println(Kd);

  //PID calculation  

  error = position - offset;
      
  motorSpeed = Kp * error + Kd * (error - lastError) + Ki * integral; 
  lastError = error;

  //Motor output

  MotorA_Speed = BaseSpeed - motorSpeed ; 
  MotorB_Speed = BaseSpeed + motorSpeed ; 
  MotorA_Speed = constrain(MotorA_Speed, 0, 255); 
  MotorB_Speed = constrain(MotorB_Speed, 0, 255);

  digitalWrite(AIN2, HIGH); 
  digitalWrite(AIN1, LOW); 
  analogWrite(PWMA, MotorA_Speed);
       
  digitalWrite(BIN2, HIGH); 
  digitalWrite(BIN1, LOW); 
  analogWrite(PWMB, MotorB_Speed);

}

void melody(){

  #define NOTE_B5   988
  #define NOTE_G5   784
  #define NOTE_A5   880
  #define NOTE_DS6  1245
  #define NOTE_CS6   1109
  
  #define BUZZER 8
  
  int melody[] = {NOTE_B5, 0, NOTE_G5, NOTE_A5, NOTE_B5, 0, NOTE_G5, NOTE_A5, NOTE_B5, 0, NOTE_B5, NOTE_B5, NOTE_DS6, NOTE_DS6, NOTE_B5, NOTE_B5, NOTE_CS6};
  int noteDurations[] = {4, 16, 8, 4, 4, 16, 8, 4, 4, 8, 4, 8, 4, 8, 4, 8, 2};
  
    for (int thisNote = 0; thisNote < 17; thisNote++){
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZZER, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
}

void button() {
  #define NOTE_C5 523
  #define NOTE_G5 784

  #define BUTTON 2
  #define BUZZER 8

  pinMode(BUTTON, INPUT_PULLUP);
  
    if (digitalRead(BUTTON) == LOW &&
        buttonPressed == false) {
      buttonPressed = true;
      mode++;
      if (mode == 1) {
        tone(BUZZER, NOTE_C5, 100);
        delay(100);
        tone(BUZZER, NOTE_G5, 100);
        delay(100);
        noTone(BUZZER);
      }
      else if (mode == 2) {
        tone(BUZZER, NOTE_G5, 100);
        delay(100);
        tone(BUZZER, NOTE_C5, 100);
        delay(100);
        noTone(BUZZER);
      }
    }

  if (buttonPressed == true) {
  buttonPressed = false;
  }
}

void calibrate(){

  int CAL = 13;         //CAL pin for Maker Line

  pinMode(CAL, OUTPUT);

  digitalWrite(CAL, LOW);
  delay(4000);
  digitalWrite(CAL, HIGH);

  left(80);
  delay(7000);
  still();

  digitalWrite(CAL, LOW);
  delay(100);
  digitalWrite(CAL, HIGH);
  delay(4000);

}

void left(int motorspeed){

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, motorspeed);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);

}

void still(){

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);

}

void done(){

  #define NOTE_C5 523
  #define NOTE_G5 784

  #define BUZZER 8

  for (int i = 0; i < 3; i++){
        tone(BUZZER, NOTE_C5, 100);
        delay(100);
        tone(BUZZER, NOTE_G5, 100);
        delay(100);
        noTone(BUZZER);
        delay(500);
  }
}

//**********best value**********\\
// Kp=0.06 Kd=4 Speed=80 Time=7.0s
// Kp=0.2 Kd=5 Speed=120 Time=5.6s
// Kp=0.06 Kd=4 Speed=120 Time=5.0s
