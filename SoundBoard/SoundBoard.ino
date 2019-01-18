/***************************************************
  DFPlayer - A Mini MP3 Player For Arduino
  <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
  This example shows the basic function of library for DFPlayer.

  Created 2016-12-07
  By [Angelo qiao](Angelo.qiao@dfrobot.com)

  GNU Lesser General Public License.
  See <http://www.gnu.org/licenses/> for details.
  All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
  1.Connection and Diagram can be found here
  <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
  2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{


    pinMode(A5, INPUT_PULLUP); //Because for some weird reason A7 INPUT_PULLUP BREAKS the whole thing....
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
 // Serial.begin(9600);

//  Serial.println();
//  Serial.println(F("DFRobot DFPlayer Mini Demo"));
//  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
  //  Serial.println(F("Unable to begin:"));
  //  Serial.println(F("1.Please recheck the connection!"));
  //  Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  myDFPlayer.play(int(random(0,3)));  //Play the first mp3 - Make This Say Hi
}

void loop()
{
  static unsigned long timer = millis();
  /*
    if (millis() - timer > 5000) {
    timer = millis();
      myDFPlayer.next();
     //myDFPlayer.playFolder(1, 4);  //play s pecific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
    //myDFPlayer.playFolder(1, int(random(1,10)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
    }
  */
  if (digitalRead(A5) == HIGH) //If the page is NOT flipped
  {
    if(!digitalRead(1))
    {
      myDFPlayer.playFolder(1, int(random(1,14)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
    if(!digitalRead(2))
    {
      myDFPlayer.playFolder(2, int(random(1,17)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
    if(!digitalRead(3))
    {
      myDFPlayer.playFolder(3, int(random(1,50)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(4))
    {
      myDFPlayer.playFolder(4, int(random(1,5)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(5))
    {
      myDFPlayer.playFolder(5, int(random(1,25)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(6))
    {
      myDFPlayer.playFolder(6, int(random(1,18)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(7))
    {
      myDFPlayer.playFolder(7, int(random(1,23)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(8))
    {
      myDFPlayer.playFolder(8, int(random(1,11)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(9))
    {
      myDFPlayer.playFolder(9, int(random(1,30)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(12))
    {
      myDFPlayer.playFolder(10, int(random(1,13)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
  }
  
  else //Page is flipped
  {
        if(!digitalRead(1))
    {
      myDFPlayer.playFolder(11, int(random(1,39)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
    if(!digitalRead(2))
    {
      myDFPlayer.playFolder(12, int(random(1,21)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
    if(!digitalRead(3))
    {
      myDFPlayer.playFolder(13, int(random(1,20)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(4))
    {
      myDFPlayer.playFolder(14, int(random(1,12)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(5))
    {
      myDFPlayer.playFolder(15, int(random(1,7)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(6))
    {
      myDFPlayer.playFolder(16, int(random(1,8)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(7))
    {
      myDFPlayer.playFolder(17, int(random(1,6)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(8))
    {
      myDFPlayer.playFolder(18, int(random(1,13)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(9))
    {
      myDFPlayer.playFolder(19, int(random(1,13)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
        if(!digitalRead(12))
    {
      myDFPlayer.playFolder(20, int(random(1,2)));  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
      delay(200); //Debounce
    }
  }

  if (myDFPlayer.available()) {
    //printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
