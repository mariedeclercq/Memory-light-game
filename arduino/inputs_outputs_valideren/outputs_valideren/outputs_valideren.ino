int ledPinrood = 5;
int ledPingroen = 7;
int ledPinwit = 3;
int ledPingeel = 9;


void setup() {
  pinMode(ledPinrood, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinblauw, OUTPUT);
  pinMode(ledPingeel, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  digitalWrite(ledPinrood, HIGH);
  Serial.println("LED rood aan");
  delay(1000);
  digitalWrite(ledPinrood, LOW);
  delay(1000);

  digitalWrite(ledPingroen, HIGH);
  Serial.println("LED groen aan");
  delay(1000);
  digitalWrite(ledPingroen, LOW);
  delay(1000);

  digitalWrite(ledPinblauw, HIGH);
  Serial.println("LED blauw aan");
  delay(1000);
  digitalWrite(ledPinblauw, LOW);
  delay(1000);

  digitalWrite(ledPingeel, HIGH);
  Serial.println("LED geel aan");
  delay(1000);
  digitalWrite(ledPingeel, LOW);
  delay(1000);
}
