// ik wil dat de leds pas beginnen te knipperen als ik op de startknop druk
// maar nu moet ik op de startknop blijven drukken om de leds te laten knipperen, dit is niet de bedoeling
// ik wil dat vanaf de startknop is ingedrukt geweest, de leds beginnen te knipperen

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

  randomSeed(analogRead(A0));
}


void loop() {
  // put your main code here, to run repeatedly:
  bool startknopwaarde = digitalRead(buttonPinstart);
  if(startknopwaarde == LOW){
    willekeurigeLED();
    delay(500);
  }
}



// functies

void willekeurigeLED() {
  int willekeurigGetal = random(0, 4);
    switch(willekeurigGetal) {
      case 0:
        digitalWrite(ledPinrood, HIGH);
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, LOW);
        digitalWrite(ledPingeel, LOW);
        break;
      case 1:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, HIGH);
        digitalWrite(ledPinblauw, LOW);
        digitalWrite(ledPingeel, LOW);
        break;
      case 2:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, HIGH);
        digitalWrite(ledPingeel, LOW);
        break;
      case 3:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, LOW);
        digitalWrite(ledPingeel, HIGH);
        break;
    }
}