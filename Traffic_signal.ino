// Define LED pins
int red_1 = 13, orange_1 = 12, green_1 = 11;
int red_2 = 10, orange_2 = 9, green_2 = 8;
int red_3 = 7, orange_3 = 6, green_3 = 5;
int red_4 = 4, orange_4 = 3, green_4 = 2;
int LEDPin = 14;  // Changed LED pin
int ButtonPin = A0; // Assuming analog pin A0 for the button
int LEDState = 0;
int ButtonNew;
int ButtonOld = 1;

// Define delay times
const int greenDelay = 5000;
const int orangeDelay = 3000;

void direction_1_green() {
  digitalWrite(red_1, LOW);
  digitalWrite(orange_1, LOW);
  digitalWrite(green_1, HIGH);

  digitalWrite(red_2, HIGH);
  digitalWrite(orange_2, LOW);
  digitalWrite(green_2, LOW);

  digitalWrite(red_3, HIGH);
  digitalWrite(orange_3, LOW);
  digitalWrite(green_3, LOW);

  digitalWrite(red_4, HIGH);
  digitalWrite(orange_4, LOW);
  digitalWrite(green_4, LOW);
}

void direction_2_orange() {
  digitalWrite(red_1, HIGH);
  digitalWrite(orange_1, LOW);
  digitalWrite(green_1, LOW);

  digitalWrite(red_2, LOW);
  digitalWrite(orange_2, HIGH);
  digitalWrite(green_2, LOW);

  digitalWrite(red_3, HIGH);
  digitalWrite(orange_3, LOW);
  digitalWrite(green_3, LOW);

  digitalWrite(red_4, HIGH);
  digitalWrite(orange_4, LOW);
  digitalWrite(green_4, LOW);
}

void pedestrian() {
  ButtonNew = digitalRead(ButtonPin);
  if (ButtonOld == 0 && ButtonNew == 1) {
    if (LEDState == 0) {
      digitalWrite(LEDPin, HIGH);
      LEDState = 1;
    } else {
      digitalWrite(LEDPin, LOW);
      LEDState = 0;
    }
  }
  ButtonOld = ButtonNew; // Update button state
}

void setup() {
  // Initialize LED pins
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(LEDPin, OUTPUT); // Pedestrian LED
  pinMode(ButtonPin, INPUT); // Button
}

void loop() {
  // Call pedestrian logic
  pedestrian();

  // Control traffic lights
  direction_1_green();
  delay(greenDelay);

  direction_2_orange();
  delay(orangeDelay);

  direction_2_green();
  delay(greenDelay);

  direction_3_orange();
  delay(orangeDelay);

  direction_3_green();
  delay(greenDelay);

  direction_4_orange();
  delay(orangeDelay);

  direction_4_green();
  delay(greenDelay);

  direction_1_orange();
  delay(orangeDelay);
}
