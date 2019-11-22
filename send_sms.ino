#include <SoftwareSerial.h>  

SoftwareSerial SIM800(12, 10);                          // RX, TX                  
int piezoPin = 7;

void setup() {
  SIM800.begin(9600);               // Скорость обмена данными с модемом
  SIM800.println("AT");             // Автонастройка скорости
  SIM800.println("AT+CLVL?");       // Запрашиваем громкость динамика
  SIM800.println("AT+CMGF=1");      // Включить TextMode для SMS
  SIM800.println("AT+DDET=1,0,1");  // Включить DTMF
  SIM800.println("AT+CLIP=1");      // Включить АОН
  pinMode(7, OUTPUT); //объявляем пин как выход

  tone(piezoPin, 2000, 100); // Звук прекратится через 500 мс, о программа останавливаться не будет!
  
}
int flag = 0;
int flag2 = 0;
void loop() {


      if (flag <= 10)
      {
      delay (3000);
      SIM800.println("AT+CMGS=\"""+71230000000""\"");   // отправляем модему номер, на который необходимо отправить смс
      delay (3000);
      SIM800.println("TREVOGA!""\r\n" + (String)((char)26)); // отправляем модему текст смс
      //delay (10000);
      //SIM800.println("AT+CPOWD=0"); // отправляем модему текст смс
      tone(piezoPin, 1000, 100); // Звук прекратится через 500 мс, о программа останавливаться не будет!
     
      flag = flag + 1;
      }
      if (flag == 11)
      {
          tone(piezoPin, 2000, 500); // Звук прекратится через 500 мс, о программа останавливаться не будет!
          flag = flag + 1;
      }

}
