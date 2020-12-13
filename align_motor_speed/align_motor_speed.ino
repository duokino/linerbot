/*
  This is for align motor
  between Right Motor and
  Left Motor
  for LinerBot
  by Duokino
 */

//Potentiometer A0

//Motor Right
int PWMB = 10; //Speed control
int BIN1 = 12; //Direction
int BIN2 = 11; //Direction

//Motor Left
int PWMA = 3; //Speed control
int AIN1 = 5; //Direction
int AIN2 = 4; //Direction

//Motor Maximum Speed
int motorspeed = 150;

void setup(){

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  Serial.begin(9600);
  
  melody();

}

void loop(){

  int VR, slipp;
  int rightmotor, leftmotor;
  
  VR = analogRead(A0);
  slipp = map(VR, 0, 1023, 0, 50);
  
  Serial.print("Slip percentage: ");
  Serial.print(slipp);
  Serial.println("%");
  
  rightmotor = motorspeed;
  leftmotor = rightmotor - (slipp * 0.003 * motorspeed);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, rightmotor);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, leftmotor);

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
