
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

/*
BAĞLANTILAR ŞU ŞEKİLDE

Servolar 2, 3, 4, 5 dijital pinlerine bağlanacak.
Joystick'ler 0, 1, 2, 3 analog pinlerine bağlanacak.
*/
#include<Servo.h>

Servo servobir;
Servo servoiki;
Servo servouc;
Servo servodort;

int deger1,deger2,deger3,deger4;

const int j1=0;
const int j2=1;
const int j3=2;
const int j4=3;

void setup()
{
servobir.attach(2);
servoiki.attach(3);
servouc.attach(4);
servodort.attach(5);
}

void loop()
{
deger1=analogRead(j1);
deger1=map(deger1,0,1023,0,179);
deger2=analogRead(j2);
deger2=map(deger2,0,1023,0,179);
deger3=analogRead(j3);
deger3=map(deger3,0,1023,0,179);
deger4=analogRead(j4);
deger4=map(deger4,0,1023,0,179);

servobir.write(deger1);
servoiki.write(deger2);
servouc.write(deger3);
servodort.write(deger4);

}

