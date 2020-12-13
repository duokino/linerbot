/*
 This is for Bluetooth Module RC
 for LinerBot
 Install Arduino Bluetooth RC Car
 from PlayStore in Android phone
 by Duokino
 */

char t;

//Motor Right
int PWMB = 10; //Speed control
int BIN1 = 12; //Direction
int BIN2 = 11; //Direction

//Motor Left
int PWMA = 3; //Speed control
int AIN1 = 5; //Direction
int AIN2 = 4; //Direction

//Slipp  percentage between Right Motor and Left Motor
int slipp = 6;     //use align_motor_speed.ino to find this value


void setup() {

  //motor setup
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  //sensor setup using Maker Line
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  Serial.begin(9600);
  
  melody();

}

void loop() {

  int VR, motorspeed;
  int rightmotor, leftmotor;
  
  VR = analogRead(A0);
  motorspeed = map(VR, 0, 1023, 0, 255);
  
  rightmotor = motorspeed;
  leftmotor = rightmotor - (slipp * 0.003 * motorspeed);
  
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
   
  if(t == 'F'){            //move forward
    forward(rightmotor, leftmotor);
  }
   
  else if(t == 'B'){      //move reverse
    backward(rightmotor, leftmotor);
  }
   
  else if(t == 'L'){      //turn right
    left(motorspeed);
  }
   
  else if(t == 'R'){      //turn left
    right(motorspeed);
  }
  
  else if(t == 'S'){      //STOP (all motors stop)
    still();
  }
  //delay(100);

}

void forward(int rightmotor, int leftmotor){

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, rightmotor);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, leftmotor);

}

void backward(int rightmotor, int leftmotor){

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, rightmotor);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, leftmotor);

}

void right(int motorspeed){

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, motorspeed);

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
