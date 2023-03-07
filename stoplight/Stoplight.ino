#define GRN 11
#define YLW 12
#define RED 13
#define STOPLIGHT_BUTTON 7

void setup()
{
  pinMode(GRN, OUTPUT);
  pinMode(YLW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(STOPLIGHT_BUTTON, INPUT);
}

void loop()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  Serial.println(digitalRead(STOPLIGHT_BUTTON));
  if (digitalRead(STOPLIGHT_BUTTON) == LOW) {
    digitalWrite(8, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(8000); // Wait for 8000 millisecond(s)
  }
  delay(10); // Wait for 10 millisecond(s)
}
