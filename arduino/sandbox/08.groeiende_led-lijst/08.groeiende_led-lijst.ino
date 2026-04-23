//Nu we al een lijst hebben die groeit, kunnen we deze ook afspelen. We maken een functie die de lijst afspeelt. 
//We voegde in de opstelling ook een knop toe om een signaal te hebben wanneer we een nieuw element aan de lijst toevoegen. (zie foto: Wokwi_schema_leds_test_lijst_v2.png)

int ledPingroen = 8;
int ledPinblauw = 9;

int buttonPin = 2;

const int aantalLijst = 100;
int randomLijst[aantalLijst];
int lengte = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinblauw, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  Serial.begin(9600);

}

bool vorigeKnopStatus = HIGH;

void loop() {
  bool huidigeKnopStatus = digitalRead(buttonPin);

  if (vorigeKnopStatus == HIGH && huidigeKnopStatus == LOW) {
    voegToe();
    speelLijstaf();
    printLijst();
  }
  vorigeKnopStatus = huidigeKnopStatus;
}

void voegToe() {
  if (lengte < aantalLijst) {
    randomLijst[lengte] = random(0, 2);
    lengte += 1;
  }
}

void speelLijstaf() {
int i = 0;
while (i < lengte){
    switch(randomLijst[i]) {
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