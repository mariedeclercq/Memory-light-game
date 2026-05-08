// werkende code voor simon says spel met 4 leds en 4 knoppen
// je moet ook niet meer op de startknop drukken als je een level hoger gaat, dat gaat vanzelf als je de juiste knoppen indrukt
// Dit is een variatie op de vorige code met een scorebord in verwerkt. Dit bord werd gerealiseerd en geprogrammeerd via Processing.
// Bij een juiste uitvoering stijgt de score met 1 punt, bij een fout reset deze weer op nul. Ook wordt de highscore bijgehouden. 



int ledPinrood = 5;
int ledPingroen = 7;
int ledPinwit = 3;
int ledPingeel = 9;

int buttonPinwit = 4;
int buttonPingeel = 10;
int buttonPinrood = 6;
int buttonPingroen = 8;

int buttonPinstart = 11;

const int aantalLijst = 100;
int randomLijst[aantalLijst];
int lengte = 0;

bool vorigeKnopStatus = HIGH;

int score = 0;
int HighScore = 0;

void setup() {
  pinMode(ledPinrood, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinwit, OUTPUT);
  pinMode(ledPingeel, OUTPUT);

  pinMode(buttonPinwit, INPUT_PULLUP);
  pinMode(buttonPingeel, INPUT_PULLUP);
  pinMode(buttonPinrood, INPUT_PULLUP);
  pinMode(buttonPingroen, INPUT_PULLUP);

  pinMode(buttonPinstart, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  Serial.begin(9600);
}


void loop() {

  if (lengte == 0) { //als lengte niet nul is dan slaat die heel deze if else over
    if(digitalRead(buttonPinstart) == LOW){ // start spel alleen als lengte 0 is en startknop wordt gedrukt
      delay(300); // debounce
      voegToe(); 
    } 
  else {
      return; // begin de loop terug van begin stop dus met deze doorloop
    }
  }
  
  speelLijstaf(); // led(s) branden

  if (checkInput() == true) { // als speler juiste knoppen indrukt gaat spel verder
    delay(500);
    voegToe();   

    score+=1;

    // printen van score
    Serial.print(lengte);
    Serial.println(lengte - 1);
    Serial.print(score);
    Serial.print(",");
    Serial.println(HighScore);
  } 

  else { 

  if (score > HighScore) {
    HighScore = score;
  }

  lengte = 0;
  score = 0;

  knipperAlleLeds();

  
}

  delay(1000);

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
        digitalWrite(ledPinwit, LOW);
        digitalWrite(ledPingeel, LOW);
        break;
      case 1:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, HIGH);
        digitalWrite(ledPinwit, LOW);
        digitalWrite(ledPingeel, LOW);
        break;
      case 2:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinwit, HIGH);
        digitalWrite(ledPingeel, LOW);
        break;
      case 3:
        digitalWrite(ledPinrood, LOW);
        digitalWrite(ledPingroen, LOW);
        digitalWrite(ledPinwit, LOW);
        digitalWrite(ledPingeel, HIGH);
        break;
    }
  delay(500);
  digitalWrite(ledPinrood, LOW);
  digitalWrite(ledPingroen, LOW);
  digitalWrite(ledPinwit, LOW);
  digitalWrite(ledPingeel, LOW);
  delay(500);
  i += 1;
}
}


bool checkInput() {
  int i = 0;

  while (i < lengte) {

    bool inputGedaan = false;

    while (!inputGedaan) {

      if (digitalRead(buttonPinrood) == LOW) {
        digitalWrite(ledPinrood, HIGH);
        if (randomLijst[i] != 0) {
          return false;
        }
        inputGedaan = true;
        delay(300);
        digitalWrite(ledPinrood, LOW);
      }

      if (digitalRead(buttonPingroen) == LOW) {
        digitalWrite(ledPingroen, HIGH);
        if (randomLijst[i] != 1) {
          return false;
        }
        inputGedaan = true;
        delay(300);
        digitalWrite(ledPingroen, LOW);
      }

      if (digitalRead(buttonPinwit) == LOW) {
        digitalWrite(ledPinwit, HIGH);
        if (randomLijst[i] != 2) {
          return false;
        }
        inputGedaan = true;
        delay(300);
        digitalWrite(ledPinwit, LOW);
      }

      if (digitalRead(buttonPingeel) == LOW) {
        digitalWrite(ledPingeel, HIGH);
        if (randomLijst[i] != 3) {
          return false;
        }
        inputGedaan = true;
        delay(300);
        digitalWrite(ledPingeel, LOW);
      }

    }

    i += 1;
  }

  return true;
}

