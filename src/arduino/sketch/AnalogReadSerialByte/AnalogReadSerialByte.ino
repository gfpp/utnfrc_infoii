// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int adc_int = analogRead(A0);

  unsigned char adc_byte = map(adc_int, 0, 1023, 0, 255);

  // Send out the value you read:
  Serial.write(adc_byte);
  delay(1);
}
