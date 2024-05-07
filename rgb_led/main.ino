
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

int kirmizi = 9;
int yesil = 10;
int mavi = 11;

void setup() {
pinMode(kirmizi, OUTPUT);
pinMode(mavi, OUTPUT);
pinMode(yesil, OUTPUT);

}

void loop() {

// KIRMIZI
digitalWrite(kirmizi, HIGH);
digitalWrite(mavi, LOW);
digitalWrite(yesil, LOW);
delay(500);

// MAVİ
digitalWrite(kirmizi, LOW);
digitalWrite(mavi, HIGH);
digitalWrite(yesil, LOW);
delay(500);

// YEŞİL
digitalWrite(kirmizi, LOW);
digitalWrite(mavi, LOW);
digitalWrite(yesil, HIGH);
delay(500);
}

