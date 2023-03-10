#define WHITE 10 // Pin for White LED
#define GRN 11 // Pin for Green LED
#define YLW 12 // Pin for Yellow LED
#define RED 13 // Pin for Red LED
#define RGB_R 6 // PWM for RGB Red Pin
#define RGB_B 5 // PWM for RGB Blue Pin
#define RGB_G 3 // PWM for RBG Green Pin

#define STOPLIGHT_BUTTON 9 // Pin for stoplight button
#define POWER_BUTTON 8 // Pin for power button

#define RGB_POT A0 // Analog pin for potentiometer

bool stoplightPower = false; // Initialize stoplight to off

int debouceTime = 100; // Set debounce time to 50 ms

void setup(){
  // LEDs
  pinMode(WHITE, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(YLW, OUTPUT);
  pinMode(RED, OUTPUT);

  // RGB LED
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(RGB_G, OUTPUT);

  // Potentiometer
  pinMode(RGB_POT, INPUT);

  // Buttons
  pinMode(STOPLIGHT_BUTTON, INPUT_PULLUP);
  pinMode(POWER_BUTTON, INPUT_PULLUP);
}

void loop(){
  rgbLED();

  powerStoplight();

  if(stoplightPower){
    runStoplight();
  }
}

/**
 * @brief Controls the rgbLED using a single potentiometer
 * 
 */
void rgbLED(){
  int val = analogRead(RGB_POT); // Value of potentiometer

  // Red-orange-yellow spectrum
  if( 0 <= val && val <= 341){
    int ledVal = map(val, 0, 341, 0, 255); // value to write to LED

    analogWrite(RGB_R, 255-ledVal);
    analogWrite(RGB_G, ledVal);
    analogWrite(RGB_B, 0);

  // Green-teal-blue spectrum  
  } else if( 341 < val && val <= 683){
    int ledVal = map(val, 341, 683, 0, 255); // value to write to LED

    analogWrite(RGB_R, 0);
    analogWrite(RGB_G, 255-ledVal);
    analogWrite(RGB_B, ledVal);

  // Blue-indigo-purple-red spectrum  
  } else {
    int ledVal = map(val, 683, 1023, 0, 255); // value to write to LED

    analogWrite(RGB_R, ledVal);
    analogWrite(RGB_G, 0);
    analogWrite(RGB_B, 255-ledVal);
  }
}

/**
 * @brief Given a button to read, return if that button has been pressed or not as a boolean
 * 
 * @param button -> Arduino pin to read from
 * @return true -> Button == HIGH
 * @return false -> Button == LOW
 */
bool debounceButton(int button){
  int initialButtonState = digitalRead(button); // Read the button
  delay(debouceTime); // Wait the defined time
  int newButtonState = digitalRead(button); // Read the button again

  // If the original and new button states are the same, return the initial button state,
  // otherwise return the new state
  if(newButtonState == initialButtonState){
    return (bool)initialButtonState;
  } else {
    return (bool)newButtonState;
  }
}

/**
 * @brief Checks if the POWER_BUTTON has been pressed. If pressed, toggle the power state of the stoplight
 * 
 */
void powerStoplight(){
  if(!debounceButton(POWER_BUTTON)){
    stoplightPower = !stoplightPower;
    digitalWrite(WHITE, stoplightPower);
  }

  if(!stoplightPower){
    digitalWrite(RED, stoplightPower);
    digitalWrite(YLW, stoplightPower);
    digitalWrite(GRN, stoplightPower);
  }
}

/**
 * @brief Runs the stoplight
 * 
 */
void runStoplight(){
  // Start with Green Light
  digitalWrite(RED, LOW);
  digitalWrite(YLW, LOW);
  digitalWrite(GRN, HIGH);

  if (!debounceButton(STOPLIGHT_BUTTON)) {
    // Yellow Light for 0.75 seconds
    digitalWrite(RED, LOW);
    digitalWrite(YLW, HIGH);
    digitalWrite(GRN, LOW);
    delay(750); 

    // Red Light for 2 seconds
    digitalWrite(RED, HIGH);
    digitalWrite(YLW, LOW);
    digitalWrite(GRN, LOW);
    delay(2000); 
  }
}


