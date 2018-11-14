// these led's wil power the lights placed around the fooseball table 
int led = 7;
int led2 = 8;

void setup() 
{
  // set pin modes for the led's
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  // initiate the baud rate to the same one set
  // by the master so that communication is 
  // possible
  Serial.begin(9600);
}

void loop() 
{

  // check if there is anything to read that was
  // sent from the master
  if(Serial.available())
  {
    // read the value for debugging purposes and to empty 
    char s = Serial.read();
    Serial.println(s);

    // make lights go off and on to indicate a goal was made
    for(int i = 0; i < 10; i++)
    {
      if(i % 2 == 0)
      {
        digitalWrite(led, HIGH);
        digitalWrite(led2, LOW);
        
      }
      else
      {
        digitalWrite(led2, HIGH);
        digitalWrite(led, LOW);
      }
      delay(500);
    }
  }
  
  // keep lights off unless there is a goal made
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);

}
