#include <SD.h>
#include <SPI.h>
#define TRIG_PIN 9
#define ECHO_PIN 8
#define CS_PIN   10
File myfile;
long duration;
int distance;
bool detect = false;
unsigned long startMillis = 0; 
bool timeSet = false;
int startHour, startMinute, startSecond;
void getCurrentTime(int &hour, int &minute, int &second) {
  unsigned long secondsPassed = (millis() - startMillis) / 1000;
  hour = startHour;
  minute = startMinute;
  second = startSecond + secondsPassed;
  if (second >= 60) {
    minute += second / 60;
    second = second % 60;
  }
  if (minute >= 60) {
    hour += minute / 60;
    minute = minute % 60;
  }
  if (hour >= 24) {
    hour = hour % 24;
  }
}
void setup() 
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  if (!SD.begin(CS_PIN)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }
  Serial.println("SD card ready");
  Serial.println("Enter current time as: HH MM SS");
}
void loop() 
{
  if (Serial.available() && !timeSet) {
    startHour = Serial.parseInt();
    startMinute = Serial.parseInt();
    startSecond = Serial.parseInt();
    if (startHour >= 0 && startHour < 24 && startMinute >= 0 && startMinute < 60 && startSecond >= 0 && startSecond < 60) {
      timeSet = true;
      startMillis = millis();
      Serial.println("Time set successfully.");
    } 
    else 
    {
      Serial.println("Invalid time format. Please re-enter.");
    }
  }
  if (!timeSet) return;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  if (distance > 0 && distance < 20) 
  {
    if (!detect) 
    {
      detect = true;
      logEvent("Object entered");
    }
  } 
  else 
  {
    if (detect) 
    {
      detect = false;
      logEvent("Object left");
    }
  }
  delay(500);
}
void logEvent(const char* status) {
  myfile = SD.open("log.txt", FILE_WRITE);
  if (myfile) 
  {
    int h, m, s;
    getCurrentTime(h, m, s);
    myfile.print(status);
    myfile.print(" at ");
    if (h < 10) myfile.print("0");
    myfile.print(h); myfile.print(":");
    if (m < 10) myfile.print("0");
    myfile.print(m); myfile.print(":");
    if (s < 10) myfile.print("0");
    myfile.println(s);
    myfile.close();
    Serial.print(status);
    Serial.print(" at ");
    if (h < 10) Serial.print("0");
    Serial.print(h); Serial.print(":");
    if (m < 10) Serial.print("0");
    Serial.print(m); Serial.print(":");
    if (s < 10) Serial.print("0");
    Serial.println(s);
  } 
  else 
  {
    Serial.println("Error opening log.txt");
  }
}
