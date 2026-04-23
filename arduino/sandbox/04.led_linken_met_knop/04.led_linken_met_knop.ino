int ledPinrood = 8;
int ledPingroen = 9;
int ledPinblauw = 10;
int ledPingeel = 11;

int buttonPinblauw = 2;
int buttonPingeel = 3;
int buttonPinrood = 4;
int buttonPingroen = 5;

int buttonPinstart = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinrood, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinblauw, OUTPUT);
  pinMode(ledPingeel, OUTPUT);

  pinMode(buttonPinblauw, INPUT_PULLUP);
  pinMode(buttonPingeel, INPUT_PULLUP);
  pinMode(buttonPinrood, INPUT_PULLUP);
  pinMode(buttonPingroen, INPUT_PULLUP);

  pinMode(buttonPinstart, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPinrood) == LOW){
  digitalWrite(ledPinrood, HIGH);
}

if(digitalRead(buttonPingroen) == LOW){
  digitalWrite(ledPingroen, HIGH);
}

if(digitalRead(buttonPinblauw) == LOW){
  digitalWrite(ledPinblauw, HIGH);
}

if(digitalRead(buttonPingeel) == LOW){
  digitalWrite(ledPingeel, HIGH);
}
}