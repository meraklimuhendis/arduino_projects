
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#define agirlik0 -16
#define agirlik1 -8
#define agirlik2 -4
#define agirlik3 -2
#define agirlik4 2
#define agirlik5 4
#define agirlik6 8
#define agirlik7 16

unsigned int sensor_deger;
unsigned int zemin = 0; // Zemin=0 ise Zemin Siyahdır --- Zemin=1 ise Zemin Beyazdır
unsigned int gorulen_sensor_sayisi;

const unsigned int sag_motorPin = 2, sol_motorPin = 3; // sag motor 2 pine, sol motor 3 pinine ileri yönler bağlandı
unsigned int sag_hiz_degeri = 0, sol_hiz_degeri = 0;
const unsigned int sag_pwm = 4, sol_pwm = 5; // hiz değerlerinin verileceği pin2

unsigned int scizgi_deger[8];

unsigned int duz_cizgi_sayisi = 0;

void veri_gonder()
{
unsigned int i;
for (i = 0; i < 8; i++)
{
Serial.print(scizgi_deger[i]);
Serial.print("-");
}
Serial.print(sag_hiz_degeri);
Serial.print("-");
Serial.print(sol_hiz_degeri);
Serial.println("-");
}

void setup()
{
Serial.begin(9600);

pinMode(sag_motorPin, OUTPUT);
pinMode(sol_motorPin, OUTPUT);

digitalWrite(sag_motorPin, LOW);
digitalWrite(sol_motorPin, LOW);

}

void loop()
{
baslangic:

digitalWrite(sag_motorPin, HIGH);
digitalWrite(sol_motorPin, HIGH);

sensor_oku();
sensor_degerlendir();

// tuzakları sayma
if (gorulen_sensor_sayisi == 8)
{
dongubir:
sensor_oku();
sensor_degerlendir();

if (gorulen_sensor_sayisi == ! 2)
{
  goto dongubir;
}
if (gorulen_sensor_sayisi == 2)
{
  duz_cizgi_sayisi++;
  goto baslangic;
}
}

if (duz_cizgi_sayisi >= 4)
{
donguiki:
sensor_oku();
sensor_degerlendir();

if (scizgi_deger[0] == 1 && scizgi_deger[7] == 1)
{
  zemin = 1; // Zemin rengi beyaz oldu
}
else
{
  goto donguiki;
}
}

if (zemin == 1)
{
if (scizgi_deger[0] == 0 || scizgi_deger[7] == 0)
{
donguuc:
if (scizgi_deger[3] == 1 && scizgi_deger[4] == 1) // çizgi değeri değişmezse
{
goto donguuc;
}
else
{
zemin = 0;
goto baslangic;
}
}
}

if (zemin == 0 && scizgi_deger[3] == 1 && scizgi_deger[4] == 1)
{
sensor_deger = 0;
}

// motor hız değerlerinin girilmesi
sag_hiz_degeri = 220 + sensor_deger;
sol_hiz_degeri = 220 - sensor_deger;

analogWrite(sag_pwm, sag_hiz_degeri);
analogWrite(sol_pwm, sol_hiz_degeri);

veri_gonder(); // alınan verilen değerleri serial ekranda kontrol etme

}

