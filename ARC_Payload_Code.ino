#include <Arduino_LPS22HB.h>
#include <Arduino_LSM9DS1.h>
#include <Arduino_HTS221.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include "Sensors.h"
#include "Serial_Monitor.h"
#include "Activate.h"
#include "Data_Logger.h"

#define Red_LED 2
#define Green_LED 4
#define chipSelect 10
char currentName[] = "MFC00.txt";

void setup() {
  Serial.begin(9600);
  pinMode (Red_LED , OUTPUT);
  pinMode(Green_LED, OUTPUT);


 Serial.print("Initializing SD card....");
 
  if(!SD.begin(chipSelect)){
    Serial.println("Initialization failed!");
    digitalWrite(Red_LED, HIGH);
    while(1);
  }

  Serial.println("Card is present and initialized");
  digitalWrite(Green_LED , HIGH);

  if(!BARO.begin()){
    Serial.println("Failed to initialize pressure sensor!");
    digitalWrite(Red_LED, HIGH);
    delay(250);
    digitalWrite(Red_LED, LOW);
    delay(250);
    while(1);
  }

  if(!HTS.begin()){
    Serial.println("Failed to initialize humidity temperature sensor!");
    digitalWrite(Red_LED, HIGH);
    delay(250);
    digitalWrite(Red_LED, LOW);
    delay(250);
    while(1);
  }

  if (!IMU.begin()){
    Serial.println("Fialed to initialize IMU!");
    digitalWrite(Red_LED, HIGH);
    delay(1500);
    digitalWrite(Red_LED, LOW);
    delay(1500);
    while(1);
  }

  for (byte i = i ; i < 99 ; i++) {
    if (SD.exists(currentName)){
      currentName[3] = i/10 + '0';
      currentName[4] = i%10 + '0';
    }
    else {
      break;
    }
  }

}


void loop() {


  double Altitude_Value = Altitude(Pressure_On);
  double* Acceleration_Value = Acceleration(Acceleration_On);
  double* Gyroscope_Value = Gyroscope(Gyroscope_On);
  float Temperature_Value = Temperature(Temperature_On);
  float Humidity_Value = Humidity(Humidity_On);
  //double Voltage_Value = Voltage(R1 , R2);
  float* Voltage_Value = Voltage(Voltage_On);

  my_Serial_Monitor(Troubleshoot_On, Altitude_Value, Acceleration_Value, Gyroscope_Value, Temperature_Value, Humidity_Value, Voltage_Value);
  my_Data_Logger(currentName, Altitude_Value, Acceleration_Value, Gyroscope_Value, Temperature_Value, Humidity_Value, Voltage_Value);

 
}
