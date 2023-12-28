# Door Open Detection System

This Arduino project implements a door open detection system using an ultrasonic distance sensor. The system includes features such as manual arming and disarming using a hardware switch, visual indicators with LEDs, and an audible alarm triggered by the opening of the door.

## Components Used

- Arduino UNO
- Ultrasonic Distance Sensor (HC-SR04)
- Blue LED
- Green LED
- Buzzer (27CN)
- Push Button Switch (4-pin)
- 10 Ohm Resistor
- Breadboard
- Jumper Wires

## Pin Layout

- Blue LED: Digital Pin 13
- Green LED: Digital Pin 12
- Buzzer: Digital Pin 11
- Ultrasonic Trigger (TRIG): Digital Pin 7
- Ultrasonic Echo (ECHO): Digital Pin 6
- Manual Switch for Arming: Digital Pin 10
- Manual Switch for Disarming: Digital Pin 9

## Functionality

1. **Arming and Disarming:**
   - The system can be manually armed and disarmed using a 4-pin push button switch.
   - Blue LED indicates armed status, and green LED indicates disarmed status.

2. **Door Open Detection:**
   - Ultrasonic distance sensor measures the distance.
   - The alarm is triggered if the distance falls below a set threshold, indicating the door is open.

3. **Audible Alarm:**
   - When the system is armed and the door is open, an audible alarm is activated.
   - The alarm continues until manually disarmed.

## Usage

1. Connect the components as per the provided pin layout.
2. Upload the Arduino code to your Arduino UNO.
3. Ensure the system is disarmed (green LED is lit).
4. Arm the system by pressing the arming button (blue LED will light up).
5. Open the door, and the alarm will be activated.

## Customize

Feel free to customize the following parameters in the Arduino code:

- Threshold distance for door open detection (`thresholdDistance` variable).
- Alarm sound frequency and duration in the `activateAlarm` function.
