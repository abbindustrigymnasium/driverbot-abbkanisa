#define motorPinRightDir  0//D2 // definar variabeln man använder för att byta direction åt höger.
#define motorPinRightSpeed 5//D1 // definar snabbhet för right direction.
#define motorPinLeftDir 2 //definar variabeln man använder för att byta direction åt vänster
#define motorPinLeftSpeed 4 //definar snabbhet för left direction.

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  pinMode(motorPinLeftDir, OUTPUT);
  pinMode(motorPinLeftSpeed, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int speed = 1024;
  int dir = 0;

  delay(2200);
     digitalWrite(motorPinRightDir, dir);
      analogWrite(motorPinRightSpeed, speed);
      delay(2200);
      digitalWrite(motorPinLeftDir, 1);
      analogWrite(motorPinLeftSpeed, speed);

 /*Drivetest3(motorPinLeftDir, motorPinLeftSpeed);
  Drivetest3(motorPinRightDir, motorPinRightSpeed);*/
}


void Drivetest(int Dirpin, int Speedpin) {

  DriveDirSpeed(Dirpin, Speedpin, 0, 1020);
  delay(2200);
  DriveDirSpeed(Dirpin, Speedpin, 1, 1020);

}


void Drivetest2(int Dirpin, int Speedpin) {

  int Speed = 0;
  while (Speed < 1020)
  {
    Speed += 100;
    DriveDirSpeed(Dirpin, Speedpin, 0, Speed);
    delay(2200);
  }

}

void Drivetest3(int Dirpin, int Speedpin) {

  int Direction = 0;
  while (Direction <= 1)
  {
    int Speed = 0;
    while (Speed < 1020)
    {
      Speed += 100;
      DriveDirSpeed(Dirpin, Speedpin, Direction, Speed);
      delay(2200);
    }
    Direction++;
  }

}


void DriveDirSpeed(int Dirpin, int Speedpin, int Direction, int Speed) {
  if (Direction == 1)
    Serial.println("Framåt");
  else
    Serial.println("Bakåt");

  Serial.println("Hastighet: " + String(Speed));

  digitalWrite(Dirpin, Direction);
  analogWrite(Speedpin, Speed);
}
