
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

include <Servo.h>
int servoPals = 2;
int pot = 0;
Servo servoKontrol;
int deger = 0;

void setup() {

servoKontrol.attach(servoPals); // Hangi uçtan bağlantı yapıldığı

}

void loop() {

deger = analogRead(pot);
deger = map(deger, 0, 1023, 0, 179);

servoKontrol.write(deger);
delay(15);

}

