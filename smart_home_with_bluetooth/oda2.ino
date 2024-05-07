 
#include <idDHT11.h>


int idDHT11pin = 2; //Digital pin for comunications
int idDHT11intNumber = 0; //interrupt number (must be the one that use the previus defined pin (see table above)

// Lib instantiate
idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);

/*
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  // Çiğ Oluşma Noktası, Dew Point
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);
*/
void dht11_wrapper() {
  DHT11.isrCallback();
}
void sicaklikKontrolu()
{
  if (veri == "oda2sicaklik" && islem == 1)
  {
    int result = DHT11.acquireAndWait();
    Serial.print("Oda 2'deki Sicaklik (Celcius): ");
    Serial.println(DHT11.getCelsius(), 2);
    islem=0;
  }
  if (veri == "oda2nem" && islem == 1)
  {
    int result = DHT11.acquireAndWait();
    Serial.print("Oda 2'deki Nem (%): ");
    Serial.println(DHT11.getHumidity(), 2);
    islem=0;
  }
}


// Bağlantılar
const int priz2Pin = 26;
const int priz3Pin = 27;
// const int yangin1Pin = 51; // dijital giriş olarak ayarlanacak


void oda2Kur()
{
  pinMode(priz2Pin, OUTPUT);
  pinMode(priz3Pin, OUTPUT);
  DHT11.isrCallback();
  // pinMode(yangin1Pin, INPUT);

}


void oda2Calis()
{
  
  //Serial.println(DHT11.getCelsius(), 2);
  // 2. PRİZ KONTROLÜ
  if (veri == "priz2ac" && islem == 1)
  {
    digitalWrite(priz2Pin, HIGH);
    Serial.println("2. Odadaki Sag Priz Acildi.");
    islem = 0;
    delay(50);
  }
  if (veri == "priz2kapat" && islem == 1)
  {
    digitalWrite(priz2Pin, LOW);
    Serial.println("2. Odadaki Sag Priz Kapatildi.");
    islem = 0;
    delay(50);
  }
  // 2. PRİZ KONTROLÜ



  // 3. PRİZ KONTROLÜ
  if (veri == "priz3ac" && islem == 1)
  {
    digitalWrite(priz3Pin, HIGH);
    Serial.println("2. Odadaki Sol Priz Acildi.");
    islem = 0;
    delay(50);
  }
  if (veri == "priz3kapa" && islem == 1)
  {
    digitalWrite(priz3Pin, LOW);
    Serial.println("2. Odadaki Sol Priz Kapatildi.");
    islem = 0;
    delay(50);
  }
  // 3. PRİZ KONTROLÜ


}

