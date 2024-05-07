
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

const int motorPin1 = 4;
const int motorPin2 = 5;
const int hizPin = 3;

const int potPin = 0;

int pot, hiz;

void setup()
{
pinMode(hizPin, OUTPUT);
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);

digitalWrite(hizPin, 0);
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
}

void loop()
{
pot = analogRead(potPin);
hiz = map(pot, 0, 1023, 0, 255);

digitalWrite(hizPin, hiz);
delay(20);
}

