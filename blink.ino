const int lm35Pin = A0;  // LM35 sensor connected to analog pin A0
const int ledPin = 13;   // Onboard LED connected to digital pin 13

unsigned long previousMillis = 0;
const long interval1 = 250;  // Blink interval when temperature is below 30°C (in milliseconds)
const long interval2 = 500;  // Blink interval when temperature is above 30°C (in milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the LM35 temperature sensor value
  int rawValue = analogRead(lm35Pin);

  // Convert the raw sensor value to temperature in Celsius
  float temperatureCelsius = (rawValue / 1023.0) * 500;  // LM35 scale factor

  // Check if the temperature is below or above 30°C and control the LED
  if (temperatureCelsius < 30) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval1) {
      previousMillis = currentMillis;
      digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle the LED
    }
  } else {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle the LED
    }
  }

  // Print temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println("°C");
}
