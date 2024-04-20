const int gasSensorPin = A0; // Analog pin connected to gas sensor
const int buzzerPin = 9;     // Digital pin connected to buzzer

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(gasSensorPin);
  
  // Convert sensor value to a voltage level (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Threshold value (adjust as needed)
  float thresholdVoltage = 2.5; // Example threshold at half of the 5V range
  
  // Check if gas level exceeds threshold
  if (voltage > thresholdVoltage) {
    // Turn on buzzer alarm
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Turn off buzzer alarm
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); // Delay for stability
}
