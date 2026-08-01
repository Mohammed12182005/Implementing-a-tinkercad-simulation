A simple Arduino project that moves a servo motor when an object is detected within range
of an HC-SR04 ultrasonic sensor, and returns it to its resting position once the object
moves away.

How It Works:
The ultrasonic sensor continuously measures distance to the nearest object.
If an object is detected within 10 cm, the servo moves to 90 degrees.
If no object is within range, the servo returns to its resting position at 0 degrees.

components:
Arduino Uno 
HC-SR04 ultrasonic sensor
Servo motor 
Breadboard and jumper wires


