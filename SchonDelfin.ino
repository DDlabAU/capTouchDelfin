// Dette er bibliotekerne der skal bruges
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// Dette er pin-definitionerne til mp3 breakoutboardet.
#define CLK 15
#define MISO 14
#define MOSI 16
#define BREAKOUT_RESET 6
#define BREAKOUT_CS 5
#define BREAKOUT_DCS 9
#define CARDCS 10
#define DREQ 3

Adafruit_VS1053_FilePlayer musicPlayer =
  Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);

// Denne variabel bruges til at debugge
char rx;

// Her deklarerer og initialiserer vi de variabler vi bruger til at aflæse kobberstrimlen
int sensorPin = 2;
bool sensorValue = HIGH;
// Her deklarerer og initialiserer vi en variabel vi kan bruge til at signalere status
int statusPin = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial connection begun");
  SD.begin(CARDCS);
  Serial.println("SD Card loaded");

  // Dette kode forsøger at starte MP3 boardet og sætter derefter volumen
  // Lykkedes det ikke at starte boardet vil koden gå ind i en uendelig while-løkke og ikke fortsætte herfra
  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println("Music player begun");
  musicPlayer.setVolume(1,1);

  // Her sætter vi pinMode
  // Vi bruger sensorPin som et input med en indbygget pullup-modstand. Vi kan bruge den til at aflæse en værdi, der som udgangspunkt vil være HIGH og bliver LOW når sensorPin groundes
  // Vi bruger statusPin som et output som vi kan signalere med
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(statusPin, OUTPUT);
 }

void loop() {
  // Her læser programmet værdien på pin to. Den variabel bruges så til at tjekke om der er forbindelse
  sensorVal = digitalRead(sensorPin);

  // Her er funktionen til hvis der er forbindelse mellem kobberstrimlen og en persen. Læg mærke til at den reagerer når sensorVal == LOW. Det er fordi vi har sat vores pinMode til INPUT_PULLUP på den pin, hvor vi har fobundet kobberstrimlen, hvilket betyder at logikken er omvendt.
  // Hvis der ikke findes en forbindelse skruer mp3 boardet lyden ned så den "slukker"
  if (sensorVal == LOW) {
    digitalWrite(statusPin, HIGH);
    Serial.println("Playing file");
    musicPlayer.setVolume(1,1);
    musicPlayer.playFullFile("track001.mp3");
  } else {
    digitalWrite(statusPin, LOW);
    musicPlayer.setVolume(0,0);
  }

  // Dette funktionssegment er til at debugge koden. Den er til at man kan skrive "A" i Serielmonitoren, og få mp3 boardet til at spille. Dette er for at teste om lydfilen og mp3 boardet virker.
  if (Serial.available() > 0) {
    rx = Serial.read();
    Serial.println("Input received");

    switch (rx) {
      case 'A':
        Serial.println("Playing file");
        musicPlayer.playFullFile("track001.mp3");
        break;
    }
  }
}
