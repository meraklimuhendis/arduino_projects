


// Bluetooth bağlantısındaki Tanımlamalar
String karakter = "";
String veri = "";

int islem = 0;
/* herhangi bir işlem yapılacağı zaman
    yani bluetooth veri değişkenine yazdıracağı zaman 1 olur
    yapılacak işlem tamamlandığı zaman tekrar sıfıra çekilir.
    Amaç tekrar tekrar yapılan işlem döngüsü içerisindeki işlemin yapılmaması
*/
// Bluetooth bağlantısındaki Tanımlamalar


int roleDeger = 0;
int role = 32;
// Elektrik Ayarları

void elektrikRolesiAyar()
{
  pinMode(role, OUTPUT);
  digitalWrite(role, HIGH);
  roleDeger = 1;
}


void elektrikKontrol() {
  if (veri == "elektrikleriac" && islem == 1)
  {
    digitalWrite(role, HIGH);
    Serial.println("Elektrikler Acildi.");
    roleDeger = 1;
    islem = 0;
  }

  if (veri == "elektriklerikapat" && islem == 1)
  {
    digitalWrite(role, LOW);
    Serial.println("Elektrikler Kapatildi.");
    roleDeger = 0;
    islem = 0;
  }
}






void setup()
{
  elektrikRolesiAyar();
  oda1Kur();  // Şuan içerisindeki priz1Pin Arduino üzerindeki 13 ledini açıyor!!! DENEME AMAÇLI
  Serial.begin(9600);
  Serial.println("Oda 1 Ayarlandi.");
  delay(250);
  oda2Kur();
  Serial.println("Oda 2 Ayarlandi.");
  delay(250);
  banyoKur();
  Serial.println("Banyo Ayarlandi.");
  delay(250);
  rgbLedKur();
  Serial.println("RGB Ledler Ayarlandi.");
  delay(250);
  sokak_kur();
  Serial.println("Sokak Lambasi Ayarlandi");
  delay(250);
  Serial.println("Hosgeldiniz.");
  buzzerSinyal();
}


void loop()
{
 // buzzerSinyal();
  yanginElektrikKontrol();
  elektrikKontrol();
  textAlma();
  oda1Calis();
  sicaklikKontrolu();
  oda2Calis();
  banyoCalis();
  ledRenkYakilmasi();
  isikOku();
  //  ledRenkYakilmasi();


}


