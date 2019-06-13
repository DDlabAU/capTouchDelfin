//Dette er librariesne der skal bruges
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

//Dette er pin deffinitionen til mp3 breakoutboardet.
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

//Denne variabel bruges til at bugteste koden
char rx;

//Disse variabler refererer til de pins som kobberstrimlen læser
int sensorPin = 2;
int sensorValue = 0;
int controlPin = 8;

void setup() {
  Serial.begin(9600);
  SD.begin(CARDCS);
  Serial.println("Booted up");


  //Dette kode starter MP3 boardet
  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  musicPlayer.setVolume(1,1);

  //Dette kode initiererer pin 2 og 8 til at bruges som registrering af når man trykker på delfinen
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(controlPin, OUTPUT);
 }

void loop() {
  //Her læser programmet værdien på pin to. Den variabel bruges så til at tjekke om der er forbindelse
  int sensorVal = digitalRead(sensorPin);

  //Her er funktionen til hvis der er forbindelse. Læg mærke til at den søger efter en sensorVal == LOW. Det er fordi det er en pin_pullup funktion, så den kigger efter det omvendte.
  //Hvis forbindelsen ikke findes så skruer mp3 boardet lyden ned så den "slukker"
  if(sensorVal == LOW){
    digitalWrite(controlPin, HIGH);
    musicPlayer.setVolume(1,1);
    musicPlayer.playFullFile("track001.mp3");
  }else{
    digitalWrite(controlPin, LOW);
    musicPlayer.setVolume(0,0);
  }

  //Dette funktionssegment er til at debugge koden. Den er til at man kan skrive "A" i Serial monitoren, og få mp3 boardet til at spille. Dette er for at teste om lydfilen og mp3 boardet virker.
  if (Serial.available()>0) {
    rx = Serial.read();
    Serial.println ("button pressed");

    switch(rx) {
      case 'A':
        musicPlayer.playFullFile("track001.mp3");
        break;
    }
  }
}
