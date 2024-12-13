// LED pin definitions
int red_1 = 13, orange_1 = 12, green_1 = 11;
int red_2 = 10, orange_2 = 9, green_2 = 8;
int red_3 = 7, orange_3 = 6, green_3 = 5;
int red_4 = 4, orange_4 = 3, green_4 = 2;
int LEDPin = 14;  // Pedestrian signal LED
int ButtonPin = A0; // Button pin for pedestrian request
int LEDState = 0;
int ButtonNew;
int ButtonOld = 1;

// Time delays
const int greenDelay = 5000; // Green light duration
const int orangeDelay = 3000; // Orange light duration

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

void direction_1_orange() {
    digitalWrite(red_1, LOW);
    digitalWrite(orange_1, HIGH);
    digitalWrite(green_1, LOW);

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

void direction_2_green() {
    digitalWrite(red_1, HIGH);
    digitalWrite(orange_1, LOW);
    digitalWrite(green_1, LOW);

    digitalWrite(red_2, LOW);
    digitalWrite(orange_2, LOW);
    digitalWrite(green_2, HIGH);

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

void direction_3_green() {
    digitalWrite(red_1, HIGH);
    digitalWrite(orange_1, LOW);
    digitalWrite(green_1, LOW);

    digitalWrite(red_2, HIGH);
    digitalWrite(orange_2, LOW);
    digitalWrite(green_2, LOW);

    digitalWrite(red_3, LOW);
    digitalWrite(orange_3, LOW);
    digitalWrite(green_3, HIGH);

    digitalWrite(red_4, HIGH);
    digitalWrite(orange_4, LOW);
    digitalWrite(green_4, LOW);
}

void direction_3_orange() {
    digitalWrite(red_1, HIGH);
    digitalWrite(orange_1, LOW);
    digitalWrite(green_1, LOW);

    digitalWrite(red_2, HIGH);
    digitalWrite(orange_2, LOW);
    digitalWrite(green_2, LOW);

    digitalWrite(red_3, LOW);
    digitalWrite(orange_3, HIGH);
    digitalWrite(green_3, LOW);

    digitalWrite(red_4, HIGH);
    digitalWrite(orange_4, LOW);
    digitalWrite(green_4, LOW);
}

void direction_4_green() {
    digitalWrite(red_1, HIGH);
    digitalWrite(orange_1, LOW);
    digitalWrite(green_1, LOW);

    digitalWrite(red_2, HIGH);
    digitalWrite(orange_2, LOW);
    digitalWrite(green_2, LOW);

    digitalWrite(red_3, HIGH);
    digitalWrite(orange_3, LOW);
    digitalWrite(green_3, LOW);

    digitalWrite(red_4, LOW);
    digitalWrite(orange_4, LOW);
    digitalWrite(green_4, HIGH);
}

void direction_4_orange() {
    digitalWrite(red_1, HIGH);
    digitalWrite(orange_1, LOW);
    digitalWrite(green_1, LOW);

    digitalWrite(red_2, HIGH);
    digitalWrite(orange_2, LOW);
    digitalWrite(green_2, LOW);

    digitalWrite(red_3, HIGH);
    digitalWrite(orange_3, LOW);
    digitalWrite(green_3, LOW);

    digitalWrite(red_4, LOW);
    digitalWrite(orange_4, HIGH);
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
    ButtonOld = ButtonNew;
}

void setup() {
    // Initialize LED pins as OUTPUT
    for (int pin = 2; pin <= 13; pin++) {
        pinMode(pin, OUTPUT);
    }
    pinMode(LEDPin, OUTPUT);
    pinMode(ButtonPin, INPUT);
}

void loop() {
    // Call pedestrian logic
    pedestrian();

    // Traffic control sequence
    direction_1_green();
    delay(greenDelay);

    direction_1_orange();
    delay(orangeDelay);

    direction_2_green();
    delay(greenDelay);

    direction_2_orange();
    delay(orangeDelay);

    direction_3_green();
    delay(greenDelay);

    direction_3_orange();
    delay(orangeDelay);

    direction_4_green();
    delay(greenDelay);

    direction_4_orange();
    delay(orangeDelay);
}
