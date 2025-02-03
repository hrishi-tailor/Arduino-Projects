// Define the button pin and LED pins
#define button_pin 7
int LED_1_PIN = 8;
int LED_2_PIN = 9;
int LED_3_PIN = 10;
int LED_4_PIN = 11;

// Initialize button-related variables
int button_pressed_count = 0;
int button_state = 0;
int prev_button_state = 0;

// Setup function: runs once when the Arduino starts
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set button pin as an input with a pull-up resistor
  pinMode(button_pin, INPUT_PULLUP);

  // Set LED pins as outputs
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);

  // Additional pin setup
  pinMode(14, OUTPUT);
  digitalWrite(13, LOW);

  // Print an initial message for debugging
  Serial.println("Button Count:");
}

// Loop function: runs repeatedly as the main program
void loop() {
  // Check and update the button state
  buttonclickcounter();
  
  // Control the state of the LEDs based on button clicks
  lightstates();
}

// Function to count button clicks and update the count
void buttonclickcounter() {
  // Read the current state of the button
  button_state = digitalRead(button_pin);
  
  // Check if the button state has changed
  if (button_state != prev_button_state) {
    if (button_state == HIGH) {
      // Button released, turn off a debug LED
      digitalWrite(13, LOW);
    } else {
      // Button pressed, increment the click count and print it
      digitalWrite(13, HIGH);
      button_pressed_count++;
      Serial.println(button_pressed_count);
    }
  }
  // Update the previous button state for the next comparison
  prev_button_state = button_state;
}

// Function to control the state of LEDs based on the button click count
void lightstates() {
  // Use button_pressed_count to determine which LEDs to turn on or off
  if (button_pressed_count == 1) {
    digitalWrite(LED_1_PIN, HIGH);
  } else if (button_pressed_count == 2) {
    digitalWrite(LED_1_PIN, LOW);
  } else if (button_pressed_count == 3) {
    digitalWrite(LED_2_PIN, HIGH);
  } else if (button_pressed_count == 4) {
    digitalWrite(LED_2_PIN, LOW);
  } else if (button_pressed_count == 5) {
    digitalWrite(LED_3_PIN, HIGH);
  } else if (button_pressed_count == 6) {
    digitalWrite(LED_3_PIN, LOW);
  } else if (button_pressed_count == 7) {
    digitalWrite(LED_4_PIN, HIGH);
  } else if (button_pressed_count == 8) {
    digitalWrite(LED_4_PIN, LOW);
  } else if (button_pressed_count == 9) {
    // Turn all LEDs on when the count is 9
    digitalWrite(LED_1_PIN, HIGH);
    dimgitalWrite(LED_2_PIN, HIGH);
    digitalWrite(LED_3_PIN, HIGH);
    digitalWrite(LED_4_PIN, HIGH);
  } else if (button_pressed_count == 10) {
    // Turn all LEDs off when the count is 10
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, LOW);
    digitalWrite(LED_4_PIN, LOW);
  } else if (button_pressed_count > 10) {
    // Reset everything when the count exceeds 10
    button_state = button_state - button_state;
    button_pressed_count = button_pressed_count - button_pressed_count;
    prev_button_state = prev_button_state - prev_button_state;
  }
}
