const int ldrPin=0;
const int sokakpwm=9;
int ldrDeger;
void sokak_kur(){
 pinMode(sokakpwm,OUTPUT);
}
void isikOku()
{
  ldrDeger=analogRead(ldrPin);
  if(ldrDeger<200){ldrDeger=200;}
  if(ldrDeger>400){ldrDeger=400;}
  ldrDeger=map(ldrDeger,200,400,0,255);
  analogWrite(sokakpwm,ldrDeger);
}


