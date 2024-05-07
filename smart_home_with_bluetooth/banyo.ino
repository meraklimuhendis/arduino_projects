

// Bağlantılar
const int priz4Pin = 22;
const int powerPin = 10;


void banyoKur()
{
  pinMode(priz4Pin, OUTPUT);
  pinMode(powerPin, OUTPUT);
}

void banyoCalis()
{

  
// 4. PRİZ KONTROLÜ
  if (veri == "priz4ac" && islem == 1)
  {
    digitalWrite(priz4Pin, HIGH);
    Serial.println("Banyodaki Priz Acildi.");
    islem=0;
    delay(50);
  }
  
  if (veri == "priz4kapat" && islem == 1)
  {
    digitalWrite(priz4Pin, LOW);
    Serial.println("Banyodaki Priz Kapatildi.");
    islem=0;
    delay(50);
  }
  // 4. PRİZ KONTROLÜ
 if (veri == "powerledaz" && islem == 1)
  {
    analogWrite(powerPin, 50);
    Serial.println("Power Led Duzeyi : Az.");
    islem=0;
    delay(50);
  }

  if (veri == "powerledorta" && islem == 1)
  {
    analogWrite(powerPin, 125);
    Serial.println("Power Led Duzeyi : Orta.");
    islem=0;
    delay(50);
  }

  if (veri == "powerledyuksek" && islem == 1)
  {
    analogWrite(powerPin, 255);
    Serial.println("Power Led Duzeyi : Az.");
    islem=0;
    delay(50);
  }
  if (veri == "powerledkapat" && islem == 1)
  {
    analogWrite(powerPin, 0);
    Serial.println("Power Led Kapatildi.");
    islem=0;
    delay(50);
  }
  
}

