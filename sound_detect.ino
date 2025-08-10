// Pin configuration
const int soundSensorPin = A0;  // Analog pin for sound sensor
const int buzzerPin = 9;        // Buzzer connected to digital pin 9

// Threshold for sound level (adjust according to your sensor)
const int soundThreshold = 70;  

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read sound sensor value
  int soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue);  // Print sound level for monitoring
  
  // Check if sound level crosses threshold
  if (soundValue > soundThreshold) {
    digitalWrite(buzzerPin, HIGH); // Turn buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn buzzer OFF
  }

  delay(100); // Small delay for stability
}
