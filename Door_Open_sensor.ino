// Define the pins
const int blueLEDPin = 13;
const int greenLEDPin = 12;
const int buzzerPin = 11;
const int trigPin = 7;    // Connect the TRIG pin of the ultrasonic sensor to digital pin 7
const int echoPin = 6;    // Connect the ECHO pin of the ultrasonic sensor to digital pin 6
const int armSwitchPin = 10;      // Connect to a row on the breadboard for manual arming
const int disarmSwitchPin = 9;    // Connect to a different row on the breadboard for manual disarming

// Variables for manual arming/disarming and alarm state
bool systemArmed = false;
bool alarmActive = false;

void setup() {
  // Initialize the components
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(armSwitchPin, INPUT_PULLUP);   // Use internal pull-up resistor for arming switch
  pinMode(disarmSwitchPin, INPUT_PULLUP); // Use internal pull-up resistor for disarming switch

  // Initially set the system as disarmed
  disarmSystem();
}

void loop() {
  // Check if the manual arming switch is closed
  if (digitalRead(armSwitchPin) == LOW) {
    armSystem();
  }

  // Check if the manual disarming switch is closed
  if (digitalRead(disarmSwitchPin) == LOW) {
    disarmSystem();
  }

  // Check if the system is armed
  if (systemArmed) {
    // Check for distance and activate the alarm if needed
    checkDistance();
  } else {
    noTone(buzzerPin); // Turn off the buzzer when disarmed
  }
}

// Function to arm the system
void armSystem() {
  systemArmed = true;
  digitalWrite(blueLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);
}

// Function to disarm the system
void disarmSystem() {
  systemArmed = false;
  digitalWrite(blueLEDPin, LOW);
  digitalWrite(greenLEDPin, HIGH);
  noTone(buzzerPin); // Turn off the buzzer when disarming
  alarmActive = false; // Reset the alarm state when disarmed
}

// Function to check distance and activate the alarm
void checkDistance() {
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Set a threshold distance for triggering the alarm (adjust as needed)
  int thresholdDistance = 30;

  // If the distance is less than the threshold, activate the alarm
  if (distance < thresholdDistance && !alarmActive) {
    activateAlarm();
  }
}

// Function to activate the alarm
void activateAlarm() {
  // For now, we'll just turn on the buzzer continuously
  tone(buzzerPin, 1000); // Adjust the frequency based on your preference
  alarmActive = true; // Set the alarm state to active
}
