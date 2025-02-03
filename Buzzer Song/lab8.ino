#define ANALOGREFVOLTAGE 5.555

// TMP36 Pin
int temperaturePin = A0;

// Piezo Pin
int piezoPin = 8;

// Threshold temperatures
float lowTempThreshold = 20.0;
float highTempThreshold = 40.0;

void setup()
{
  // Start the Serial connection
  Serial.begin(9600);
}

void loop()
{
  float temperatureC = getTemperature(temperaturePin);
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  float temperatureK = temperatureC + 273.15;

  // Display temperatures in one line
  Serial.print("Temperature (C): " + String(temperatureC) + "  |  ");
  Serial.print("Temperature (F): " + String(temperatureF) + "  |  ");
  Serial.println("Temperature (K): " + String(temperatureK));

  // Temperature alarm
  if (temperatureC < lowTempThreshold)
  {
    tone(piezoPin, 1100, 1000); // Play the alarm
    Serial.println("TOO LOW");
  }
  else if (temperatureC >= highTempThreshold)
  {
    tone(piezoPin, 1100, 1000); // Play the alarm
    Serial.println("TOO HIGH");
  }
  else
  {
    noTone(piezoPin); // Stop the alarm
    Serial.println("NORMAL");
  }

  delay(1000);
}

float getTemperature(int pin)
{
  float voltage = float(analogRead(pin)) * float(ANALOGREFVOLTAGE / 1023.0);
  return (voltage - 0.5) * 100;
}
