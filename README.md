# Capacitive Touch Delfin

Projektet er resultatet af en række eksperimenter med at lave interaktive vægdekoration med capacitive touch teknologi.

Vægdekorationen er en delfin, lavet med kobbertape, der afspiller lyde når den berøres. Den er sat op i Schön-bygningen.  

Der anvendes følgende teknologi i installationen:
- [MP3 Codec Breakout](https://www.adafruit.com/product/1381)
- Arduino Pro-Micro (Hvis du vil anvende et andet arduino board skal du læse mere nedenfor)
- Kobbertape (kan erstattes af et andet strømledende materiale)
- Speaker
- Prototyping board
- Ledninger/Jumpercables
- LM386 forstærker chip (valgfri)

Delfinen er opsat som et kredsløb der registrerer når det groundes, hvilket sker når man rører delfinen. Når dette registreres starter arduinoen afspilningen af en lydfil på mp3 breakout-boardet. Projektet kan uden problemer laves med andre strømlende materiale end kobbertape.

I projektet er der også brugt en LM386 forstærker chip, der sørger for at lyden, der afspilles af mp3 boardet lyder bedre. Denne kan udelades. Men hvis du er interesseret, kan du læse mere om, hvordan man anvender sådan en forstærker chip i [denne guide](https://github.com/DDlabAU/lm386-forstaerker-chip).

## Brug med andre arduino boards
Mp3 boardet og koden fra dette projekt kan godt bruges med et andet arduino board end en pro-micro. Hvis du gør det, er du nødt til selv at slå dit arduino board op for at finde ud hvor pins med specifik funktionalitet (f.eks. clk, miso & mosi) sidder på dit pågældende arduino board. I [adafruits guide](https://learn.adafruit.com/adafruit-vs1053-mp3-aac-ogg-midi-wav-play-and-record-codec-tutorial/simple-audio-player-wiring) kan man se hvordan opsætningen vil være med en arduino uno. 
