const int LDR = 5;
float LowestValue = 0;
float HighestValue = 0;

const int LED1 = 1;
const int LED2 = 2;
const int LED3 = 42;
const int LED4 = 41;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LDR, OUTPUT);
}

void loop() {
  unsigned int AnalogValue;

  AnalogValue = analogRead(LDR);

  if (AnalogValue > HighestValue) {
    HighestValue = AnalogValue;
  } else if ((AnalogValue < HighestValue && LowestValue == 0) || (AnalogValue < LowestValue && LowestValue != 0)) {
    LowestValue = AnalogValue;
  }

  
  if (HighestValue != 0 && LowestValue != 0) {
    float difference = (HighestValue - LowestValue) / 16; 
    Serial.println(LowestValue);
    Serial.println(LowestValue + difference);
    Serial.println(LowestValue + difference * 2);
    Serial.println(LowestValue + difference * 3);
    Serial.println(LowestValue + difference * 4);
    Serial.println(LowestValue + difference * 5);
    Serial.println(LowestValue + difference * 6);
    Serial.println(LowestValue + difference * 7);
    Serial.println(LowestValue + difference * 8);
    Serial.println(LowestValue + difference * 9);
    Serial.println(LowestValue + difference * 10);
    Serial.println(LowestValue + difference * 11);
    Serial.println(LowestValue + difference * 12);
    Serial.println(LowestValue + difference * 13);
    Serial.println(LowestValue + difference * 14);
    Serial.println(LowestValue + difference * 15);
    Serial.println(LowestValue + difference * 16);
    delay(20000);
  }
}
