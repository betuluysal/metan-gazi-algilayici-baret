int buzzerPin = 9; //buzzer pini tanimlaniyor
int notaSayisi = 8; //nota sayisi degisken olarak ataniyor
int C = 262; //
int D = 294; //
int E = 330; //
int F = 349; //
int G = 392; //
int A = 440; //
int B = 494; //
int C_ = 523; //
int notalar[] = {C, D, E, F, G, A, B, C_}; //notalar dizisi tnaimlaniyor
void setup()
{
  for (int i = 0; i < notaSayisi; i++) //nota sayisi artiriliyor
  {
    tone(buzzerPin, notalar[i]); //buzzerdan uygun desibel degerinin cikisi aliniyor
    delay(500);
    noTone(buzzerPin); //sinyal yok ise otme tanimlaniyor
    delay(20);
  }
  noTone(buzzerPin);
}

void loop()
{
}
