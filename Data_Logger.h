#ifndef Data_Logger_H
#define Data_Logger_H



void my_Data_Logger (char* currentName, double Altitude_Value, double* Acceleration_Value, double* Gyroscope_Value, float Temperature_Value, float Humidity_Value, float* Voltage_Value){
 
  Serial.println("SD card is datalogging");
  File dataFile = SD.open(currentName , FILE_WRITE);
  dataFile.print("Time: ");
  dataFile.print(millis() / 1000.0);
  dataFile.print("Altitude_Value: ");
  dataFile.print(Altitude_Value);
  dataFile.print(",");

  dataFile.print("Acceleration Value X: ");
  dataFile.print(Acceleration_Value[Ax_arr]);
  dataFile.print(",");

  dataFile.print("Acceleration Value Y: ");
  dataFile.print(Acceleration_Value[Ay_arr]);
  dataFile.print(",");

  dataFile.print("Acceleration Value Z: ");
  dataFile.print(Acceleration_Value[Az_arr]);
  dataFile.print(",");

  dataFile.print("Gyroscope_Value X: ");
  dataFile.print(Gyroscope_Value[Gx_arr]);
  dataFile.print(",");

  dataFile.print("Gyroscope_Value Y: ");
  dataFile.print(Gyroscope_Value[Gy_arr]);
  dataFile.print(",");

  dataFile.print("Gyroscope_Value Z: ");
  dataFile.print(Gyroscope_Value[Gz_arr]);
  dataFile.print(",");

  dataFile.print("Temperature : ");
  dataFile.print(Temperature_Value);
  dataFile.print(",");

  dataFile.print("Humidity");
  dataFile.print(Humidity_Value);
  dataFile.print(",");

  dataFile.print("MFC #1 : ");
  dataFile.print(Voltage_Value[V_1_arr]);
  dataFile.println(",");

  dataFile.print("MFC #2 : ");
  dataFile.print(Voltage_Value[V_2_arr]);
  dataFile.println(",");
  dataFile.close();

}

  #endif  /* Data_Logger_H */
