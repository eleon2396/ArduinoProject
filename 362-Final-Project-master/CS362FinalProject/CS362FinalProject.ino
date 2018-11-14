//This code for Motion sensor and LCD
#include <LiquidCrystal.h>
//define the pins
int LED = 9;
int LED2 = 8;
int PIR = 7;
int counter = 0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

   lcd.begin(16, 2);
  // Print a message to the LCD.
 // lcd.print("hello, world!");
  delay(1000);
  //define the LED and Buzzer pin as output
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  //define the sensor pin as input
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  //using the digitalRead function we will read the signal of the sensor
  int value = digitalRead(PIR);
        
  //if its high or if an any object is detected it will activate the LED and Buzzer
  if (value == HIGH){
    digitalWrite(LED, HIGH);
   digitalWrite(LED2, HIGH);
    lcd.print("GOOOOALLL");
    counter++;
    Serial.println(value);
    
    delay(5000);
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
     Serial.println(value);
     lcd.print("Score: ");
     lcd.print(counter);
  }

  delay(1000);  
}
