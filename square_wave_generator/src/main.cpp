#include <Arduino.h>

//pin numbers
#define PWM_PIN 1
#define POTENCIOMETER_PIN 2

// período de 104ms, f = 9,61538
#define MIN_FREQUENCY 8 //Hz
#define MAX_FREQUENCY 11 //Hz


void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_PIN, OUTPUT);

  analogWriteFrequency(PWM_PIN, PWM_FREQUENCY);
  analogWrite(PWM_PIN, map(DUTY_CYCLE, 0, 100, 0, 255));
}

void loop() {
  // put your main code here, to run repeatedly:
}