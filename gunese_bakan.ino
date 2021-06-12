// Gereklii kütüphaneleri ekliyoruz
#include "deneyap.h"
#include "ServoESP32.h"

// Servomuzu tanımlıyoruz
Servo servoMotor;

// Gerekli int değerleri tanımlıyoruz 
int initial_position = 90;
int LDR1 = A0;
int LDR2 = A1;
int error = 5;
int servopin = D0;

// Setup fonksiyonu başlangıcı 
void setup()
{ 
  // Servomuzu "servopin" pinine   
  servoMotor.attach(servopin);

  // Analog pinlere taktığımız LDR'leri giriş olarak ayarlıyoruz.
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);

  // Servomuza başlangıç pozisyonumuzu giriyoruz
  servoMotor.write(initial_position);
  delay(2000);
}

// loop fonksiyonu başlangıcı
void loop()
{
  // LDR'den okunan değerleri değişkenlere basıyoruz
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);

  // Önceki okunan LDR değerlerinden, yeni okunan LDR değerlerini çıkartıyoruz
  // Çıkan değerin "abs()" fonksiyonu ile mutlak değerini alıyoruz
  int diff1 = abs(R1 - R2);
  int diff2 = abs(R2 - R1);
  
  // Çıkan farkların, önceden belirlenen error değerine göre karşılaştırıyoruz
  if ((diff1 <= error) || (diff2 <= error)) {

  } else {
    if (R1 > R2)
    {
      initial_position = initial_position - 1;
    }
    if (R1 < R2)
    {
      initial_position = initial_position + 1;
    }
  }

  // Son değeri servomuza yazıyoruz
  servoMotor.write(initial_position);

  delay(100);
}
