
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#include <SPI.h>
#include <nRF24L01p.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

nRF24L01p alici(8, 7);
/* CSN - > 8, CE -> 7 olarak belirlendi */

LiquidCrystal_I2C lcd(0x27, 16, 2);

// TANK DEĞİŞKEN TANIMLAMALARI

// MOTOR
const int solMotorIleriPin = 9;
const int solMotorGeriPin = 10;

const int sagMotorIleriPin = 3;
const int sagMotorGeriPin = 4;

const int solMotorPWMPin = 5;
const int sagMotorPWMPin = 6;

int hizDegeri = 0, yonDegeri = 0;
int hiz = 0, yon = 0;

const int buzzerPin = 2;

// DEĞERLER
String veri = " ", hizDegeriStr = " ", yonDegeriStr = " ";

void setup() {
Serial.begin(9600);
Serial.println("Merakli Muhendis Youtube Kanali");
Serial.println("ProtoTank");
Serial.println("");
delay(30);

SPI.begin();
SPI.setBitOrder(MSBFIRST);
/* SPI başlatıldı */
alici.channel(90);
alici.RXaddress("asd");
alici.init();

lcd.begin();
lcd.setBacklight(200);
lcd.setCursor(3, 0);
lcd.print("ProtoTank");
lcd.setCursor(0, 1);
lcd.print("Merakli Muhendis");

// INPUT OUTPUT AYARLARI
pinMode(buzzerPin, OUTPUT);
digitalWrite(buzzerPin, HIGH);
delay(220);
digitalWrite(buzzerPin, LOW);
delay(120);
digitalWrite(buzzerPin, HIGH);
delay(220);
digitalWrite(buzzerPin, LOW);

pinMode(solMotorPWMPin, OUTPUT);
pinMode(sagMotorPWMPin, OUTPUT);
digitalWrite(solMotorPWMPin, LOW);
digitalWrite(sagMotorPWMPin, LOW);

pinMode(solMotorIleriPin, OUTPUT);
pinMode(solMotorGeriPin, OUTPUT);
digitalWrite(solMotorIleriPin, LOW);
digitalWrite(solMotorGeriPin, LOW);

pinMode(sagMotorIleriPin, OUTPUT);
pinMode(sagMotorGeriPin, OUTPUT);
digitalWrite(sagMotorIleriPin, LOW);
digitalWrite(sagMotorGeriPin, LOW);

}

void loop() {

/*
analogWrite(solMotorPWMPin, 200);
analogWrite(sagMotorPWMPin, 200);
*/

// BİLGİLERİN ALICIDAN ALINMASI
while (alici.available()) {
// Modülden veri geldiği sürece while devam edecek
alici.read();

alici.rxPL(veri);
// Modülden gelen veri okundu

if (veri.length() > 0)
{
  //  Serial.println(veri);  // modülden gelen veri ekrana yazdırıldı

 //  x150y120b

  // Gelen veri parçalanacak
  int index1 = veri.indexOf("x");
  int index2 = veri.indexOf("y");
  int index3 = veri.indexOf("b");

  yonDegeriStr = veri.substring(index1 + 1, index2);
  yonDegeri = yonDegeriStr.toInt();

  hizDegeriStr = veri.substring(index2 + 1, index3);
  hizDegeri = hizDegeriStr.toInt();

  veri = "";  // eski veri temizlendi

  Serial.print("Hiz Degeri = ");
  Serial.print(hizDegeri);

  Serial.print("    ");

  Serial.print("Yon Degeri = ");
  Serial.println(yonDegeri);
}
}

// DURMAK İÇİN
if (hizDegeri > 120 && hizDegeri < 130 && yonDegeri > 120 && yonDegeri < 130)
{
dur();
}

// İLERİ GİTMEK İÇİN
if (hizDegeri > 130)
{
hiz = map(hizDegeri, 140, 255, 140, 255);
Serial.println(hiz);

ileri();
}

// GERİ GİTMEK İÇİN
if (hizDegeri < 120)
{
hiz = map(hizDegeri, 125, 0, 140, 255);
Serial.println(hiz);

geri();
}

// SOLA DÖNMEK İÇİN
if (yonDegeri > 130)
{
yon = map(yonDegeri, 130, 255, 140, 255);

solaDon();
}

// SAĞA DÖNMEK İÇİN
if (yonDegeri < 120)
{
yon = map(yonDegeri, 120, 0, 140, 255);

sagaDon();
}

}

void dur()
{
digitalWrite(sagMotorIleriPin, LOW);
digitalWrite(sagMotorGeriPin, LOW);

digitalWrite(solMotorIleriPin, LOW);
digitalWrite(solMotorGeriPin, LOW);

}

void ileri()
{
digitalWrite(sagMotorIleriPin, HIGH);
digitalWrite(sagMotorGeriPin, LOW);

digitalWrite(solMotorIleriPin, HIGH);
digitalWrite(solMotorGeriPin, LOW);

analogWrite(solMotorPWMPin, hiz);
analogWrite(sagMotorPWMPin, hiz);
}

void geri()
{
digitalWrite(sagMotorIleriPin, LOW);
digitalWrite(sagMotorGeriPin, HIGH);

digitalWrite(solMotorIleriPin, LOW);
digitalWrite(solMotorGeriPin, HIGH);

analogWrite(solMotorPWMPin, hiz);
analogWrite(sagMotorPWMPin, hiz);
}

void sagaDon()
{
digitalWrite(sagMotorIleriPin, LOW);
digitalWrite(sagMotorGeriPin, HIGH);

digitalWrite(solMotorIleriPin, HIGH);
digitalWrite(solMotorGeriPin, LOW);

analogWrite(solMotorPWMPin, yon);
analogWrite(sagMotorPWMPin, yon);
}

void solaDon()
{
digitalWrite(sagMotorIleriPin, HIGH);
digitalWrite(sagMotorGeriPin, LOW);

digitalWrite(solMotorIleriPin, LOW);
digitalWrite(solMotorGeriPin, HIGH);

analogWrite(solMotorPWMPin, yon);
analogWrite(sagMotorPWMPin, yon);
}

