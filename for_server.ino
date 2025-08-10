#include <DHT.h>

// Soil Moisture Sensor Configuration
#define soilWet 500   // Define max value we consider soil 'wet'
#define soilDry 750   // Define min value we consider soil 'dry'
#define sensorPower 7  // Power pin for soil sensor
#define sensorPin A0   // Analog pin for soil sensor

// DHT11 Sensor Configuration
#define DHTPIN 2       // Pin connected to the sensor
#define DHTTYPE DHT11  // Change to DHT22 if using it
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Sensor Configuration
#define TRIG_PIN 9   // Define Trig pin
#define ECHO_PIN 10  // Define Echo pin

void setup() {
    Serial.begin(9600);
    
    // Initialize DHT sensor
    dht.begin();
    
    // Set soil moisture sensor power pin as OUTPUT
    pinMode(sensorPower, OUTPUT);
    digitalWrite(sensorPower, LOW); // Initially keep the sensor OFF
    
    // Set ultrasonic sensor pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    // ** Read Soil Moisture **
    int moisture = readSensor();
    Serial.print("Analog Output: ");
    Serial.println(moisture);
    
    if (moisture < soilWet) {
        Serial.println("Status: Soil is too wet");
    } else if (moisture >= soilWet && moisture < soilDry) {
        Serial.println("Status: Soil moisture is perfect");
    } else {
        Serial.println("Status: Soil is too dry - time to water!");
    }
    
    // ** Read Temperature & Humidity **
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    
    if (isnan(temp) || isnan(hum)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print("°C, Humidity: ");
        Serial.print(hum);
        Serial.println("%");
    }
    
    // ** Measure Distance with Ultrasonic Sensor **
    long duration;
    float distance;
    
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * 0.0343) / 2;
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    Serial.println("--------------------");
    delay(1000); // Wait for next cycle
}

// Function to read soil moisture sensor value
int readSensor() {
    digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
    delay(10);                         // Allow power to settle
    int val = analogRead(sensorPin);  // Read the analog value from sensor
    digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
    return val;                        // Return analog moisture value
}
