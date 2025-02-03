int latchPin = 4;
int clockPin = 3;
int dataPin = 2;
int pins[4] = {8, 9, 10, 11};

byte H[4] = { B00001111,
              B00000110,
              B00000110,
              B00001111
};

byte T[4] = { B00001000,
              B00001111,
              B00001111,
              B00001000
};

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
}

void loop() {
  display_char(H, 2000); // Display 'H' for 5 seconds
  display_char(T, 2000); // Display 'T' for 5 seconds
}

void display_char(byte ch[4], int duration) {
  for (int s = 0; s < duration / 20; s++) {
    for (int d = 0; d < 4; d++) {
      int displayIndex = (d + 2) % 4; // Shift display starting point
      digitalWrite(latchPin, LOW);
      digitalWrite(pins[displayIndex], LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, ch[displayIndex]);
      digitalWrite(latchPin, HIGH);
      delay(1);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
      digitalWrite(latchPin, HIGH);
      digitalWrite(pins[displayIndex], HIGH);
    }
  }
}
