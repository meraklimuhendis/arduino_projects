
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11
//#define DHTTYPE DHT22
//#define DHTTYPE DHT21

DHT meraklimuhendis(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
Serial.println("DHT11 test!");

meraklimuhendis.begin();
}

void loop() {

delay(1000);

float h = meraklimuhendis.readHumidity();

float t = meraklimuhendis.readTemperature();

float f = meraklimuhendis.readTemperature(true);

Serial.print("Nem: ");
Serial.print(h);
Serial.println(" %");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C ");
Serial.print(f);
Serial.println(" *F");

Serial.println(" ");
}

