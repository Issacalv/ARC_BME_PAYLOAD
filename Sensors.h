#ifndef Sensors_H
#define Sensors_H

#define ON 1
#define OFF 0 

#define Ax_arr 0
#define Ay_arr 1
#define Az_arr 2

#define Gx_arr 0
#define Gy_arr 1
#define Gz_arr 2

#define V_1_arr 0
#define V_2_arr 1

#define Voltage_Sensor_1 A0
#define Voltage_Sensor_2 A4

#define Reference_Voltage  0.6
  
double Altitude (int Pressure_On){

  if (Pressure_On == ON) {
    float raw_pressure = BARO.readPressure();
    float altitude =  44330 * ( 1 - pow(raw_pressure/101.325, 1/5.255) );
    return altitude;
  }

  else {
    return 0;
  }

}

double *Acceleration( int Acceleration_On ){
  float x,y,z;
  static double arr[3];
  
  if(Acceleration_On == ON) { 
    IMU.readAcceleration(x,y,z);
    arr[Ax_arr] = x;
    arr[Ay_arr] = y;
    arr[Az_arr] = z;
    return arr;
  }

  else{
    return 0;
  }

}

double *Gyroscope( int Gyroscope_On) {
  float x,y,z;
  static double arr[3];

  if(Gyroscope_On == ON) {
    IMU.readGyroscope(x,y,z);
    arr[Gx_arr] = x;
    arr[Gy_arr] = y;
    arr[Gz_arr] = z;
    return arr;
  }

  else{
    return 0;
  }

}

float Temperature( int Temperature_On) {
  
  if(Temperature_On == ON){
    float temp_reading = HTS.readTemperature();
    return temp_reading;
  }

  else{
    return 0;
  }
}

float Humidity( int Humidity_On) {
  
  if (Humidity_On == ON){
    float humidity = HTS.readHumidity();
    return humidity;
  }

  else{
    return 0;
  }
}

/*
float Voltage( double R1 , double R2) {
  
  float Input_Voltage = 0.00;
  float Voltage_Out = 0.00;
  float Voltage_Divider = 0.00;
  const float Refference_Voltage = 4.096;
  const float Steps = 1024.0;

  Input_Voltage = analogRead(A0);
  Voltage_Out = (Input_Voltage * Refference_Voltage) / (Steps);
  Voltage_Divider = Voltage_Out / (R2 / (R1 + R2) );

  return  Voltage_Divider;

}
*/

float *Voltage( int Voltage_On){
  
  float value_1 = 0;
  float value_2 = 0;
  static float arr[2];



  value_1 = analogRead(Voltage_Sensor_1);
  value_2 = analogRead(Voltage_Sensor_2);
  arr[V_1_arr] = (value_1 * AR_INTERNAL2V4) / 4095;
  arr[V_2_arr] = (value_2 * AR_INTERNAL2V4) / 4095;

  

  return arr;

}




#endif  /* Sensors_H */ 
