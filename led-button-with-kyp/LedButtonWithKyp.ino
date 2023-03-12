#define BUT_RED A0
#define BUT_GRN A1
#define BUT_BLUE A2

#define RED_LED 7
#define GRN_LED 6
#define BLUE_LED 5

bool redLedOn = false;
bool grnLedOn = false;
bool blueLedOn = false;

void setup(){
    pinMode(BUT_RED, INPUT_PULLUP);
    pinMode(BUT_GRN, INPUT_PULLUP);
    pinMode(BUT_BLUE, INPUT_PULLUP);

    pinMode(RED_LED, OUTPUT);
    pinMode(GRN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
}

void loop(){

    if(!digitalRead(BUT_RED)){
        redLedOn = !redLedOn;
    }

    if(!digitalRead(BUT_GRN)){
        grnLedOn = !grnLedOn;
    }

    if(!digitalRead(BUT_BLUE)){
        blueLedOn = !blueLedOn;
    }

    digitalWrite(RED_LED, redLedOn);
    digitalWrite(GRN_LED, grnLedOn);
    digitalWrite(BLUE_LED, blueLedOn);
}