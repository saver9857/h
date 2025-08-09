#include <DHT.h>

#define DHTPIN 2      // Pin connected to the sensor
#define DHTTYPE DHT11 // Change to DHT22 if using it

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C, Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  delay(500); // Wait 2 seconds before next reading
}
