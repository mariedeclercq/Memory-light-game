[Wokwi_schema](./images/Wokwi_schema_v1.png)

int buttonPinwit = 4;
int buttonPingeel = 10;
int buttonPinrood = 6;
int buttonPingroen = 8;

int buttonPinstart = 11;

void setup() {
  pinMode(buttonPinwit, INPUT_PULLUP);
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

  if (digitalRead(buttonPinwit) == LOW) {
    Serial.println("Witte knop werkt");
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

  