//#define soilWet 500   // Define max value we consider soil 'wet'
//#define soilDry 750   // Define min value we consider soil 'dry'
//
//// Sensor pins
//#define sensorPower 7
//#define sensorPin A0
//
//// Motor and Buzzer pins
//#define motorPin 8
//#define buzzerPin 9
//
//void setup() {
//  pinMode(sensorPower, OUTPUT);
//  digitalWrite(sensorPower, LOW); // Initially keep the sensor OFF
//
//  pinMode(motorPin, OUTPUT);
//  pinMode(buzzerPin, OUTPUT);
// 
//  digitalWrite(motorPin, LOW);  // Motor off initially
//  digitalWrite(buzzerPin, LOW); // Buzzer off initially
//
//  Serial.begin(9600);
//}
//
//void loop() {
//  // Get the reading from the function below and print it
//  int moisture = readSensor();
//  Serial.print("Analog Output: ");
//  Serial.println(moisture);
//
//  // Determine status of our soil
//  if (moisture < soilWet) {
//    Serial.println("Status: Soil is too wet");
//    digitalWrite(motorPin, HIGH);
//    digitalWrite(buzzerPin, HIGH);
//  } else if (moisture >= soilWet && moisture < soilDry) {
//    Serial.println("Status: Soil moisture is perfect");
//    digitalWrite(motorPin, HIGH);
//    digitalWrite(buzzerPin, HIGH);
//  } else {
////    Serial.println("Status: Soil is too dry - time to water!");
//    digitalWrite(motorPin, LOW);   // Turn motor ON
//    digitalWrite(buzzerPin, LOW);  // Turn buzzer ON
//  }
//
//  delay(1000);  // Take a reading every second
//  Serial.println();
//}
//
//// This function returns the analog soil moisture measurement
//int readSensor() {
//  digitalWrite(sensorPower, LOW);  // Turn the sensor ON
//  delay(10);                        // Allow power to settle
//  int val = analogRead(sensorPin);  // Read the analog value from sensor
//  digitalWrite(sensorPower, HIGH);   // Turn the sensor OFF
//  return val;                       // Return analog moisture value
//}







int soil=A0;
int relay=3;

void setup() {

pinMode(soil,INPUT);
pinMode(relay,OUTPUT);
digitalWrite(relay,HIGH);
Serial.begin(9600);
}

void loop() {

int soilData=analogRead(soil);
Serial.print("Soil DATA:");
Serial.println(soilData);

if(soilData>900)
{
  digitalWrite(relay,LOW);
}
else
{
  digitalWrite(relay,HIGH);
}
}
