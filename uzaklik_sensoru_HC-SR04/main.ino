
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

const int trig = 2;
const int echo = 3;

int sure = 0;
int uzaklik = 0;

void setup() {
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

Serial.begin(9600);
}

void loop() {
digitalWrite(trig, HIGH);
delay(1);
digitalWrite(trig, LOW);

sure = pulseIn(echo, HIGH);
uzaklik = (sure / 2) / 29.1;

Serial.print("Uzaklik: ");
Serial.print(uzaklik);
Serial.println(" cm");

delay(250);
}

