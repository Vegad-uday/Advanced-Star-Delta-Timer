// Define pins for buttons, relays, LEDs, and other components
#define BUTTON_PIN PB0
#define BUTTON_PIN1 PB1
#define BUTTON_PIN2 PB10

#define POT_PIN PA5
#define RELAY1_PIN PA3
#define RELAY2_PIN PA4
#define RELAY3_PIN PA2
#define SWITCH_PIN PA3

#define deltanc PA7
#define starin PA0
#define deltain PA1
#define led2 PB8
#define led3 PB9

#define LED_PIN PB7

void setup() {
  // Initialize pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);     // Set BUTTON_PIN as input with pull-up resistor
  pinMode(BUTTON_PIN1, INPUT_PULLUP);    // Set BUTTON_PIN1 as input with pull-up resistor
  pinMode(BUTTON_PIN2, INPUT_PULLUP);    // Set BUTTON_PIN2 as input with pull-up resistor
  pinMode(SWITCH_PIN, INPUT);            // Set SWITCH_PIN as input
  pinMode(LED_PIN, OUTPUT);              // Set LED_PIN as output
  pinMode(RELAY1_PIN, OUTPUT);           // Set RELAY1_PIN as output
  pinMode(RELAY2_PIN, OUTPUT);           // Set RELAY2_PIN as output
  pinMode(RELAY3_PIN, OUTPUT);           // Set RELAY3_PIN as output

  pinMode(starin, OUTPUT);               // Set starin as output
  pinMode(deltain, OUTPUT);              // Set deltain as output
  pinMode(led2, OUTPUT);                 // Set led2 as output
  pinMode(led3, OUTPUT);                 // Set led3 as output

  digitalWrite(RELAY1_PIN, HIGH);  // Initialize RELAY1 as off (HIGH is off for active-low relays)
  digitalWrite(RELAY2_PIN, HIGH);  // Initialize RELAY2 as off
  digitalWrite(RELAY3_PIN, HIGH);  // Initialize RELAY3 as off

  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  bool buttonPressed = digitalRead(BUTTON_PIN) == HIGH; // Read state of BUTTON_PIN

  if (buttonPressed) {
    int rtx1 = digitalRead(RELAY2_PIN);  // Read state of RELAY2
    int a1 = digitalRead(deltain);        // Read state of deltain

    // Check conditions to control LEDs and relays
    if ((rtx1 == 1 && a1 == 0) || (rtx1 == 0 && a1 == 1)) {
      digitalWrite(PB9, HIGH);    // Turn on LED at PB9
      digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
      digitalWrite(RELAY3_PIN, HIGH);  // Turn off RELAY3
      return; // Exit loop to stop further operations
    }

    digitalWrite(RELAY3_PIN, LOW);   // Turn on RELAY3
    digitalWrite(RELAY1_PIN, LOW);   // Turn on RELAY1

    int rtx = digitalRead(RELAY1_PIN);  // Read state of RELAY1
    int a = digitalRead(starin);        // Read state of starin

    if (rtx == 0 && a == 1) {
      digitalWrite(PB7, HIGH);    // Turn on LED at PB7
      digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
      digitalWrite(RELAY3_PIN, HIGH);  // Turn off RELAY3
      return; // Exit loop to stop further operations
    }

    unsigned long startTime = millis();   // Record start time
    unsigned long delayTime = map(analogRead(POT_PIN), 0, 4095, 60000, 0); // Map POT_PIN reading to delay time
    float del = delayTime / 1000.0; // Convert delay time to seconds
    while (millis() - startTime < delayTime) {
      Serial.println(del); // Print delay time in seconds
      if (digitalRead(BUTTON_PIN1) == LOW || digitalRead(BUTTON_PIN2) == LOW) {
        digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
        if (digitalRead(BUTTON_PIN2) == LOW) {
          Serial.println('1');  // Print '1' to serial
          digitalWrite(LED_PIN, HIGH);  // Turn on LED_PIN
        } else {
          Serial.println('a');  // Print 'a' to serial
          digitalWrite(LED_PIN, LOW);   // Turn off LED_PIN
        }
        return; // Exit loop to stop all operations
      }
      delay(10); // Short delay to prevent CPU overload
    }

    digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1

    if (digitalRead(SWITCH_PIN) == LOW) {
      delay(50); // Short delay if SWITCH_PIN is LOW
    } else {
      delay(100); // Longer delay if SWITCH_PIN is HIGH
    }
    int rtx2 = digitalRead(RELAY1_PIN);  // Read state of RELAY1
    int a2 = digitalRead(starin);        // Read state of starin

    if ((rtx2 == 1 && a2 == 0)) {
      digitalWrite(PB8, HIGH);    // Turn on LED at PB8
      digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
      digitalWrite(RELAY3_PIN, HIGH);  // Turn off RELAY3
      return; // Exit loop to stop further operations
    }
    digitalWrite(RELAY2_PIN, LOW);  // Turn on RELAY2

    // Check if stop button is pressed
    if (digitalRead(BUTTON_PIN1) == LOW || digitalRead(BUTTON_PIN2) == LOW) {
      if (digitalRead(BUTTON_PIN2) == LOW) {
        Serial.println('1');  // Print '1' to serial
        digitalWrite(LED_PIN, HIGH);  // Turn on LED_PIN
      } else {
        Serial.println('a');  // Print 'a' to serial
        digitalWrite(LED_PIN, LOW);   // Turn off LED_PIN
      }
      digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
      digitalWrite(RELAY2_PIN, HIGH);  // Turn off RELAY2
      return; // Exit loop to stop all operations
    }
  }

  // Check if stop button is pressed to stop all relays
  if (digitalRead(BUTTON_PIN1) == LOW || digitalRead(BUTTON_PIN2) == LOW) {
    if (digitalRead(BUTTON_PIN2) == LOW) {
      Serial.println('1');  // Print '1' to serial
      digitalWrite(LED_PIN, HIGH);  // Turn on LED_PIN
    } else {
      Serial.println('a');  // Print 'a' to serial
      digitalWrite(LED_PIN, LOW);   // Turn off LED_PIN
    }

    digitalWrite(RELAY1_PIN, HIGH);  // Turn off RELAY1
    digitalWrite(RELAY2_PIN, HIGH);  // Turn off RELAY2
    digitalWrite(RELAY3_PIN, HIGH);  // Turn off RELAY3
    digitalWrite(PB9, LOW);          // Turn off LED at PB9
    digitalWrite(PB8, LOW);          // Turn off LED at PB8
  }
}
