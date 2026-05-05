// Pinnen definiëren
int ledPinblauw = 9;
int ledPingroen = 8;
int knopBlauw = 4;
int knopGroen = 3;
int knopZwartStart = 2;

// Variabelen voor het spel
int randomLijst[100];
int lengte = 0;
const int aantalLijst = 100;
bool vorigeStartStatus = HIGH;
bool foutGemaakt = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPinblauw, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(knopBlauw, INPUT_PULLUP);
  pinMode(knopGroen, INPUT_PULLUP);
  pinMode(knopZwartStart, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

void loop() {
  bool huidigeStartStatus = digitalRead(knopZwartStart);

  if (vorigeStartStatus == HIGH && huidigeStartStatus == LOW) {
    delay(50);
    voegToe();
    speelLijstaf();
    printLijst();
    checkInput();
  }

  vorigeStartStatus = huidigeStartStatus;

  if (lengte == 0 && foutGemaakt == true) {
    foutGemaakt = false;
    vorigeStartStatus = HIGH;
  }
}

void voegToe() {
  if (lengte < aantalLijst) {
    randomLijst[lengte] = random(0, 2);
    lengte += 1;
  }
}

void speelLijstaf() {
  int i = 0;
  while (i < lengte) {

    switch (randomLijst[i]) {
      case 0:
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, HIGH);
        break;

      case 1:
        digitalWrite(ledPingroen, HIGH);// Pinnen definiëren
int ledPinblauw = 9;
int ledPingroen = 8;
int knopBlauw = 4;
int knopGroen = 3;
int knopZwartStart = 2;

// Variabelen voor het spel
int randomLijst[100];
int lengte = 0;
const int aantalLijst = 100;
bool vorigeStartStatus = HIGH;
bool foutGemaakt = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPinblauw, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(knopBlauw, INPUT_PULLUP);
  pinMode(knopGroen, INPUT_PULLUP);
  pinMode(knopZwartStart, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

void loop() {
  bool huidigeStartStatus = digitalRead(knopZwartStart);

  if (vorigeStartStatus == HIGH && huidigeStartStatus == LOW) {
    delay(50);
    voegToe();
    speelLijstaf();
    printLijst();
    checkInput();
  }

  vorigeStartStatus = huidigeStartStatus;

  if (lengte == 0 && foutGemaakt == true) {
    foutGemaakt = false;
    vorigeStartStatus = HIGH;
  }
}

void voegToe() {
  if (lengte < aantalLijst) {
    randomLijst[lengte] = random(0, 2);
    lengte += 1;
  }
}

void speelLijstaf() {
  int i = 0;
  while (i < lengte) {

    switch (randomLijst[i]) {
      case 0:
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, HIGH);
        break;

      case 1:
        digitalWrite(ledPingroen, HIGH);
        digitalWrite(ledPinblauw, LOW);
        break;
    }

    delay(500);

    digitalWrite(ledPingroen, LOW);
    digitalWrite(ledPinblauw, LOW);

    delay(500);
    i += 1;
  }
}

void checkInput() {
  int i = 0;

  while (i < lengte && !foutGemaakt) {

    bool gekozen = false;

    while (!gekozen && !foutGemaakt) {

      if (digitalRead(knopBlauw) == LOW) {
        handleKeuze(0, i, gekozen, foutGemaakt);  // FIX
        delay(150);
      }

      else if (digitalRead(knopGroen) == LOW) {
        handleKeuze(1, i, gekozen, foutGemaakt);  // FIX
        delay(150);
      }
    }

    i += 1;
  }

  if (!foutGemaakt) {
    Serial.println("Ronde gehaald! Druk weer op zwart.");
  }
}

void handleKeuze(int kleur, int index, bool &gekozen, bool &foutGemaakt) {

  if (randomLijst[index] == kleur) {

    if (kleur == 0) digitalWrite(ledPinblauw, HIGH);
    else digitalWrite(ledPingroen, HIGH);

    delay(200);

    digitalWrite(ledPinblauw, LOW);
    digitalWrite(ledPingroen, LOW);

    gekozen = true;

    if (kleur == 0) {
      while (digitalRead(knopBlauw) == LOW);
    } else {
      while (digitalRead(knopGroen) == LOW);
    }

  } else {

    Serial.println("FOUT! Start opnieuw.");
    lengte = 0;
    gekozen = true;
    foutGemaakt = true;

    int i = 0;
    while (i < 3) {
      digitalWrite(ledPinblauw, HIGH);
      digitalWrite(ledPingroen, HIGH);
      delay(100);
      digitalWrite(ledPinblauw, LOW);
      digitalWrite(ledPingroen, LOW);
      delay(100);
      i += 1;
    }
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
        digitalWrite(ledPinblauw, LOW);
        break;
    }

    delay(500);

    digitalWrite(ledPingroen, LOW);
    digitalWrite(ledPinblauw, LOW);

    delay(500);
    i += 1;
  }
}

void checkInput() {
  int i = 0;

  while (i < lengte && !foutGemaakt) {

    bool gekozen = false;

    while (!gekozen && !foutGemaakt) {

      if (digitalRead(knopBlauw) == LOW) {
        handleKeuze(0, i, gekozen, foutGemaakt);  // FIX
        delay(150);
      }

      else if (digitalRead(knopGroen) == LOW) {
        handleKeuze(1, i, gekozen, foutGemaakt);  // FIX
        delay(150);
      }
    }

    i += 1;
  }

  if (!foutGemaakt) {
    Serial.println("Ronde gehaald! Druk weer op zwart.");
  }
}

void handleKeuze(int kleur, int index, bool &gekozen, bool &foutGemaakt) {

  if (randomLijst[index] == kleur) {

    if (kleur == 0) digitalWrite(ledPinblauw, HIGH);
    else digitalWrite(ledPingroen, HIGH);

    delay(200);

    digitalWrite(ledPinblauw, LOW);
    digitalWrite(ledPingroen, LOW);

    gekozen = true;

    if (kleur == 0) {
      while (digitalRead(knopBlauw) == LOW);
    } else {
      while (digitalRead(knopGroen) == LOW);
    }

  } else {

    Serial.println("FOUT! Start opnieuw.");
    lengte = 0;
    gekozen = true;
    foutGemaakt = true;

    int i = 0;
    while (i < 3) {
      digitalWrite(ledPinblauw, HIGH);
      digitalWrite(ledPingroen, HIGH);
      delay(100);
      digitalWrite(ledPinblauw, LOW);
      digitalWrite(ledPingroen, LOW);
      delay(100);
      i += 1;
    }
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