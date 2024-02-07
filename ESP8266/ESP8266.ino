#define BLYNK_PRINT Serial
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>


#define SDA_PIN 4
#define SCL_PIN 5
#define pinSUHU2 D6

OneWire oneWire1(pinSUHU1);
OneWire oneWire2(pinSUHU2);

DallasTemperature sensorSuhu1(&oneWire1);
DallasTemperature sensorSuhu2(&oneWire2);

char auth[] = "QqgDfBS-jpuB1vADONmYA-ZdjomIKAxt";
const char *ssid = "Aku keren";
const char *pass = "dhewaganteng";
const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;
int suhu1, suhu2, myBPM1, myBPM2;
byte dataTerima[10];
float hasilInfus1, hasilInfus2;

SimpleTimer timer;
WiFiClient client;

void setup() 
{
  Serial.begin(115200);  
  
  sensorSuhu1.begin();
  sensorSuhu2.begin();
  
//  Serial.print("Menghubungkan ke : ");
//  Serial.println(ssid);
//  WiFi.begin(ssid, pass);
//  while(WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print("...");
//  }
//  Serial.print("\nIP Address : ");
//  Serial.println(WiFi.localIP());
//  Serial.print("MAC Address : ");
//  Serial.println(WiFi.macAddress());
//
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000, Send_dataToBlynk);
  
  Wire.begin(SDA_PIN, SCL_PIN, I2C_MASTER);
}

void Send_dataToBlynk()
{
  I2C_terima();
  //kamar 2(suhu, infus, heart)
  Blynk.virtualWrite(V0, suhu2);
  Blynk.virtualWrite(V1, hasilInfus2);
  Blynk.virtualWrite(V2, myBPM2);
  //kamar 1(heart, infus, suhu)
  Blynk.virtualWrite(V4, myBPM1);
  Blynk.virtualWrite(V5, hasilInfus1);
  Blynk.virtualWrite(V6, suhu1);
}

void loop() 
{
//  Serial.println("a");
//  I2C_terima();
//  delay(1000);
  SENSOR_SUHU_1();
  SENSOR_SUHU_2();
  Blynk.run();
  timer.run();       
}
