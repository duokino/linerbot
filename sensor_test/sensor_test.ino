/*
This is for sensor test
for Line Sensor LSS05 or Maker Line
and Edge Sensor using Maker Reflect
for LinerBot
by Duokino
 */

int VR = A0;

int Button = 2;

int LeftSen = A1;
int LeftMSen = A2;
int MidSen = A3;
int RightMSen = A4;
int RightSen = A5;

int EdgeL = A6;
int EdgeR = A7;

void setup() {

  pinMode(Button, INPUT_PULLUP);

  Serial.begin(9600); // set the data rate in bits per second for serial data transmission

  melody();

}

void loop() {
  
  Serial.print("LeftSen:");
  Serial.print(digitalRead(LeftSen));
  Serial.print("  LeftMid:");
  Serial.print(digitalRead(LeftMSen));
  Serial.print("  Mid:");
  Serial.print(digitalRead(MidSen));
  Serial.print("  RightMid:");
  Serial.print(digitalRead(RightMSen));
  Serial.print("  RightSen:");
  Serial.print(digitalRead(RightSen));
  Serial.print("    Edge_L:");
  Serial.print(analogRead(EdgeL));
  Serial.print("  Edge_R:");
  Serial.print(analogRead(EdgeR));
  Serial.print("    VR:");
  Serial.print(analogRead(VR));
  Serial.print("    Button:");
  Serial.println(digitalRead(Button));
  delay(200);

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
