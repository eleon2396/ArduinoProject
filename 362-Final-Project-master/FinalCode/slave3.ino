
// initiate buzzer pin
int buzPin = 10;  

void setup() {
  // initiate pin mode for buzzer
  pinMode(buzPin, OUTPUT);

  // initiate the baud rate to the same one set
  // by the master so that communication is 
  // possible
  Serial.begin(9600);
}

void loop() 
{

  // if Master sent something to this slave then
  // then sound the buzzer off
  if(Serial.available())
  {
    // read what came from the master ardunio 
    // for debugging purposes and to empty the buffer
    char s = Serial.read();
    Serial.println(s);

    // sound the buzzer and add a delay
    tone(buzPin, 1000);
    delay(1000);
  }

  // if no information was sent from master then don't let the buzzer
  // make a sound
  noTone(buzPin);
  delay(500);
}


