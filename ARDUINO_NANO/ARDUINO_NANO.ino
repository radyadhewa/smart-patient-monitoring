#define USE_ARDUINO_INTERRUPTS true
#include <Wire.h>
#include <PulseSensorPlayground.h>

#define I2CAddress 8
#define ECHO1 6
#define TRIG1 7
#define ECHO2 8
#define TRIG2 9

PulseSensorPlayground sensorPulse;


float hasilInfus1, hasilInfus2;
int AAhasilInfus1, AAhasilInfus2, myBPM1, myBPM2;
long durasi1, durasi2;
const int PulseWire1 = 1;
const int PulseWire2 = 0;
const int LED13 = 13;    
int Threshold = 600;
byte dataKirim[10];

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  
  sensorPulse.blinkOnPulse(LED13);
  sensorPulse.analogInput(PulseWire1);
//  sensorPulse.analogInput(PulseWire2);         
//  sensorPulse.setThreshold(Threshold);       
//  sensorPulse.begin();

  Wire.begin(0x08);
  Wire.onRequest(KIRIM_I2C_DATA);

//  dataKirim[0] = 255;
}

void loop()
{
  SENSOR_INFUS_1();
  SENSOR_INFUS_2();
  SENSOR_DETAKJANTUNG_1();
  delay(100);
  SENSOR_DETAKJANTUNG_2();
  delay(100);
  for(int s = 0; s < 7; s++)
  {
    Serial.print(dataKirim[s]);
    Serial.print("\t");
  }
  Serial.println();
}
