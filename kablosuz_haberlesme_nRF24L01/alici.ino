
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

include <SPI.h>
include <nRF24L01.h>
include <RF24.h>
RF24 radio(7, 8); // radio(CE, CS);
const uint64_t kod = 0xE8E8F0F0E1LL;

include <Servo.h>
Servo servo;
int servoPin = 3;

int sayi[1];

void setup() {
Serial.begin(9600);

radio.begin();
radio.openReadingPipe(1, kod);
radio.startListening();

servo.attach(servoPin);

}

void loop() {

if (radio.available())
{
bool done = false;
while (!done)
{
done = radio.read(sayi, 1);

  servo.write(sayi[0]);
  Serial.println(sayi[0]);
}
}

}

