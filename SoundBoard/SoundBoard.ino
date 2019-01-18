/***************************************************
 EEV See N' Say++
 Andrei Aldea
 January 2019
 
 Uses DFPlayer - A Mini MP3 Player For Arduino from <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>
 Uses Library by Angelo Qiao for said device. 
 
 Made to run on an Arduino Nano/Uno or other compatibles
 ***************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX for MP3 module
DFRobotDFPlayerMini myDFPlayer;

void setup()
{


    pinMode(A5, INPUT_PULLUP); //Because for some weird reason A7 INPUT_PULLUP causes AVR-GCC to seg-fault at the time of writing
    pinMode(2, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);

  mySoftwareSerial.begin(9600);
 // Serial.begin(9600); --Serial Port Taken up because I used Pin 1 for Matrix

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3, wait for module
    while (true);
  }

  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  myDFPlayer.play(int(random(0,3)));  //Play the first mp3 - Make Dave Say Hi
}

void loop()
{
  //Should have all been a CASE statement but copy-paste is easy.  
 
  if (digitalRead(A5) == HIGH) //If the page is NOT flipped
  {
    if(!digitalRead(1))
    {
      myDFPlayer.playFolder(1, int(random(1,14)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
    if(!digitalRead(2))
    {
      myDFPlayer.playFolder(2, int(random(1,17))); 
      delay(200); //Debounce
    }
    if(!digitalRead(3))
    {
      myDFPlayer.playFolder(3, int(random(1,50))); 
      delay(200); //Debounce
    }
        if(!digitalRead(4))
    {
      myDFPlayer.playFolder(4, int(random(1,5)));  
      delay(200); //Debounce
    }
        if(!digitalRead(5))
    {
      myDFPlayer.playFolder(5, int(random(1,25))); 
      delay(200); //Debounce
    }
        if(!digitalRead(6))
    {
      myDFPlayer.playFolder(6, int(random(1,18)));
      delay(200); //Debounce
    }
        if(!digitalRead(7))
    {
      myDFPlayer.playFolder(7, int(random(1,23)));
      delay(200); //Debounce
    }
        if(!digitalRead(8))
    {
      myDFPlayer.playFolder(8, int(random(1,11)));
      delay(200); //Debounce
    }
        if(!digitalRead(9))
    {
      myDFPlayer.playFolder(9, int(random(1,30)));
      delay(200); //Debounce
    }
        if(!digitalRead(12))
    {
      myDFPlayer.playFolder(10, int(random(1,13)));
      delay(200); //Debounce
    }
  }
  
  else //Page is flipped
  {
        if(!digitalRead(1))
    {
      myDFPlayer.playFolder(11, int(random(1,39))); 
      delay(200); //Debounce
    }
    if(!digitalRead(2))
    {
      myDFPlayer.playFolder(12, int(random(1,21))); 
      delay(200); //Debounce
    }
    if(!digitalRead(3))
    {
      myDFPlayer.playFolder(13, int(random(1,20))); 
      delay(200); //Debounce
    }
        if(!digitalRead(4))
    {
      myDFPlayer.playFolder(14, int(random(1,12))); 
      delay(200); //Debounce
    }
        if(!digitalRead(5))
    {
      myDFPlayer.playFolder(15, int(random(1,7))); 
      delay(200); //Debounce
    }
        if(!digitalRead(6))
    {
      myDFPlayer.playFolder(16, int(random(1,8))); 
      delay(200); //Debounce
    }
        if(!digitalRead(7))
    {
      myDFPlayer.playFolder(17, int(random(1,6)));
      delay(200); //Debounce
    }
        if(!digitalRead(8))
    {
      myDFPlayer.playFolder(18, int(random(1,13)));  //Right now this is a placeholder - no sounds will play as none are on SD
      delay(200); //Debounce
    }
        if(!digitalRead(9))
    {
      myDFPlayer.playFolder(19, int(random(1,13)));  //Right now this is a placeholder - no sounds will play as none are on SD
      delay(200); //Debounce
    }
        if(!digitalRead(12))
    {
      myDFPlayer.playFolder(20, int(random(1,2)));  //Some Tek Syndicate / Wendell from Level1Techs sounds
      delay(200); //Debounce
    }
  }
}
