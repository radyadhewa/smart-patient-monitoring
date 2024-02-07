void SENSOR_SUHU_1()
{
   sensorSuhu1.requestTemperatures();
   suhu1 = sensorSuhu1.getTempCByIndex(0);
//   Serial.print(suhu1);
//   Serial.print("\t");
}


