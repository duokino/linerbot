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

}

void loop() {

  //read sensor
  S1 = digitalRead(A1);
  S2 = digitalRead(A2);
  S3 = digitalRead(A3);
  S4 = digitalRead(A4);
  S5 = digitalRead(A5);
  
  if (S1 == 1 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) position = 3500;
  else if (S1 == 0 && S2 == 1 && S3 == 0 && S4 == 0 && S5 == 0) position = 2500;
  else if (S1 == 0 && S2 == 0 && S3 == 1 && S4 == 0 && S5 == 0) position = 2000;
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 1 && S5 == 0) position = 1500;
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 1) position = 500;

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

//**********best value**********\\
// Kp=0.06 Kd=4 Speed=80 Time=7.0s
// Kp=0.2 Kd=5 Speed=120 Time=5.6s
// Kp=0.06 Kd=4 Speed=120 Time=5.0s
