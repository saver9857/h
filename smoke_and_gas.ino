const int mq2Pin = A0;  // Analog pin for MQ-2 sensor
const int threshold = 500;  // Set a gas detection threshold
const int buzzerPin = 8;

void setup() {
    Serial.begin(9600);
    pinMode(mq2Pin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(mq2Pin);
    Serial.print("Gas Level: ");
    Serial.println(sensorValue);

    if (sensorValue > threshold) {
        Serial.println("Warning! Gas detected.");
        digitalWrite(buzzerPin, HIGH);  // Turn buzzer on
    } else {
        digitalWrite(buzzerPin, LOW);   // Turn buzzer off
    }

    delay(1000);
}