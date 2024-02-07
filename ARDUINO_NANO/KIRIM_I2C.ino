void KIRIM_I2C_DATA()
{
  for(int x = 0; x < 7; x++)
  {
    Wire.write(dataKirim[x]);
  }
}
