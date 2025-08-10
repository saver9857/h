#define TRIG_PIN 9  // Define Trig pin
#define ECHO_PIN 10 // Define Echo pin

void setup() {
    Serial.begin(9600);       // Start Serial Monitor
    pinMode(TRIG_PIN, OUTPUT); // Set Trig pin as OUTPUT
    pinMode(ECHO_PIN, INPUT);  // Set Echo pin as INPUT
}

void loop() {
    long duration;
    float distance;

    // Send a 10us HIGH pulse to trigger the sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the pulse duration from the Echo pin
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert duration to distance (Speed of sound = 343m/s)
    distance = (duration * 0.0343) / 2;

    // Print distance to Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500); // Wait for 500ms before next reading
}
 
