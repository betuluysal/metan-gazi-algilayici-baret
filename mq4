const int gasPin = A0; //Sensor baglanti pini
void setup(){
  Serial.begin(9600); //Serial monitor uzerinde 9600 baydrate`de veri gonderme ayarlaniyor
}

void loop(){
  Serial.println(analogRead(gasPin)); //gaz pininden veriler okunuyor
  delay(1000); // yarim saniyede bir veri okunuyor
}
