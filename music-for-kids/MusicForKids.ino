#define BUZZER 5

#define RED_LED 1
#define YLW_LED 2
#define BLUE_LED 3
#define GRN_LED 4

#define RED_BTN 6
#define YLW_BTN 7
#define BLUE_BTN 8
#define GRN_BTN 9

#define C5 523

#define D5 587

#define E5 659

#define G5 784

bool red = false;
bool ylw = false;
bool blue = false;
bool grn = false;

int duration = 100;

int mary[] = {2, 1, 0, 1, 2, 2, 2, 1, 1, 1, 2, 3, 3, 2, 1, 0, 1, 2, 2, 2, 2, 1, 1, 2, 1, 0};

int noteIndex = 0;

void setup(){
  pinMode(RED_LED, OUTPUT);
  pinMode(YLW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  
  pinMode(RED_BTN, INPUT_PULLUP);
  pinMode(YLW_BTN, INPUT_PULLUP);
  pinMode(BLUE_BTN, INPUT_PULLUP);
  pinMode(GRN_BTN, INPUT_PULLUP);
  
  pinMode(BUZZER, OUTPUT);

  noteIndex = 0;

  red = false;
  ylw = false;
  blue = false;
  grn = false;
  
  Serial.begin(9600);
}

void loop(){
  
  while(noteIndex < sizeof(mary)){
    readNoteIndex(mary);
    controlLeds();
  	readButtons(mary);
  }
}

int note(int song[], int noteIndex){
  int note = 0;
  
  if(song == mary){
    switch(noteIndex){
      case 0: 
      	note = C5;
      	break;
      case 1:
      	note = D5;
      	break;
      case 2: 
      	note = E5;
      	break;
      case 3: 
      	note = G5;
      	break;
      default:
      	note = 0;
      	break;
  	}
  }
    
  return note;
}
  
void readButtons(int song[]){
  if(digitalRead(RED_BTN) == LOW){
    tone(BUZZER, note(song, noteIndex), duration);
    noteIndex++;
  }
  if(digitalRead(YLW_BTN) == LOW){
    tone(BUZZER, note(song, noteIndex), duration);
    noteIndex++;
  }
  if(digitalRead(BLUE_BTN) == LOW){
    tone(BUZZER, note(song, noteIndex), duration);
    noteIndex++;
  }
  if(digitalRead(GRN_BTN) == LOW){
    tone(BUZZER, note(song, noteIndex), duration);
    noteIndex++;
  }
  Serial.println(noteIndex);
}
  
void controlLeds(){
  digitalWrite(RED_LED, red);
  digitalWrite(YLW_LED, ylw);
  digitalWrite(BLUE_LED, blue);
  digitalWrite(GRN_LED, grn);
}

void readNoteIndex(int song[]){
    switch(song[noteIndex]){
        case 0:
            red = true;
            ylw = false;
            blue = false;
            grn = false;
            break;
        case 1:
            red = false;
            ylw = true;
            blue = false;
            grn = false;
            break;
        case 2:
            red = false;
            ylw = false;
            blue = true;
            grn = false;
            break;
        case 3:
            red = false;
            ylw = false;
            blue = false;
            grn = true;
            break;
        default:
            red = false;
            ylw = false;
            blue = false;
            grn = false;
            break;
    }
}