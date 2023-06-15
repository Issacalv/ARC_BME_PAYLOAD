#ifndef Serial_Monitor_H
#define Serial_Monitor_H

void my_Serial_Monitor (int Troubleshoot_On, double Altitude_Value, double* Acceleration_Value, double* Gyroscope_Value, float Temperature_Value, float Humidity_Value, float* Voltage_Value){
  if(Troubleshoot_On == 1){
  Serial.print("Altitude in meters is: ");
  Serial.println(Altitude_Value);

  Serial.print("Ax :");
  Serial.println(Acceleration_Value[Ax_arr]);
  Serial.print("Ay :");  
  Serial.println(Acceleration_Value[Ay_arr]);
  Serial.print("Az :");
  Serial.println(Acceleration_Value[Az_arr]);

  Serial.print("Gx :");
  Serial.println(Gyroscope_Value[Gx_arr]);
  Serial.print("Gy :");
  Serial.println(Gyroscope_Value[Gy_arr]);
  Serial.print("Gz :");
  Serial.println(Gyroscope_Value[Gz_arr]);

  Serial.print("Temperature: ");
  Serial.print(Temperature_Value);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(Humidity_Value);
  Serial.println(" %");

  Serial.print("Voltage of MFC #1: ");
  Serial.print(Voltage_Value[V_1_arr]);
  Serial.println(" V");

  Serial.print("Voltage of MFC #2: ");
  Serial.print(Voltage_Value[V_2_arr]);
  Serial.println(" V");
  delay(2000);
  }

  else {
    Serial.println("Serial Monitor is not active");
    delay(10000);
  }
}

#endif /*Serial_Monitor_H */
