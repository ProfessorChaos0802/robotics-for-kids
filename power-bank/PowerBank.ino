#define POT A0

int numLeds = 13;

void setup(){
  pinMode(POT, INPUT);
  
  for(int i = 1; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
  
}

void loop(){
  // Loops over each LED number and turns it on if the potentiometer has been turned far enough
  for(int i = 1; i <= numLeds; i++){
    digitalWrite(i, analogRead(POT) > (numLeds-i)*(1024/(numLeds+1)));
  }
}