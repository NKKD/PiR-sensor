#include <Wire.h>

//////////////////////////
// Hardware Definitions //
//////////////////////////
#define PIR_A0 A0  // PIR analog output on A0
#define PIR_A1 A1  // PIR analog output on A1
#define PIR_A2 A2  // PIR analog output on A2
#define PIR_A3 A3  // PIR analog output on A3
#define PIR_A4 A4  // PIR analog output on A4
#define PIR_A5 A5  // PIR analog output on A5

#define PRINT_TIME 100 // Rate of serial printouts
unsigned long lastPrint = 0; // Keep track of last serial out

void setup() 
{
  Serial.begin(9600);  // Serial is used to view Analog out
  // Analog and digital pins should both be set as inputs:
  pinMode(PIR_A0, INPUT);
  pinMode(PIR_A1, INPUT);
  pinMode(PIR_A2, INPUT);
  pinMode(PIR_A3, INPUT);
  pinMode(PIR_A4, INPUT);
  pinMode(PIR_A5, INPUT);
}

void loop() 
{

  // Read A pin, print that value to serial port:
  printAnalogValue();
}

void printAnalogValue()
{
  if ( (lastPrint + PRINT_TIME) < millis() )
  {
    lastPrint = millis();
    // Read in analog value:
    unsigned int analog_a0 = analogRead(PIR_A0);
    unsigned int analog_a1 = analogRead(PIR_A1);
    unsigned int analog_a2 = analogRead(PIR_A2);
    unsigned int analog_a3 = analogRead(PIR_A3);
    unsigned int analog_a4 = analogRead(PIR_A4);
    unsigned int analog_a5 = analogRead(PIR_A5);

    
    // Convert 10-bit analog value to a voltage
    // (Assume high voltage is 3.0V.)
    float analog_c0 = (float) analog_a0 / 1024.0 * 3.0;
    float analog_c1 = (float) analog_a1 / 1024.0 * 3.0;
    float analog_c2 = (float) analog_a2 / 1024.0 * 3.0;
    float analog_c3 = (float) analog_a3 / 1024.0 * 3.0;
    float analog_c4 = (float) analog_a4 / 1024.0 * 3.0;
    float analog_c5 = (float) analog_a5 / 1024.0 * 3.0;


    // Print 
    Serial.print(',');    // Print a comma
    Serial.print(2.5);    // Print the upper limit
    Serial.print(',');    // Print a comma
    Serial.print(1.7);    // Print the lower limit
    Serial.print(',');    // Print a comma
    Serial.print(analog_c0);
    Serial.print(',');    // Print a comma
    Serial.print(analog_c1);
    Serial.print(',');    // Print a comma
    Serial.print(analog_c2);
    Serial.print(',');    // Print a comma
    Serial.print(analog_c3);
    Serial.print(',');    // Print a comma
    Serial.print(analog_c4);
    Serial.print(',');    // Print a comma
    Serial.print(analog_c5);


    
    Serial.println();
  }
}
