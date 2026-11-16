const int sensorPin = 2;   // AETHDX sensor connected to Digital Pin 2
const int ledPin = 13;     // Built-in LED on Arduino Uno/Nano

void setup() {
  // Enable the internal pull-up resistor so no external resistor is needed
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("AETHDX Tilt/Vibration Sensor Ready...");
}

void loop() {
  // Read the state of the sensor
  int sensorState = digitalRead(sensorPin);

  // Because of INPUT_PULLUP, the pin reads LOW when the switch closes (tilted/shaken)
  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Movement or Tilt Detected!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50); // Short delay to prevent rapid serial flooding
}