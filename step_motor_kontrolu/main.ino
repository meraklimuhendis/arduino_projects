
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

const int motorPin1 = 2;
const int motorPin2 = 3;
const int motorPin3 = 4;
const int motorPin4 = 5;

int bekleme = 15, hiz = 0, sagaDon = 0, solaDon = 0, dur = 0;

#define potPin A0
#define butonBir 8
#define butonIki 9
#define butonUc 10

void adim1() {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim2() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim3() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim4() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(bekleme);
}

void hizAyari()
{
hiz = analogRead(potPin);
hiz = map(hiz, 0, 1023, 2, 35);
bekleme = hiz;
}

void butonKontrolu()
{
if (digitalRead(butonBir) == HIGH && solaDon == 0 && sagaDon == 0)
{
delay(5);
sagaDon = 1;
}

if (digitalRead(butonUc) == HIGH && sagaDon == 0 && solaDon == 0)
{
delay(5);
solaDon = 1;
}

if (digitalRead(butonIki) == HIGH )
{
delay(5);
sagaDon = 0;
solaDon = 0;
}

}

void setup() {

pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

}

void loop() {

butonKontrolu();

if (sagaDon == 1)
{
adim4();
adim3();
adim2();
adim1();

hizAyari();
}

if (solaDon == 1)
{

adim1();
adim2();
adim3();
adim4();

hizAyari();
}

/*
for (int i = 0; i < 512; i++)
{
adim4();
adim3();
adim2();
adim1();

hizAyari();
}
*/
}

