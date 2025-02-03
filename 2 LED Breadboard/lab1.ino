int yellowPin=6;
int redPin=9;
int yellowTime=500;
int redTime=500;
int yellowBlink=3;
int redBlink=5;
int h;
void setup() {
  pinMode (yellowPin, OUTPUT);
  pinMode (redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    for(h=1;h<=yellowBlink; h=h+1) {
  digitalWrite(yellowPin, HIGH);
  delay (yellowTime);
  digitalWrite (yellowPin, LOW);
  delay (yellowTime);
    }
    for (h=1;h<=redBlink; h=h+1){
  digitalWrite(redPin, HIGH);
  delay (redTime);
  digitalWrite (redPin, LOW);
  delay (redTime);
    }
}
