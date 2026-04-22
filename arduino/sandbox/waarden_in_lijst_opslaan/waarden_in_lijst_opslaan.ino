// De laatste 10 waarden (0 of 1tjes) worden opgeslaan in een lijst.
// Ik deed het met twee leds om het even gemakkelijk uit te testen. (zie foto bij images van opstelling in wokwi: Wokwi_schema_leds_test_lijst.png)

int ledPingroen = 8;
int ledPinblauw = 9;

const int aantalLijst = 10;
int randomLijst[aantalLijst];
int index = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinblauw, OUTPUT);

  randomSeed(analogRead(A0));

  Serial.begin(9600);

}

void loop() {
  willekeurigeLED();
  printLijst();
}

void willekeurigeLED() {
  int willekeurigGetal = random(0, 2);

  randomLijst[index] = willekeurigGetal;
  index = (index + 1) % aantalLijst;

    switch(willekeurigGetal) {
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
}

void printLijst() {
  Serial.print("Lijst: ");

  for (int i = 0; i < aantalLijst; i++) {
    Serial.print(randomLijst[i]);
    Serial.print(" ");
  }

  Serial.println();
}