
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

/*
ÖRNEKLER
Keyboard.print("Merhabalar"); // İmlecin bulunduğu yere tırnak içerisindeki yazıyı yazar.
Keyboard.write(KEY_RETURN); // içerisinde bulunan komuttaki klavye hareketini bir kere yapar ve bırakır.
Keyboard.press('l'); // Klavyeden tırnak içerisindeki karakteri basar. Ve basılı kalır.
Keyboard.release(KEY_RETURN); // Enter tuşuna basılmışsa bunu kaldırır.
Keyboard.releaseAll(); // basılı kalan tüm karakterleri yada tuşları kaldırır.
*/

include "Keyboard.h"
void setup()
{
Keyboard.begin(); // klavye ayarları yapıldı
delay(1000);
}

void loop()
{

Keyboard.println("Merhabalar");
delay(1000);
Keyboard.write(KEY_RETURN); // Enter tuşuna basar
Keyboard.println("Suan Merakli Muhendis youtube kanalindasiniz");
delay(1200);
Keyboard.write(KEY_RETURN);
Keyboard.println("Beni izlediginiz icin tesekkurler");
delay(1200);
Keyboard.write(KEY_RETURN);
Keyboard.println("Not defterini kapatiyorum Tekrar gorusmek dilegiyle");
delay(1000);
Keyboard.write(KEY_RETURN);
Keyboard.write(KEY_RETURN);
Keyboard.println("YOUTUBE KANALIMA ABONE OLMAYI UNUTMA");
delay(3000);

// Not defterini kapatıyoruz
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press(KEY_F4);
Keyboard.releaseAll();
Keyboard.write(KEY_RETURN);

while (true); // Sonsuz döngü

}

