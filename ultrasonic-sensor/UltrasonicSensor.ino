#define ECHO 22
#define TRIG 23

int numLeds = 13;

void setup(){
  
  for(int i = 1; i <= 13; i++){
    pinMode(i, OUTPUT);
  }

  Serial.begin(115200);
  Serial.println("HELLO!");
  
}

void loop(){
  long sensorReading = readSensor(TRIG, ECHO);
  Serial.println(readSensor(TRIG, ECHO));

  // Loops over each LED number and turns it on if the potentiometer has been turned far enough
  for(int i = 1; i <= numLeds; i++){
    digitalWrite(i, readSensor(TRIG, ECHO) > (numLeds-i)*(7750/(numLeds+1)));
  }
}

/**
 * @brief Returns the reading of the ultrasonic sensor. If reading is greater than 8000, value is rounded to 8000. If reading is less than 250, value is rounded to 250.
 * 
 * @param trig 
 * @param echo 
 * @return long 
 */
long readSensor(int trig, int echo){
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Reads the echo pin, and returns the sound wave travel time in microseconds
  pinMode(echo, INPUT);
  
  long reading = pulseIn(echo, HIGH);

  if(reading > 8000)
    reading = 8000;

  if(reading < 250)
    reading = 250;

  return reading;
}