void setup() {

pinMode(7, OUTPUT); // This line is nor really necessary for the program to function, you can experiment by removing this line ad running the code

}

void loop() {

// the tone function takes three parameters (the pin number, the tone frequency, the number of seconds to sound)

tone(7, 440, 2000); //A

delay(1000);

tone(7, 494, 2000); //B

delay(1000);

tone(7, 523, 2000); //C

delay(1000);

tone(7, 587, 2000); //D

delay(1000);

tone(7, 659, 2000); //E

delay(1000);

tone(7, 698, 2000); //F

delay(1000);

tone(7, 784, 2000); //G

delay(1000);

tone(7, 880, 2000); //A

delay(1000);

//Playing the melodies an octave higher

tone(7, 494*2, 2000);

delay(1000);

tone(7, 523*2, 2000);

delay(1000);

tone(7, 587*2, 2000);

delay(1000);

tone(7, 659*2, 2000);

delay(1000);

tone(7, 698*2, 2000);

delay(1000);

tone(7, 784*2, 2000);

delay(1000);

tone(7, 880*2, 2000);

delay(1000);

//You can use the notone() function instead of the delay()

}