
/*
MERAKLI MÜHENDİS YOUTUBE KANALI

Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp

Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

unsigned int qtr_deger[8];

void sensor_oku()
{
unsigned int adc_deger[8];
unsigned int i;

for (i = 0; i < 8; i++)
{
adc_deger[i] = analogRead(i);
}

for (i = 0; i < 9; i++)
{
if (adc_deger[i] >= 19) // algılanan renk siyah ise lojik 0 tanımlanır
{
qtr_deger[i] = 1;
}
else if (adc_deger[i] < 19) // algılanan renk beyaz ise lojik 1 tanımlanır
{
qtr_deger[i] = 0;
}
}
}

void sensor_degerlendir()
{

if (zemin == 0) // Zemin Siyah ise
{
  scizgi_deger[0] = qtr_deger[0];
  scizgi_deger[1] = qtr_deger[1];
  scizgi_deger[2] = qtr_deger[2];
  scizgi_deger[3] = qtr_deger[3];
  scizgi_deger[4] = qtr_deger[4];
  scizgi_deger[5] = qtr_deger[5];
  scizgi_deger[6] = qtr_deger[6];
  scizgi_deger[7] = qtr_deger[7];
}

if (zemin == 1) // Zemin Beyaz ise
{
  scizgi_deger[0] = !qtr_deger[0];
  scizgi_deger[1] = !qtr_deger[1];
  scizgi_deger[2] = !qtr_deger[2];
  scizgi_deger[3] = !qtr_deger[3];
  scizgi_deger[4] = !qtr_deger[4];
  scizgi_deger[5] = !qtr_deger[5];
  scizgi_deger[6] = !qtr_deger[6];
  scizgi_deger[7] = !qtr_deger[7];
}
gorulen_sensor_sayisi = scizgi_deger[0] + scizgi_deger[1] + scizgi_deger[2] + scizgi_deger[3] + scizgi_deger[4] + scizgi_deger[5] + scizgi_deger[6] + scizgi_deger[7];

sensor_deger = scizgi_deger[0] * agirlik0 + // Bu değerlerin sonucuna göre çizginin nerede ne tarafta olduğu anlaşılır
scizgi_deger[1] * agirlik1 +
scizgi_deger[2] * agirlik2 +
scizgi_deger[3] * agirlik3 +
scizgi_deger[4] * agirlik4 +
scizgi_deger[5] * agirlik5 +
scizgi_deger[6] * agirlik6 +
scizgi_deger[7] * agirlik7 ;

}

