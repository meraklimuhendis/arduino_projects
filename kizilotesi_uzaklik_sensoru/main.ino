
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

int uzaklik = 0;

void setup() {
Serial.begin(9600);
pinMode(52, INPUT);
}

void loop() {
uzaklik = digitalRead(52);
Serial.println(uzaklik);
delay(20);
}