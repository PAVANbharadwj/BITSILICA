// Pin assignments
int led1 = 2;  
int led2 = 3;  
int led3 = 4;  

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  blinkLED(led1, 5);

  blinkLED(led2, 10);

  blinkLED(led3, 15);
}

void blinkLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(500); 
    digitalWrite(pin, LOW);
    delay(500);
  }
}
