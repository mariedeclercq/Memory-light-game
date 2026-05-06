int buttonPinblauw = 2;
int buttonPingeel = 3;
int buttonPinrood = 4;
int buttonPingroen = 5;

int buttonPinstart = 6;

void setup() {
  pinMode(buttonPinblauw, INPUT_PULLUP);
  pinMode(buttonPingeel, INPUT_PULLUP);
  pinMode(buttonPinrood, INPUT_PULLUP);
  pinMode(buttonPingroen, INPUT_PULLUP);

  pinMode(buttonPinstart, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop() {

  if (digitalRead(buttonPinrood) == LOW) {
    Serial.println("Rode knop werkt");
    delay(500);
  }

  if (digitalRead(buttonPingroen) == LOW) {
    Serial.println("Groene knop werkt");
    delay(500);
  }

  if (digitalRead(buttonPinblauw) == LOW) {
    Serial.println("Blauwe knop werkt");
    delay(500);
  }

  if (digitalRead(buttonPingeel) == LOW) {
    Serial.println("Gele knop werkt");
    delay(500);
  }

  if (digitalRead(buttonPinstart) == LOW) {
    Serial.println("Sartknop werkt");
    delay(500);
  }
}

  