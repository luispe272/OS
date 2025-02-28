const int sensorTemp = A0;
const int ledPin = 13;
const int fanPin = 12;

void setup() {
    Serial.begin(9600); 
    pinMode(ledPin, OUTPUT);
    pinMode(fanPin, OUTPUT);
}

void loop() {
    int lectura = analogRead(sensorTemp);
    float voltaje = lectura * (5.0 / 1023.0);
    float temperatura = (voltaje - 0.5) * 100.0;
    
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    if (temperatura < 5) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        digitalWrite(fanPin, LOW);
    } 
    else if (temperatura >= 6 && temperatura <= 25) {
        digitalWrite(ledPin, LOW);
        digitalWrite(fanPin, LOW);
    } 
    else {
        digitalWrite(ledPin, HIGH);
        digitalWrite(fanPin, HIGH);
    }
}
