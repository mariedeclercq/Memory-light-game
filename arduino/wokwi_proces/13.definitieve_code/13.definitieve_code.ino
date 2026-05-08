//In deze definitieve code werd er een aanpassing gedaan rond het scherm. In de vorige fase was het niet echt duidelijk te zien op het scherm wanneer er een fout werd gemaakt. Nu zal het scherm dit wel weergeven.


int ledPinrood = 5;
int ledPingroen = 7;
int ledPinwit = 3;
int ledPingeel = 9;

int buttonPinwit = 4;
int buttonPingeel = 10;
int buttonPinrood = 6;
int buttonPingroen = 8;

int buttonPinstart = 11;

const int aantalLijst = 100; //maximum grootte van de lijst is 100
int randomLijst[aantalLijst]; // een array waarin de willekeurige kleuren worden opgeslagen
int lengte = 0; // houdt bij hoeveel kleuren er momenteel in de lijst zitten

bool vorigeKnopStatus = HIGH; //variabele om de vorige status van de startknop bij te houden, wordt gebruikt voor het detecteren van een nieuwe druk op de startknop

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

  if (lengte == 0) { //als lengte niet nul is dan slaat die heel deze if over
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
    voegToe();   // voeg een nieuwe kleur toe aan de lijst

    score+=1; // verhoog score met 1 punt

    // printen van score
    Serial.print(lengte);
    Serial.println(lengte - 1);
    Serial.print(score);
    Serial.print(",");
    Serial.println(HighScore);
  } 

  else { // als speler een fout maakt, gaat spel terug naar begin en knipperen alle leds

  if (score > HighScore) { // als huidige score hoger is dan highscore, update de highscore
    HighScore = score;     // de highscore wordt geüpdatet
  }
    // stuur foutmelding naar Processing
  Serial.println("FOUT");

  score = 0;

  Serial.print(score);
  Serial.print(",");
  Serial.println(HighScore);

  lengte = 0;

  knipperAlleLeds(); // alle leds knipperen als feedback dat speler een fout heeft gemaakt

  
}

  delay(1000);

}



// functies

void voegToe() {
  if (lengte < aantalLijst) { // zolang lengte kleiner is dan maximum grootte van de lijst, voeg een willekeurige kleur toe aan de lijst
    randomLijst[lengte] = random(0, 4); //geeft een random getal terug (0,1,2 of 3) dat overeenkomt met een kleur
    lengte += 1; //verhoog lengte met 1 zodat volgende kleur in de lijst op volgende positie wordt opgeslagen
  }
}

void speelLijstaf() {
  int i = 0; // begin bij eerste kleur in de lijst
  while (i < lengte){ // zolang i kleiner is dan lengte (hoeveel kleuren er momenteel in de lijst zitten), speel de kleuren in de lijst af
    switch(randomLijst[i]) { // switch statement die controleert welke kleur er op positie i in de lijst staat en de bijhorende led aansteekt
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
  // alle leds uitzetten na het tonen van de kleur
  digitalWrite(ledPinrood, LOW);
  digitalWrite(ledPingroen, LOW);
  digitalWrite(ledPinwit, LOW);
  digitalWrite(ledPingeel, LOW);
  delay(500);
  i += 1; // ga naar volgende kleur in de lijst
}
}


bool checkInput() { 
  int i = 0; // begin bij eerste kleur in de lijst

  while (i < lengte) { // zolang i kleiner is dan lengte (hoeveel kleuren er momenteel in de lijst zitten), controleer de input van de speler voor elke kleur in de lijst

    bool inputGedaan = false; // variabele om bij te houden of de speler al een input heeft gegeven voor de huidige kleur in de lijst

    while (!inputGedaan) { // zolang speler nog geen input heeft gegeven voor de huidige kleur, blijft deze loop draaien

      if (digitalRead(buttonPinrood) == LOW) { // als rode knop wordt ingedrukt
        digitalWrite(ledPinrood, HIGH); // zet rode led aan als feedback dat de knop is ingedrukt
        if (randomLijst[i] != 0) { // als kleur op positie i niet rood is, maakte speler een fout
          return false; // stop functie en geef false terug aan loop()
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

    i += 1; // ga naar volgende kleur in de lijst
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











//En de bijhorende Processing code: 

import processing.serial.*; //seriele bibliotheek van processing laden (om communicatie tussen arduino en processing mogelijk te maken)

Serial myPort; // seriële poort variabele

int score = 0;
int highscore = 0;
boolean foutMelding = false;
int foutTimer = 0;


void setup() {
  size(800, 500); //maakt een venster van 800 (breedte) bij 500 (hoogte) pixels

  background(0); //achtergrond zwart maken

  println(Serial.list()); //print in de console alle beschikbare seriële poorten
  
  myPort = new Serial(this, Serial.list()[0], 9600); 
// Serial.list()[0] kiest eerste com poort uit de lijst
// 9600 is de baudrate (= communicatiesnelheid) deze moet exact gelijk zijn aan: Serial.begin(9600)

  myPort.bufferUntil('\n'); // wacht met lezen totdat een newline (\n) ontvangen wordt
    textAlign(CENTER, CENTER);
}



void draw() {
  background(20); //achtergrond zwart maken

  // Titel
  fill(255);
  textSize(40);
  text("SIMON SAYS", width/2, 60);

  // Scorebord
  fill(0, 255, 0);
  textSize(35);
  text("Score: " + score, width/2, 180);

  fill(255, 215, 0);
  text("Highscore: " + highscore, width/2, 260);

  // Foutmelding tonen
  if (foutMelding) {

    fill(255, 0, 0);
    textSize(45);
    text("FOUT GEMAAKT!", width/2, 380);

    // melding verdwijnt na 2 seconden
    if (millis() - foutTimer > 2000) {
      foutMelding = false;
    }
  }
}


// Deze functie wordt automatisch uitgevoerd
// wanneer Arduino data stuurt
void serialEvent(Serial myPort) {

  String data = myPort.readStringUntil('\n');

  if (data != null) {

    data = trim(data);

    println(data);

    // Controle op foutmelding
    if (data.trim().equals("FOUT")) {
    
      foutMelding = true;
      foutTimer = millis();
    
      return;
    }

    // Controle op scoregegevens
    else if (data.contains(",")) {

      String[] waarden = split(data, ',');

      if (waarden.length == 2) {

        score = int(waarden[0]);
        highscore = int(waarden[1]);
      }
    }
  }
}

//Belangrijk om hier goed te vermelde is de seriële poort waarmee de Arduino is verbonden via de USB met de laptop.
//Het is belangrijk om goed te controleren of de Serial Monitor uitstaat want anders is deze geconnecteerd met de poort waarmee de Processing moet verbonden zijn en werkt het niet.