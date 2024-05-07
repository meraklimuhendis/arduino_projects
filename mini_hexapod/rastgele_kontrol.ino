
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#include <Servo.h>
#include <Oscillator.h>

Oscillator osc_middle, osc_right, osc_left;

const int A = 30;
const int T = 1000;

int i = 0;

void setup()
{
delay(1000);

osc_middle.attach(2);
osc_right.attach(3);
osc_left.attach(4);

//..and set parameters
osc_middle.SetO(25); //Correction for the offset of the servos
osc_right.SetO(25); //(was -20)
osc_left.SetO(25);

osc_middle.SetA(15); //Middle motor needs a small amplitude (5-10)
osc_right.SetA(A);
osc_left.SetA(A);

set_period_all();
refresh_all();

//phase difference
osc_middle.SetPh(DEG2RAD( 90 ));
osc_right.SetPh( DEG2RAD( 0 ));
osc_left.SetPh( DEG2RAD( 0 ));

}

void loop()
{

// delay(30);

//ileri gidiş
for (i; i < 500; i++)
{
ileriGit();
refresh_all();
delay(30);
Serial.println(i);
}

//saga dönüş
for (i; i < 1000; i++)
{
sagaDon();
refresh_all();
delay(30);
}

//geri gidiş
for (i; i < 1500; i++)
{
geriGit();
refresh_all();
delay(30);
}

//sola dönüş
for (i; i < 2000; i++)
{
solaDon();
refresh_all();
delay(30);
}

if (i == 2000)
i = 0;

}

void solaDon()
{
osc_right.SetPh( DEG2RAD( 0 ));
osc_left.SetPh( DEG2RAD( 180 ));
}

void sagaDon()
{
osc_right.SetPh( DEG2RAD( 180 ));
osc_left.SetPh( DEG2RAD( 0 ));
}

void ileriGit()
{
osc_right.SetPh( DEG2RAD( 0 ));
osc_left.SetPh( DEG2RAD( 0 ));
}

void geriGit()
{
osc_right.SetPh( DEG2RAD( 180 ));
osc_left.SetPh( DEG2RAD( 180 ));
}

void stop_all() {

osc_middle.Stop();
osc_right.Stop();
osc_left.Stop();
}

void play_all() {

osc_middle.Play();
osc_right.Play();
osc_left.Play();

}

void refresh_all() {
//Refresh the oscillators
osc_middle.refresh();
osc_right.refresh();
osc_left.refresh();
}

void set_period_all() {
//Set the period of work
osc_middle.SetT(T);
osc_right.SetT(T);
osc_left.SetT(T);
}

