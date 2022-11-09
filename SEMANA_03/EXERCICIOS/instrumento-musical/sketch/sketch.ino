const int LDR = 5;

float LowestValue = 0;
float HighestValue = 0;

const int LED1 = 1;
const int LED2 = 2;
const int LED3 = 4;
const int LED4 = 6;

const int BUZZ = 7;

const int PLAY = 3;
const int RECORD = 8;
int recordState = 0;
int playState = 0;
int Playing = 0; 
int Recording = 0;

int SAVED[100] = {};
int SavedLength = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(LDR, OUTPUT);
  pinMode(PLAY, INPUT);
  pinMode(RECORD, INPUT);
}

void loop() {

  delay(1000);

  unsigned int AnalogValue;

  recordState = digitalRead(RECORD);
  playState = digitalRead(PLAY);
  AnalogValue = analogRead(LDR);

  Serial.println(AnalogValue);

  if (AnalogValue > HighestValue) {
    HighestValue = AnalogValue;
  } else if ((AnalogValue < HighestValue && LowestValue == 0) || (AnalogValue < LowestValue && LowestValue != 0)) {
    LowestValue = AnalogValue;
  }

  int DecimalValue = 0;
  
  if (HighestValue != 0 && LowestValue != 0) {
    float difference = (HighestValue - LowestValue) / 15; 
    for (int i = 0; i < 16; i++) {
      float CurrentBit = LowestValue + (difference * i);
      if (AnalogValue <= CurrentBit) {
        DecimalValue = i;
        break;
        }
      }
    }
  
  Decimal_to_Binary(DecimalValue);

  int frequency = 200 + (DecimalValue * 200);

  tone(BUZZ, frequency);

  if (recordState == LOW) {
    Recording = 1;
  }

  if (recordState == HIGH  && Recording == 1) {
    Serial.println("Salvo o valor binário de " + DecimalValue);
    SAVED[SavedLength] = DecimalValue;
    SavedLength++;
    if (SavedLength >= 10) {
      SavedLength = 0;
    }
    Recording = 0;
    Blink(frequency);
  }

  if (playState == LOW && SavedLength >= 1) {
    Playing = 1;
  }

  if (playState == HIGH && Playing == 1) {
    for (int i = 0; i < SavedLength; i++) {
      Serial.println("Agora tocando no valor binário " + SAVED[i]);
      Decimal_to_Binary(SAVED[i]);
      frequency = 200 + ((SAVED[i]) * 200);
      tone(BUZZ, frequency);
      delay(1500);
    }
    Playing = 0; 
    SAVED[100] = {};
    SavedLength = 0;
    Blink(1500);
  }
}


void Blink(int frequency) {
  for (int i = 1; i < 4; i++) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    tone(BUZZ, frequency, (250 * i));
    delay(250 * i); 
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    tone(BUZZ, frequency, (250 * i));
    delay(250 * i); 
  }
}

void Decimal_to_Binary(int DecimalValue) {
  for (int i = 0; i < 4; i++) {
    if (i == 0) {
      digitalWrite(LED1, (DecimalValue % 2));
    } else if (i == 1) {
      digitalWrite(LED2, ((DecimalValue / 2) % 2));
    } else if (i == 2) {
      digitalWrite(LED3, ((DecimalValue / 4) % 2));
    } else if (i == 3) {
      digitalWrite(LED4, ((DecimalValue / 8) % 2));
    }
  }
}