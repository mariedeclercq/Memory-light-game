// Zorgen dat als de knop lang wordt ingedrukt, dat er dan ook maar 1 LED aan gaat. En niet dat terwijl de knop ingedrukt wordt de LEDs random knipperen.
// Ook de knop gedebounced

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

bool vorigeKnopStatus = HIGH;

void loop() {
  bool huidigeKnopStatus = digitalRead(buttonPinstart);

  if (vorigeKnopStatus == HIGH && huidigeKnopStatus == LOW) {
    willekeurigeLED();
    while (digitalRead(buttonPinstart) == LOW) {
      delay(10);
  }
  }
  vorigeKnopStatus = huidigeKnopStatus;
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
  delay(500);
  digitalWrite(ledPinrood, LOW);
  digitalWrite(ledPingroen, LOW);
  digitalWrite(ledPinblauw, LOW);
  digitalWrite(ledPingeel, LOW);
}