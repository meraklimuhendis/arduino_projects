int red;
int green;
int blue;


const int kPin1 = 3;
const int yPin1 = 4;
const int mPin1 = 5;

const int kPin2 = 6;
const int yPin2 = 7;
const int mPin2 = 8;


void rgbLedKur()
{
  pinMode(kPin1, OUTPUT);
  pinMode(mPin1, OUTPUT);
  pinMode(yPin1, OUTPUT);

  pinMode(kPin2, OUTPUT);
  pinMode(mPin2, OUTPUT);
  pinMode(yPin2, OUTPUT);
}



void kirmizi()
{
  red = 255;
  green = 0;
  blue = 0;
}


void mavi()
{
  red = 0;
  green = 0;
  blue = 255;
}

void yesil()
{
  red = 0;
  green = 255;
  blue = 0;
}

void oda1LedBilgiYolla()
{
  analogWrite(kPin1, red);
  analogWrite(yPin1, green);
  analogWrite(mPin1, blue);
}

void oda2LedBilgiYolla()
{
  analogWrite(kPin2, red);
  analogWrite(yPin2, green);
  analogWrite(mPin2, blue);
}

void oda1ledac()
{
  analogWrite(kPin1, 255);
  analogWrite(yPin1, 255);
  analogWrite(mPin1, 255);
}

void oda2ledac()
{
  analogWrite(kPin2, 255);
  analogWrite(yPin2, 255);
  analogWrite(mPin2, 255);
}

void oda2ledkapat()
{
  analogWrite(kPin2, 0);
  analogWrite(yPin2, 0);
  analogWrite(mPin2, 0);
}

void oda1ledkapat()
{
  analogWrite(kPin1, 0);
  analogWrite(yPin1, 0);
  analogWrite(mPin1, 0);
}

void ledRenkYakilmasi()
{
  if (veri == "oda2ledkapat" && islem == 1)
  {
    oda2ledkapat();
    Serial.println("Oda 2'nin Ledleri Kapatildi.");
    islem = 0;
  }

  if (veri == "oda1ledkapat" && islem == 1)
  {
    oda1ledkapat();
    Serial.println("Oda 1'in Ledleri Kapatildi.");
    islem = 0;
  }
  
  if (veri == "oda1ledac" && islem == 1)
  {
    oda1ledac();
    Serial.println("Oda 1'in Ledleri Acildi.");
    islem = 0;
  }

  if (veri == "oda2ledac" && islem == 1)
  {
    oda2ledac();
    Serial.println("Oda 2'nin Ledleri Acildi.");
    islem = 0;
  }

  if (veri == "oda1kirmizi" && islem == 1)
  {
    kirmizi();
    oda1LedBilgiYolla();
    Serial.println("Oda 1 Ledi Kirmizi Olarak Ayarlandi.");
    islem = 0;
  }
  if (veri == "oda1mavi" && islem == 1)
  {
    mavi();
    oda1LedBilgiYolla();
    Serial.println("Oda 1 Ledi Mavi Olarak Ayarlandi.");
    islem = 0;
  }

  if (veri == "oda1yesil" && islem == 1)
  {
    yesil();
    oda1LedBilgiYolla();
    Serial.println("Oda 1 Ledi Yesil Olarak Ayarlandi.");
    islem = 0;
  }


  if (veri == "oda2mavi" && islem == 1)
  {
    mavi();
    oda2LedBilgiYolla();
    Serial.println("Oda 2 Ledi Mavi Olarak Ayarlandi.");
    islem = 0;
  }

  if (veri == "oda2yesil" && islem == 1)
  {
    yesil();
    oda2LedBilgiYolla();
    Serial.println("Oda 2 Ledi Yesil Olarak Ayarlandi.");
    islem = 0;
  }

  if (veri == "oda2kirmizi" && islem == 1)
  {
    kirmizi();
    oda2LedBilgiYolla();
    Serial.println("Oda 2 Ledi Kirmizi Olarak Ayarlandi.");
    islem = 0;
  }
}





