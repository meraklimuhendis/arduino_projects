/*
  MERAKLI MÜHENDİS YOUTUBE KANALI
  
  Youtube Kanalı için - https://bit.ly/2AEP5bf
  Facebook Sayfası için - https://bit.ly/3qVqAMC
  Discord Kanalımıza GEL!  - https://bit.ly/347FlSp
  
  Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 4 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
dht11 DHT11;
int sicaklik, nem;

// OKUNABİLİR VERİLER
// SICAKLIK     - DHT11.temperature
// NEM          - DHT11.humidity
// ÇİĞ NOKTASI  - DHT11.fahrenheit()
// KELVİN       - DHT11.kelvin()
// ÇİĞ NOKTASI  - DHT11.dewPoint()


char auth[33] = "Blynk_Auth_Token";
char ssid[33] = "WiFi_Ismi";
char pass[33] = "WiFi_Sifresi";


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}


BLYNK_READ(V0) {
  DHT11.read(DHT11PIN);
  sicaklik = DHT11.temperature;
  Serial.println("Sıcaklık: " + String(sicaklik));
  
  Blynk.virtualWrite(V0, sicaklik);
}

BLYNK_READ(V1) {
  DHT11.read(DHT11PIN);
  nem = DHT11.humidity;
  Serial.println("Nem: " + String(nem));
  
  Blynk.virtualWrite(V1, nem);
}
