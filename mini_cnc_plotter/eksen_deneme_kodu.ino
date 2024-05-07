
/*
MERAKLI MÜHENDİS YOUTUBE KANALI
Youtube Kanalı için - https://bit.ly/2AEP5bf
Facebook Sayfası için - https://bit.ly/3qVqAMC
Discord Kanalımıza GEL! - https://bit.ly/347FlSp
Tüm sorularınızı discord kanalımızdan sorabilirsiniz. Orası teknik servis gibi :)
*/

#include <Stepper.h>

const int stepsPerRevolution = 20;

// Connection pins:
Stepper myStepperX(stepsPerRevolution, 8,9,10,11);

void setup() {
// Set speed:
myStepperX.setSpeed(200);
// max 250 steps for dvd/cd stepper motor
myStepperX.step(125);
delay(100);

}

void loop() {

}

