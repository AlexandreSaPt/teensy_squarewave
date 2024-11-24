/** 
 * To do list
 *  - send via serial monitor the current frequency that it is sending
 *      ~ just send the value to the serial monitor when it changes
 *  - 
 */

#include <Arduino.h>

//pin numbers
#define PWM_PIN 1
#define POTENTIOMETER_PIN 2

// period off 104ms, f = 9,61538
#define MIN_FREQUENCY 8 //Hz
#define MAX_FREQUENCY 11 //Hz

#define DUTY_CYCLE 50 //%

#define FREQ_TOLERANCE 0.00 //Hz

const int ANALOG_DUTY_CYCLE = round((255 * DUTY_CYCLE ) / 100); // 0 - 1023

float frequency = 0;

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);

  Serial.begin(38400); //it seems that this number doesn't matter since the Teensy uses the max baud rate of the usb connection  
  Serial.println("Serial Communication is Working");
}

void loop() {
  int potenc_value = analogRead(POTENTIOMETER_PIN); // 0 - 1023

  float last_frequency = frequency;
  float read_frequency = map(potenc_value, 0, 1023, MIN_FREQUENCY, MAX_FREQUENCY);

  if(last_frequency - FREQ_TOLERANCE <= read_frequency && last_frequency + FREQ_TOLERANCE >= read_frequency){
    frequency = read_frequency;
    //means that the frequency has changed
    analogWriteFrequency(PWM_PIN, frequency);
    analogWrite(PWM_PIN, ANALOG_DUTY_CYCLE);

    Serial.print("Frequency(Hz): ");
    Serial.print(frequency);

    float period = (1 / (frequency)) * 1000; //ms
    Serial.print("Period(ms): ");
    Serial.println(period);
  }
}