// Pinnen definiëren
int ledPinblauw = 9;
int ledPingroen = 8;
int knopBlauw = 4;
int knopGroen = 3;
int knopZwartStart = 2; // De nieuwe startknop

// Variabelen voor het spel
int randomLijst[100]; // De lijst bedraagt maximaal 100 waardes
int lengte = 0;
const int aantalLijst = 100;
bool vorigeStartStatus = HIGH;
bool foutGemaakt = false;

// De Arduino laten lezen wat de in-en outputs zijn
void setup() {
  Serial.begin(9600);
  pinMode(ledPinblauw, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(knopBlauw, INPUT_PULLUP);
  pinMode(knopGroen, INPUT_PULLUP);
  pinMode(knopZwartStart, INPUT_PULLUP);
  
  randomSeed(analogRead(A0)); // Voor willekeur zodat de Arduino steeds een andere 'route' aflegt
}

void loop() {
  bool huidigeStartStatus = digitalRead(knopZwartStart); //Druk op de zwarte knop om de loop te starten

  // Alleen als de ZWARTE knop wordt ingedrukt
  if (vorigeStartStatus == HIGH && huidigeStartStatus == LOW){ //ervoor was de knop nog niet ingedrukt, nu wel
    delay(50);
    voegToe();
    speelLijstaf();
    printLijst();
    checkInput(); 
  }
  vorigeStartStatus = huidigeStartStatus;
  if (lengte == 0 && foutGemaakt == true) {
  foutGemaakt = false; //Nog een fout gemaakt
  vorigeStartStatus = HIGH;
} //Deze stand wordt opgeslagen en is bij de volgende loop de vorige.
}

void voegToe() { //In deze stap wordt een cijfer random gekozen en in de lijst opgeslagen
  if (lengte < aantalLijst) {
    randomLijst[lengte] = random(0, 2); // 0 = blauw, 1 = groen, arduino kiest een random getal
    lengte += 1;
  }
}

void speelLijstaf() {
  int i = 0;
  while (i < lengte){
    switch(randomLijst[i]) { //Kijk naar de waarde op plek i
      case 0: //Stel gekozen waarde is 0
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinblauw, HIGH);
        break;
      case 1: //Stel gekozen waarde is 1
        digitalWrite(ledPingroen, HIGH);
        digitalWrite(ledPinblauw, LOW);
        break;
    }
  delay(500);

  digitalWrite(ledPingroen, LOW);
  digitalWrite(ledPinblauw, LOW);
  //Beide LED's weer uit

  delay(500);
  i += 1;
  }
}

void checkInput() {
  int i = 0;

  while (i < lengte && !foutGemaakt) {

    bool gekozen = false;

    while (!gekozen && !foutGemaakt) { //Er is nog geen keuze gemaakt en dus ook geen fout

      // Check Blauwe Knop
      if (digitalRead(knopBlauw) == LOW) { //De blauwe knop is ingedrukt
        handelKeuze(0, i, gekozen, foutGemaakt);
        delay(150);
      }

      // Check Groene Knop
      else if (digitalRead(knopGroen) == LOW) {
        handelKeuze(1, i, gekozen, foutGemaakt);
        delay(150);
      }
    }

    i += 1;
  }

  if (!foutGemaakt) {
    Serial.println("Ronde gehaald! Druk weer op zwart.");
  }
}

void handleKeuze(int kleur, int index, bool &gekozen, bool &foutGemaakt) { //Deze functie verbetert de input
  if (randomLijst[index] == kleur) {

    // Juiste LED aan
    if (kleur == 0) {
      digitalWrite(ledPinblauw, HIGH);
    } else {
      digitalWrite(ledPingroen, HIGH);
    }

    delay(200);

    // LEDs uit
    digitalWrite(ledPinblauw, LOW);
    digitalWrite(ledPingroen, LOW);

    gekozen = true;

    // Wachten tot knop losgelaten wordt
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

    // Fout-signaal
int i = 0;

while (i < 3) {
  digitalWrite(ledPinblauw, HIGH);
  digitalWrite(ledPingroen, HIGH);
  delay(100); //LED's knipperen 3 keer
  digitalWrite(ledPinblauw, LOW);
  digitalWrite(ledPingroen, LOW);
  delay(100); //LED's gaan uit

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
