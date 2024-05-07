
int denePin = 13;
int i = 0;
int priz1;
int yangin1Deger;



// Bağlantılar
const int priz1Pin = 23;
const int yangin1Pin = 24; // dijital giriş olarak ayarlanacak
const int buzzerPin = 25;


//Başlangıçta Buzzer sinyal sesi versin.
boolean sinyal = false;
void buzzerSinyal()
{
  
  for (i; i < 6; i++)
  {
    sinyal = !sinyal;
    digitalWrite(buzzerPin, sinyal);
    delay(100);
  }
  /*
  delay(150);
  for (i; i < 10; i++)
  {
    sinyal = !sinyal;
    digitalWrite(buzzerPin, sinyal);
    delay(175);
  }
  delay(125);
  for (i; i < 16; i++)
  {
    sinyal = !sinyal;
    digitalWrite(buzzerPin, sinyal);
    delay(100);
  }
  */
  
}



void oda1Kur()
{
  pinMode(priz1Pin, OUTPUT);
  pinMode(yangin1Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(denePin, OUTPUT);
}


void oda1Calis()
{


  // 1. PRİZ KONTROLÜ
  if (veri == "priz1ac" && islem == 1)
  {
    digitalWrite(priz1Pin, HIGH);
    Serial.println("Oda 1'deki Priz Acildi.");
    islem = 0;
    delay(50);
  }

  if (veri == "priz1kapat" && islem == 1)
  {
    digitalWrite(priz1Pin, LOW);
    Serial.println("Oda 1'deki Priz Kapatildi.");
    islem = 0;
    delay(50);
  }
  // 1. PRİZ KONTROLÜ

  // 1. YANGIN SENSÖRÜ KONTROLÜ
  yangin1Deger = digitalRead(yangin1Pin);

  if (yangin1Deger == 1 && roleDeger == 1) // Yangin Sensörü Alev GÖRDÜĞÜ zaman
    // yangın alarmı elektrik varken çalışsın. Elektrik olmadığında parazitlenmesin
  {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("ODA 1'DE YANGIN ALGILANDI.");
    delay(50);

  }
  if (yangin1Deger == 0) // Yangin Sensörü Alev GÖRMEDİĞİ zaman
  {
    digitalWrite(buzzerPin, LOW);
    delay(50);
  }
  // 1. YANGIN SENSÖRÜ KONTROLÜ
}









int j = 0;
void yanginElektrikKontrol()
{
basaDon:
  if (yangin1Deger == 1 && roleDeger == 1) // yangın alarmı elektrik varken çalışsın. Elektrik olmadığında parazitlenmesin
  {
    for ( j = 0; j < 15; j++)
    {
      delay(200);
      yangin1Deger = digitalRead(yangin1Pin);
      if (yangin1Deger == 0)
      {
        goto basaDon;
      }
    }
  }
  else
  {
    j = 0;
  }

  if (j == 15)
  {
    Serial.println("Yangin 3 Saniye Surdugu Icin Elektrikler Kesildi!");
    roleDeger = 0;
    digitalWrite(role, LOW);
  }
}



