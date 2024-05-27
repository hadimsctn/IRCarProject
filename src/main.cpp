#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

IRrecv irrecv(34);
decode_results results;
const int trigPin = 13;
const int echoPin = 12;
// define sound speed in cm/uS
#define SOUND_SPEED 0.034
int motor1Pin1 = 5;
int motor1Pin2 = 17;
int enable1Pin = 16;
int motor2Pin1 = 18;
int motor2Pin2 = 19;
int enable2Pin = 21;
int buzzer = 14;
int mode=1;
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 130;
long duration;
float distanceCm;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel);
  ledcWrite(pwmChannel, dutyCycle);
}

void loop()
{
  digitalWrite(buzzer, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;

  // Prints the distance in the Serial Monitor
  if (distanceCm<3){
    if(dutyCycle>130){
      dutyCycle -= 50;
      ledcWrite(pwmChannel, dutyCycle);
    }
    Serial.println(distanceCm);
    digitalWrite(buzzer, HIGH);
  }
  if (irrecv.decode(&results))
  {
    if (results.value == 0xFF18E7)
    {
      Serial.println("start");
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
    }
    if (results.value == 0xFF5AA5)
    {
      Serial.println(mode);
      if(mode ==1){
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
      }
      else if (mode ==2){
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
      }
    }
    if (results.value == 0xFF10EF)
    {
      Serial.println(mode);
      if(mode ==1){
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);
      }
      else if (mode == 2){
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
      }
    }
    if (results.value == 0xFF38C7){
      if(mode ==1){
        mode =2;
      }else if(mode == 2){
        mode = 1;
      }
    }
    if(results.value !=0){ 
      if(dutyCycle<250){
        dutyCycle += 10;
        ledcWrite(pwmChannel, dutyCycle);
        Serial.println(dutyCycle);
      }      
    }
    irrecv.resume();
    delay(1000);
  }
  else{
    if(dutyCycle>130)
    dutyCycle -= 1;
    ledcWrite(pwmChannel, dutyCycle);
  }
}