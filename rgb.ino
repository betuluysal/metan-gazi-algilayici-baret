int kirmiziPin = 5;
int yesilPin = 6;
int maviPin = 7;
 

 
void setup()
{
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);  
}
 
void loop()
{
  setColor(255, 0, 0);  // kirmizi
  delay(1000);
  setColor(0, 255, 0);  // yesil
  delay(1000);
  setColor(0, 0, 255);  // mavi
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
}
 
void setColor(int kirmizi, int yesil, int mavi)
{
  #ifdef COMMON_ANODE
    kirmizi = 255 - kirmizi;
    yesil = 255 - yesil;
    mavi = 255 - mavi;
  #endif
  analogWrite(kirmiziPin, kirmizi);
  analogWrite(yesilPin, yesil);
  analogWrite(maviPin, mavi);  
}