void knipperAlleLeds() { // als speler een fout maakt stopt het spel en knipperen alle leds drie keer

  int i = 0;

  while (i < 3) {

    digitalWrite(ledPinrood, HIGH);
    digitalWrite(ledPingroen, HIGH);
    digitalWrite(ledPinwit, HIGH);
    digitalWrite(ledPingeel, HIGH);

    delay(500);

    digitalWrite(ledPinrood, LOW);
    digitalWrite(ledPingroen, LOW);
    digitalWrite(ledPinwit, LOW);
    digitalWrite(ledPingeel, LOW);

    delay(500);

    i += 1;
  }
}


//Onderstaande code is deze uit de Processing

import processing.serial.*; //seriele bibliotheek van processing laden (om communicatie tussen arduino en processing mogelijk te maken)

Serial myPort; // seriële poort variabele

int score = 0;
int highScore = 0;

void setup() {
  size(400, 200); //maakt een venster van 400 (breedte) bij 200 (hoogte) pixels

  println(Serial.list()); //print in de console alle beschikbare seriële poorten
  
  myPort = new Serial(this, Serial.list()[0], 9600); 
// Serial.list()[0] kiest eerste com poort uit de lijst
// 9600 is de baudrate (= communicatiesnelheid) deze moet exact gelijk zijn aan: Serial.begin(9600)

  myPort.bufferUntil('\n'); // wacht met lezen totdat een newline (\n) ontvangen wordt
}

void draw() {
  background(0); //achtergrond zwart maken

  fill(255); //tekst wit maken
  textSize(28); //tekstgrootte instellen

  text("Simon Says", 20, 40); //tekst "Simon Says" op het scherm zetten op positie (20, 40)
  text("Score: " + score, 20, 90); //tekst "Score: " gevolgd door de huidige score op het scherm zetten op positie (20, 90)
  text("Highscore: " + highScore, 20, 130); //tekst "Highscore: " gevolgd door de highscore op het scherm zetten op positie (20, 130)
}

void serialEvent(Serial myPort) { // functie wordt automatisch uitgevoerd wanneer nieuwe data binnenkomt via de seriële poort

  String data = myPort.readStringUntil('\n'); // leest de binnenkomende data als een string tot aan de newline (\n)

  if (data != null) { // controleert of er daadwerkelijk data is ontvangen
    data = trim(data); // verwijdert spaties, enters en verborgen tekens aan het begin en einde van de string

    if (data.indexOf(',') > -1) {  // controleert of er een komma aanwezig is
    // indexOf(',') geeft de positie van de komma terug, als er geen komma is gevonden geeft die -1 terug, dus als deze groter is dan -1 betekent dit dat er een komma aanwezig is in de string

      String[] values = split(data, ','); // splitst de string met de komma als scheidingsteken

      if (values.length == 2) { // zijn er precies 2 delen na het splitsen (score en highscore)
        try { // probeert de tekst om te zetten naar gehele getallen
          score = int(values[0]);
          highScore = int(values[1]);
        } 
        catch (Exception e) { // als er een fout optreedt bij het omzetten van de tekst naar getallen, wordt deze catch-blok uitgevoerd
          println("Foute data ontvangen: " + data); // print foutmelding + de ontvangen data
        }
      }
      //try = probeer deze code uit te voeren, als er een fout optreedt ga dan naar catch
    }
  }
}

//Belangrijk om hier goed te vermelde is de seriële poort waarmee de Arduino is verbonden via de USB met de laptop.
//Het is belangrijk om goed te controleren of de Serial Monitor uitstaat want anders is deze geconnecteerd met de poort waarmee de Processing moet verbonden zijn en werkt het niet.