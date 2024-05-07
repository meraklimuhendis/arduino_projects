

/*


String karakter = "";
String veri="";

int islem=0;
/* herhangi bir işlem yapılacağı zaman
 *  yani bluetooth veri değişkenine yazdıracağı zaman 1 olur
 *  yapılacak işlem tamamlandığı zaman tekrar sıfıra çekilir.
 *  Amaç tekrar tekrar yapılan işlem döngüsü içerisindeki işlemin yapılmaması
*/

int islemYapiliyor = 0;

void textAlma()
{
  while (Serial.available())
  {

    // İSLEM YAPILIYOR yazısı sadece 1 kere ekranda yazacak.
    for (islemYapiliyor; islemYapiliyor < 1; islemYapiliyor++)
    {
      Serial.println("Islem yapiliyor.");
    }

    char c = Serial.read();
    
    if ( c == '\r' || c == '\n' )
    {
      veri = karakter;
      karakter = "";
      islem = 1;
      islemYapiliyor = 0;
    }
    else
    {
      karakter += c;

    }

  }
}


