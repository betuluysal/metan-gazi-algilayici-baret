//Sensör pinlerimizi tanimliyoruz:
#define sensor_pin A0
#define buzzer_pin 9
//RGB LED'imizin çikis pinlerini tanimliyoruz:
#define led_r 5
#define led_g 6
#define led_b 7
//Sensörün çalismasi için gerekli ön isitma süresini 5sn olarak belirliyoruz
#define preheat_time 5000
//Alarmin çalmasi için gerekli esik degerini 300 olarak belirliyoruz.
#define threshold 450

void setup()
{
//Alarm için kullanacagimiz buzzer ve LED'leri çikis olarak tanimliyoruz
pinMode(buzzer_pin, OUTPUT);
pinMode(led_r, OUTPUT);
pinMode(led_g, OUTPUT);
pinMode(led_b, OUTPUT);
//Varsayilan olarak LED'in sönük kalmasini sagliyoruz
digitalWrite(led_r, HIGH);
digitalWrite(led_g, HIGH);
digitalWrite(led_b, HIGH);
//Sensör degerini seri monitörden görebilmemiz için seri haberlesmeyi baslatiyoruz:
Serial.begin(9600);
//Ilk 5sn boyunca sensörün isinmasini bekliyoruz. Bu esnada LED mavi renkte yaniyor:
Serial.println("Sensor isitiliyor...");
digitalWrite(led_b, LOW);
delay(preheat_time);
//Isima islemi için gereken 5sn süre tamamlandiginda mavi LED'i söndürüyoruz:
digitalWrite(led_b, HIGH);
delay(1000);
}

void loop()
{
//analogRead() fonksiyonu ile sensör degerini ölçüyoruz ve bir degisken içerisinde tutuyoruz:
int sensorValue = analogRead(sensor_pin);
//Sensör degeri belirledigimiz esik degerinden yüksek ise alarm() fonksiyonunu çagiriyoruz:
if (sensorValue >= threshold)
alarm(100);
//Alarmin çalmadigi durumda LED'in yesil yanmasini istiyoruz:
else
digitalWrite(led_g, LOW);
//Sensör degerini bilgisayarimizdan görebilmek için seri monitöre yaziyoruz:
Serial.println(sensorValue);
delay(1);
}

//Alarm fonksiyonumuzu tanimliyoruz. Bu fonksiyon parametre olarak buzzerin ötüp ve LED'in yanip sönecegi süreyi almakta.

void alarm(unsigned int duration)
{
//Buzzer'in 440Hz'te (la notasi) ses üretmesini istiyoruz:
tone(buzzer_pin, 440);
//Normal durumda yesil yanmakta olan LED'i söndürüp kirmizi renkte yakiyoruz:
digitalWrite(led_r, LOW);
digitalWrite(led_g, HIGH);
delay(duration);
noTone(buzzer_pin);
digitalWrite(led_r, HIGH);
digitalWrite(led_g, HIGH);
delay(duration);
}
