
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

int butonPin = 2;

int xPin = 0;
int yPin = 1;

int buton, x, y;

void setup() {

Serial.begin(9600);
pinMode(butonPin, INPUT);

}

void loop() {

x = analogRead(xPin);
y = analogRead(yPin);

buton = digitalRead(butonPin);

if (buton == 0) // butona basıldığında
{
digitalWrite(13, HIGH);
Serial.println("Buton'a Basildi.");
}
if (buton == 1) // buton basılmadığında
{
digitalWrite(13, LOW);
Serial.println("Buton'a Basilmadi.");
}

Serial.print("X Ekseni = ");
Serial.println(x);

Serial.print("Y Ekseni= ");
Serial.println(y);

Serial.println("-------------------------------------");

delay(1000);

}

