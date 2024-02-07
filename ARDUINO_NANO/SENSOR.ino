/*
 * dataKirim[0] = 255
 * dataKirim[1] = high hasilInfus1
 * dataKirim[2] = low hasilInfus1
 * dataKirim[3] = high hasilInfus2
 * dataKirim[4] = low hasilInfus2
 * dataKirim[5] = HEART1
 * dataKirim[6] = HEART2
 */

void SENSOR_INFUS_1()
{
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(8);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(8);
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(8);

  durasi1 = pulseIn(ECHO1, HIGH);
  hasilInfus1 = (durasi1/2) / 29.1;
  hasilInfus1 *= 10;
  AAhasilInfus1 = hasilInfus1;
  dataKirim[1] = AAhasilInfus1 >> 8;
  dataKirim[2] = AAhasilInfus1;

//  Serial.print(hasilInfus1);
//  Serial.print("\t");
}

void SENSOR_INFUS_2()
{
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(8);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(8);
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(8);

  durasi2 = pulseIn(ECHO2, HIGH);
  hasilInfus2 = (durasi2/2) / 29.1;
  hasilInfus2 *= 10;
  AAhasilInfus2 = hasilInfus2;
  dataKirim[3] = AAhasilInfus2 >> 8;
  dataKirim[4] = AAhasilInfus2;

//  Serial.print(hasilInfus2);
//  Serial.println("\t");
}

void SENSOR_DETAKJANTUNG_1()
{
  sensorPulse.analogInput(PulseWire1);         
  sensorPulse.setThreshold(Threshold);       
  sensorPulse.begin();
  myBPM1 = sensorPulse.getBeatsPerMinute();
  if (sensorPulse.sawStartOfBeat()) 
  {            
    dataKirim[5] = myBPM1;
//    Serial.print("BPM 1 : ");
//    Serial.print(myBPM1);
//    Serial.print("\t");               
  }
}

void SENSOR_DETAKJANTUNG_2()
{
  sensorPulse.analogInput(PulseWire2);         
  sensorPulse.setThreshold(Threshold);       
  sensorPulse.begin();
  myBPM2 = sensorPulse.getBeatsPerMinute();
  if (sensorPulse.sawStartOfBeat()) 
  {            
    dataKirim[6] = myBPM2;
//    Serial.print("BPM 2 : ");
//    Serial.print(myBPM2);
//    Serial.println();               
  }
}
