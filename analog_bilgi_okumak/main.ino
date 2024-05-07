
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

int potPin=0;
int ldrPin=1;

int pot,ldr;

void setup() {
Serial.begin(9600);
}

void loop() {
pot=analogRead(potPin);
ldr=analogRead(ldrPin);

Serial.println("------------------------------------");

Serial.print("Pot Degeri = ");
Serial.println(pot);

Serial.print("LDR Degeri = ");
Serial.println(ldr);

delay(700);
}

