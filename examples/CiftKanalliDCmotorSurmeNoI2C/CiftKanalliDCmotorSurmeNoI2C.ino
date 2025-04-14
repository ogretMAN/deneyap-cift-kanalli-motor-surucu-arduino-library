/*   
 *    CiftKanalliDCmotorSurmeNoI2C örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    
 *          [+]  PİN BAĞLANTILARI
 *    >>>Deneyap Motor Sürücü 3V3 pini Deneyap Kart 3v3 pinine bağlandı<<<
 *    >>>Deneyap Motor Sürücü GND pini Deneyap Kart GND pinine bağlandı<<<
 *    >>>Deneyap Motor Sürücü SDA pini Deneyap Kart SDA pinine bağlandı<<<
 *    >>>Deneyap Motor Sürücü SCL pini Deneyap Kart SCL pinine bağlandı<<<
 *    >>>Deneyap Motor Sürücü MODE pini Deneyap Kart D9 pinine bağlandı<<<
 *    >>>Deneyap Motor Sürücü STBY pini 3.3v bağlanmalıdır<<<<
 *    >>>Deneyap Motor Sürücü SWM pini BOŞ BIRAKILDI<<<
 *    >>>Deneyap Motor Sürücü RES pini BOŞ BIRAKILDI<<<

 *    >>>Deneyap Kart Motor Sürücü üzerindeki Yeşil Terminaller (Klemensler)
 *    >>>VM pini Deneyap Kart BAT pinine bağlandı<<<
 *    >>>GND pini Deneyap Kart GND pinine bağlandı<<<
 *    >>>A ve B terminal bağlantıları için aşağıdaki setup() fonksiyonuna bakın
 *          [-]  PİN BAĞLANTILARI
 *
 *    Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır
 *    Bu örnek I2C haberleşme protokolü KULLANILMADAN yazılmıştır
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m  <------
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
*/
void setup() {
  pinMode(D0,OUTPUT);     // Deneyap Motor Sürücünün IN1A pinine bağlanmalı
  pinMode(A4,OUTPUT);     // Deneyap Motor Sürücünün IN2A pinine bağlanmalı
  pinMode(D1,OUTPUT);     // Deneyap Motor Sürücünün IN1B pinine bağlanmalı
  pinMode(A5,OUTPUT);     // Deneyap Motor Sürücünün IN2B pinine bağlanmalı
  pinMode(D9,OUTPUT);     // Deneyap Motor Sürücünün MODE pini D9'a bağlandı
  digitalWrite(D9,HIGH)   // Mod seçimi yapıldı
}

void loop() {
  // A ve B MOTORLARI TAM GÜÇ ÇALIŞIYOR
  analogWrite(A4, 255);   // 255 dutycyle hızı ile hareket. 0-255 dutycyle aralığında motor hızı belirlenir.
  digitalWrite(D0, HIGH); // A kanalına bağlı motor

  analogWrite(A5, 255);   // 255 dutycyle hızı ile hareket. 0-255 dutycyle aralığında motor hızı belirlenir.
  digitalWrite(D1, HIGH); // B kanalına bağlı motor

  delay(2000);

  
  // SADECE A MOTORU TAM GÜÇTE ÇALIŞIYOR
  analogWrite(A4, 255);
  digitalWrite(D0, HIGH);

  analogWrite(A5, 0);  
  digitalWrite(D1, LOW);
  
  delay(2000);

  
  // SADECE B MOTORU TAM GÜÇTE ÇALIŞIYOR
  analogWrite(A4, 0);
  digitalWrite(D0, LOW);

  analogWrite(A5, 255);  
  digitalWrite(D1, HIGH);
  
  delay(2000);

  
 // A ve B MOTORLARI YARIM (YAKLAŞIK) GÜÇ ÇALIŞIYOR
  analogWrite(A4, 170);   // 165 dutycyle altındaki hızlarda bazen güç yetmeyebilir, değiştirerek deneme yanılma yapınız.
  digitalWrite(D0, HIGH);

  analogWrite(A5, 170);   // 165 dutycyle altındaki hızlarda bazen güç yetmeyebilir, değiştirerek deneme yanılma yapınız.
  digitalWrite(D1, HIGH);

  delay(2000);

  
  // A ve B MOTORLARI DURDURULDU
  analogWrite(A4, 0);
  digitalWrite(D0, LOW);

  analogWrite(A5, 0);  
  digitalWrite(D1, LOW);

  delay(2000);
}
