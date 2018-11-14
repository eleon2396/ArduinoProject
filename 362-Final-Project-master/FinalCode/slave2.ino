// library needed to use the lcd
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// counters which will be used to indicate the score for each player
int counter = 0;
int counter2 = 0;

void setup() 
{
  // initiate the baud rate to the same one set
  // by the master so that communication is 
  // possible
  Serial.begin(9600);

  // initiate lcd
  lcd.begin(16, 2);
}


void loop() 
{
  // reset the characters displayed on the lcd
  lcd.clear();

  // if master sent information to this slave
  // then execute this code
  if(Serial.available())
  {
    // check the value that was sent by the master and print it
    // to the serial monitor for debugging purposes
    int s = Serial.read();
    Serial.println(s);

    // show that a goal was made
    lcd.print("GOOOOALLL");

    // if the value is 49 then player 1 made a goal
    // else if value is 50 then player 2 made a goal
    // increment counters based on who made the goal
    if(s == 49)
    {
      counter++;
    }
    else if(s == 50)
    {
      counter2++;
    }

    //delay so players can see a goal was made
    delay(1000);
  }
  else
  {
    // if no goals were made then keep displaying goal scores
    // for both player one and player 2
    lcd.print("P1 Score: ");
    lcd.print(counter);

    lcd.setCursor(0,1);
    lcd.print("P2 Score: ");
    lcd.print(counter2);
    
    // delay to show player scores
    delay(1000);
  }
}


