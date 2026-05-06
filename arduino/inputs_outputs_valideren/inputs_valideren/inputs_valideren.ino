int buttonPinwit = 4;
int buttonPingeel = 10;
int buttonPinrood = 6;
int buttonPingroen = 8;

int buttonPinstart = 11;

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

  