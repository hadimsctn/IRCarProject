#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

IRrecv irrecv(25);
decode_results results;
const int trigPin = 26;
const int echoPin = 27;
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
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle = 200;
int dutyCycle2 = 200;
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
  ledcSetup(pwmChannel2, freq, resolution);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel2);
  ledcWrite(pwmChannel, dutyCycle);
  ledcWrite(pwmChannel2, dutyCycle2);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);                           
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;
  if (distanceCm<=10&&distanceCm!=0){
    Serial.println(distanceCm);
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
  }
  if (distanceCm>10){
    digitalWrite(buzzer, LOW);
  }
  // Serial.println("haha");
  if (irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);
    if (results.value == 0xFF18E7)
    {
      Serial.println("start");
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
    }
    if (results.value == 0xFF5AA5)
    {
      dutyCycle = dutyCycle - 20;
      ledcWrite(pwmChannel, dutyCycle);
      if(dutyCycle2<250){
        dutyCycle2 = dutyCycle2 + 20;
        ledcWrite(pwmChannel2, dutyCycle2);
      }
    }
    if (results.value == 0xFF10EF)
    {
      dutyCycle2 = dutyCycle2 - 20;
      ledcWrite(pwmChannel2, dutyCycle2);
      if(dutyCycle<250){
        dutyCycle = dutyCycle + 20;
        ledcWrite(pwmChannel, dutyCycle);
      }
    }
    if (results.value == 0xFF4AB5){
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      distanceCm=15;
      delay(3000);
    }
    if (results.value == 0xFF38C7){
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
    }
    if (results.value == 0xFF6897)
    {
      dutyCycle2 = dutyCycle2 + 10;
      dutyCycle = dutyCycle + 10;
      if(dutyCycle>255){
        dutyCycle = 255;
      }
      if(dutyCycle2>255){
        dutyCycle2 = 255;
      }
      ledcWrite(pwmChannel, dutyCycle);
      ledcWrite(pwmChannel2, dutyCycle2);
    }
    if (results.value == 0xFFB04F)
    {
      dutyCycle2 = dutyCycle2 - 10;
      dutyCycle = dutyCycle - 10;
      ledcWrite(pwmChannel, dutyCycle);
      ledcWrite(pwmChannel2, dutyCycle2);
      if(dutyCycle<100){
        dutyCycle = 100;
      }
      if(dutyCycle2<100){
        dutyCycle2 = 100;
      }
    }
    Serial.println(dutyCycle);
    Serial.println(dutyCycle2);
    irrecv.resume();
  }
}