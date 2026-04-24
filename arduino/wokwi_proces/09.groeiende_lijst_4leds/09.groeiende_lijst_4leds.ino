int ledPinrood = 8;
int ledPingroen = 9;
int ledPinblauw = 10;
int ledPingeel = 11;

int buttonPinblauw = 2;
int buttonPingeel = 3;
int buttonPinrood = 4;
int buttonPingroen = 5;

int buttonPinstart = 6;

const int aantalLijst = 100;
int randomLijst[aantalLijst];
int lengte = 0;


void setup() {
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

  Serial.begin(9600);
}

bool vorigeKnopStatus = HIGH;

void loop() {
  bool huidigeKnopStatus = digitalRead(buttonPinstart);

  if (vorigeKnopStatus == HIGH && huidigeKnopStatus == LOW) {
    voegToe();
    speelLijstaf();
    printLijst();
    while (digitalRead(buttonPinstart) == LOW){
      delay(10);
    }
  }
  vorigeKnopStatus = huidigeKnopStatus;
}



// functies

void voegToe() {
  if (lengte < aantalLijst) {
    randomLijst[lengte] = random(0, 4);
    lengte += 1;
  }
}

void speelLijstaf() {
  int i = 0;
  while (i < lengte){
    switch(randomLijst[i]) {
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
  delay(500);
  i += 1;
}
}

void printLijst() {
  Serial.print("Lijst: ");

  int i = 0;

  while (i < lengte) {
    Serial.print(randomLijst[i]);
    Serial.print(" ");
    i += 1;
}

  Serial.println();
}