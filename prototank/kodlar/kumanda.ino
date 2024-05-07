
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#include <SPI.h>
#include <nRF24L01p.h>
#include <String.h>

nRF24L01p verici(8, 7);
/* CSN - > 8, CE -> 7 olarak belirlendi */

String veri = "";

// KUMANDA DEĞİŞKEN TANIMLAMALARI
const int joystickXpin = A0;
const int joystickYpin = A1;

// BUTONLAR

// DEGERLER
int joystickX = 0;
int joystickY = 0;
String joystickXstr = "";
String joystickYstr = "";

void setup() {
Serial.begin(9600);
Serial.println("Merakli Muhendis Youtube Kanali");
Serial.println("ProtoTank");
Serial.println("");
delay(30);

SPI.begin();
SPI.setBitOrder(MSBFIRST);
/* SPI başlatıldı */
verici.channel(90);
verici.TXaddress("asd");
verici.init();
}

void loop() {

joystickX = map(analogRead(joystickXpin), 0, 1023, 0, 255);
joystickY = map(analogRead(joystickYpin), 0, 1023, 255, 0);
joystickXstr = String(joystickX);
joystickYstr = String(joystickY);

// TÜM VERİLERİN TOPLANMASI
veri = "x" + joystickXstr + "y" + joystickYstr + "b"; // a,b,c,d gibi harfler ile ayrılarak da yapılabilir

// x150y120b

// YAZDIRMA
verici.txPL(veri);
Serial.println(veri);

boolean gonderimDurumu = verici.send(FAST);

// Eğer gönderim başarısız olursa gonderimDurumu'nun değeri false olacaktır
if (gonderimDurumu == true) {
Serial.println("mesaj gonderildi");
} else {
Serial.println("mesaj gonderilemedi");
}

delay(100);

}

