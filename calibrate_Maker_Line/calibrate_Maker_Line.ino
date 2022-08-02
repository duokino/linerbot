/*
 This is for calibrating Maker Line Sensor
 for LinerBot using TB6612FNG for motor driver
 by Duokino
 */

//Pin declaration for TB6612FNG

//Motor Right
int PWMB = 10; //Speed control
int BIN1 = 12; //Direction
int BIN2 = 11; //Direction

//Motor Left
int PWMA = 3; //Speed control
int AIN1 = 5; //Direction
int AIN2 = 4; //Direction

//Pin declaration for Maker Line sensor

int LeftSen = A1;
int LeftMSen = A2;
int MidSen = A3;
int RightMSen = A4;
int RightSen = A5;

int mode = 0;
boolean buttonPressed = false;

void setup() {

  Serial.begin(9600);       //Enable Serial Communications
  
  //Maker Line Auto-Calibrating Line Sensor Pin Setup
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

  //Motor Driver Pin Setup
  pinMode(PWMB,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);

  while (mode < 2) button();

  calibrate();

}

void loop() {

  done();

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

        tone(BUZZER, NOTE_C5, 100);
        delay(100);
        tone(BUZZER, NOTE_G5, 100);
        delay(100);
        noTone(BUZZER);
        delay(1000);
  
}
