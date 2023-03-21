// Distance between the two photoresistors = 0.04m
// analogRead takes 100ms to occur
// Took 16ms to reach steady state



void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  Serial.begin(115200);

}

double startt, endt, speedl, ttime;
double dist = 0.04;
double previousT = 0;

void loop() {
  //Serial.println(analogRead(A1));
  if (analogRead(A0) < 700){
    startt = millis();
  }
  if (analogRead(A1) < 660){
    endt = millis();
    ttime = endt - startt;
    speedl = dist / ttime * 1000;
    Serial.println(speedl);
  }
  }
