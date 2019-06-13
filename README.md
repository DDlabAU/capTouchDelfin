# Capacitive Touch Delfin

Projektet er resultatet af en række eksperminenter med at lave interaktive vægdekoration med capacitive touch teknologi.

Vægdekorationen er en delfin, lavet med kobbertape, der afspiller lyde når den berøres. Den er sat op i Schön-bygningen.  

Der anvendes følgende teknologi i installationen:
- MP3 Codec Breakout
- Arduino Pro-Micro (kan erstattes af andre arduino boards)
- Kobbertape (kan erstattes af et andet strømledende materiale)
- Speaker
- Prototyping board
- Ledninger/Jumpercables
- LM386 forstærker chip (valgfri)

Delfinen er opsat som et kredsløb der registrerer når det groundes, hvilket sker når man rører delfinen. Når dette registreres starter arduinoen afspilningen af en lydfil på mp3 breakout-boardet. Projektet kan uden problemer laves med andre strømlende materiale end kobbertape.

I projektet er der også brugt en LM386 forstærker chip, der sørger for at lyden, der afspilles af mp3 boardet lyder bedre. Denne kan udelades. Men hvis du er interesseret, kan du læse mere om, hvordan man anvender sådan en forstærker chip i [denne guide](https://github.com/DDlabAU/lm386-forstaerker-chip).
