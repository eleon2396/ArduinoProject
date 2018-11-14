// include library that will be needed to use serial communication
#include <SoftwareSerial.h>

// initiate pins for player 2's goal
const int PIR1 = 13;
const int PIR2 = 12;

// initiate pins for player 1's goal
const int PIR3 = 11;
const int PIR4 = 10;

// slave 1 rx,tx pins
const byte rxPinSlave1 = 2;
const byte txPinSlave1 = 3;

// slave 2 rx,tx pins
const byte rxPinSlave2 = 4;
const byte txPinSlave2 = 5;

// slave 3 rx, tx pins
const byte rxPinSlave3 = 6;
const byte txPinSlave3 = 7;

// use SoftwareSerial to create communication between master arduino and the multiple slave arduinos
SoftwareSerial slave1 = SoftwareSerial(rxPinSlave1, txPinSlave1);

SoftwareSerial slave2 = SoftwareSerial(rxPinSlave2, txPinSlave2);

SoftwareSerial slave3 = SoftwareSerial(rxPinSlave3, txPinSlave3);

void setup() 
{
  // set pin modes for motion sensors
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  
  pinMode(PIR3, INPUT);
  pinMode(PIR4, INPUT);

  // initiate baud rate where master will send information
  // to slaves and slaves will catch the information
  slave1.begin(9600);
  slave2.begin(9600);
  slave3.begin(9600);
}

void loop() 
{

  // if player 1's goal sensor catches motion then write to slaves
  // to have them do what they need to do
  if(digitalRead(PIR3))
  {
    slave1.write("1");
    slave2.write("2");
    slave3.write("1");

    // delay since motion sensor will be keep sending that
    // there is motion detected even after a few seconds
    delay(8000);
  }

   // if player 2's goal sensor catches motion then write to slaves
  // to have them do what they need to do
  if(digitalRead(PIR2) && digitalRead(PIR1))
  {
    slave1.write("1");
    slave2.write("1");
    slave3.write("1");

    // delay since motion sensor will be keep sending that
    // there is motion detected even after a few seconds
    delay(6000);
  }
  

  
  delay(500);
}


