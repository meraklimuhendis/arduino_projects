
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

const int led = 13;
const int pirPin = 2;
int pirDeger;

void setup() {
pinMode(pirPin, INPUT);
pinMode(led, OUTPUT);
}

void loop() {

pirDeger = digitalRead(pirPin);
if (pirDeger == HIGH) // hareket algılandığında
{
digitalWrite(led, HIGH);
}
if (pirDeger == LOW) // hareket algılanmadığında
{
digitalWrite(led, LOW);
}
}

