#define WHITE 10 // Pin for White LED
#define GRN 11 // Pin for Green LED
#define YLW 12 // Pin for Yellow LED
#define RED 13 // Pin for Red LED
#define STOPLIGHT_BUTTON 9 // Pin for stoplight button
#define POWER_BUTTON 8 // Pin for power button

bool stoplightPower = false; // Initialize stoplight to off

int debouceTime = 50; // Set debounce time to 50 ms

void setup()
{
  pinMode(WHITE, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(YLW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(STOPLIGHT_BUTTON, INPUT_PULLUP);
  pinMode(POWER_BUTTON, INPUT_PULLUP);
}

void loop()
{
  if(stoplightPower){
    runStoplight();
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


