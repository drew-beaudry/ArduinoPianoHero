/**
 * Piano Hero Project
 * All code written by Drew Beaudry
 * For UW-Whitewater Comp-Sci 412
 */

#include "pitches.h"

int commonSend = 2;

int greenLight = 3;
int redLight = 4;
int yellowLight = 5;
int blueLight = 6;
int whiteLight = 7;

int greenInput = A0;
int redInput = A1;
int yellowInput = A2;
int blueInput = A3;
int whiteInput = A4;

int buttons[] = {greenInput, redInput, yellowInput, blueInput, whiteInput};
int buzzer = 9;
int tx = 1;
int rx = 0;
String serialString;

/*
 * SARIAS' SONG
 */

int sariasSong[] = {
  NOTE_F4,NOTE_A4,NOTE_B4,
  NOTE_F4,NOTE_A4,NOTE_B4,
  NOTE_F4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,
  NOTE_B4,NOTE_C5,NOTE_B4,NOTE_G4,NOTE_E4,
  NOTE_D4,NOTE_E4,NOTE_G4,NOTE_E4,

  NOTE_F4,NOTE_A4,NOTE_B4,
  NOTE_F4,NOTE_A4,NOTE_B4,
  NOTE_F4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,
  NOTE_B4,NOTE_C5,NOTE_E5,NOTE_B4,NOTE_G4,
  NOTE_B4,NOTE_G4,NOTE_D4,NOTE_E4,

  NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_C5,NOTE_B4,NOTE_E4,

  NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_C5,NOTE_D5,NOTE_E5,

  NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_C5,NOTE_B4,NOTE_E4,

  NOTE_E4,NOTE_D4,NOTE_F4,NOTE_E4,
  NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,
  NOTE_B4,NOTE_A4,NOTE_C5,NOTE_B4,
  NOTE_D5,NOTE_C5,

  NOTE_E5,NOTE_F5,NOTE_D5,NOTE_E5
};

int sariasSongButtonsIn[] = {
  greenInput,redInput,yellowInput,greenInput,redInput,yellowInput,
  greenInput,redInput,yellowInput,whiteInput,blueInput,
  yellowInput,blueInput,yellowInput,redInput,greenInput,
  greenInput,redInput,yellowInput,redInput,

  greenInput,redInput,yellowInput,greenInput,redInput,yellowInput,
  greenInput,redInput,yellowInput,whiteInput,blueInput,
  greenInput,redInput,whiteInput,blueInput,yellowInput,
  blueInput,yellowInput,greenInput,redInput,

  greenInput,redInput,yellowInput,
  redInput,yellowInput,blueInput,
  whiteInput,blueInput,yellowInput,
  greenInput,redInput,yellowInput,
  redInput,yellowInput,blueInput,
  yellowInput,blueInput,whiteInput,

  greenInput,redInput,yellowInput,
  redInput,yellowInput,blueInput,
  whiteInput,blueInput,yellowInput,
  
  redInput,greenInput,redInput,greenInput,
  yellowInput,redInput,yellowInput,redInput,
  blueInput,yellowInput,blueInput,yellowInput,
  whiteInput,blueInput,
  
  blueInput,whiteInput,yellowInput,blueInput
};

int sariasSongButtonsOut[] = {
  greenLight,redLight,yellowLight,greenLight,redLight,yellowLight,
  greenLight,redLight,yellowLight,whiteLight,blueLight,
  yellowLight,blueLight,yellowLight,redLight,greenLight,
  greenLight,redLight,yellowLight,redLight,

  greenLight,redLight,yellowLight,greenLight,redLight,yellowLight,
  greenLight,redLight,yellowLight,whiteLight,blueLight,
  greenLight,redLight,whiteLight,blueLight,yellowLight,
  blueLight,yellowLight,greenLight,redLight,

  greenLight,redLight,yellowLight,
  redLight,yellowLight,blueLight,
  whiteLight,blueLight,yellowLight,
  greenLight,redLight,yellowLight,
  redLight,yellowLight,blueLight,
  yellowLight,blueLight,whiteLight,

  greenLight,redLight,yellowLight,
  redLight,yellowLight,blueLight,
  whiteLight,blueLight,yellowLight,
  
  redLight,greenLight,redLight,greenLight,
  yellowLight,redLight,yellowLight,redLight,
  blueLight,yellowLight,blueLight,yellowLight,
  whiteLight,blueLight,
  
  blueLight,whiteLight,yellowLight,blueLight
};

/*
 * SONG OF STORMS
 */
int songOfStorms[] = {
  NOTE_D4, NOTE_F4, NOTE_D5,
  NOTE_D4, NOTE_F4, NOTE_D5,

  NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_C5,NOTE_A4,

  NOTE_A4,NOTE_D4,NOTE_F4,NOTE_G4,NOTE_A4,
  NOTE_A4,NOTE_D4,NOTE_F4,NOTE_G4,NOTE_E4,

  NOTE_D4, NOTE_F4, NOTE_D5,
  NOTE_D4, NOTE_F4, NOTE_D5,

  NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_C5,NOTE_A4,
  NOTE_A4,NOTE_D4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_D4
};

int songOfStormsButtonsIn[] = {
  greenInput,redInput,whiteInput,greenInput,redInput,whiteInput,
  blueInput,whiteInput,blueInput,whiteInput,blueInput,yellowInput,redInput,
  redInput,greenInput,greenInput,redInput,yellowInput,
  redInput,greenInput,greenInput,yellowInput,redInput,
  
  greenInput,redInput,whiteInput,greenInput,redInput,whiteInput,
  blueInput,whiteInput,blueInput,whiteInput,blueInput,yellowInput,redInput,
  redInput,greenInput,greenInput,redInput,yellowInput,yellowInput,greenInput
};

int songOfStormsButtonsOut[] = {
  greenLight,redLight,whiteLight,greenLight,redLight,whiteLight,
  blueLight,whiteLight,blueLight,whiteLight,blueLight,yellowLight,redLight,
  redLight,greenLight,greenLight,redLight,yellowLight,
  redLight,greenLight,greenLight,yellowLight,redLight,
  
  greenLight,redLight,whiteLight,greenLight,redLight,whiteLight,
  blueLight,whiteLight,blueLight,whiteLight,blueLight,yellowLight,redLight,
  redLight,greenLight,greenLight,redLight,yellowLight,yellowLight,greenLight
};

void setup() {
  Serial.begin(9600);
  
  pinMode(commonSend, OUTPUT);
  pinMode(buzzer, OUTPUT);
    
  pinMode(greenLight, OUTPUT);
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(blueLight, OUTPUT);
  pinMode(whiteLight, OUTPUT);

  pinMode(greenInput, INPUT);
  pinMode(redInput, INPUT);
  pinMode(yellowInput, INPUT);
  pinMode(blueInput, INPUT);
  pinMode(whiteInput, INPUT);

  digitalWrite(commonSend, HIGH);

  //Welcome Message
  printWelcomeMessage();
  playStartupTone();
}

void loop() {
  
//Check for serial input via bluetooth
if(Serial.available() > 0) {
  serialString = Serial.readString();
  checkInputString(serialString);
}

//Listen for the green button to be pressed
if (digitalRead(greenInput) == HIGH){
  while(true){
    digitalWrite(greenLight, HIGH);
    buzz(buzzer, NOTE_C4);
    if(checkButtonPresses(greenInput)){
      digitalWrite(greenLight, LOW);
      break;
    }
  }
}

//Listen for the red button to be pressed
if (digitalRead(redInput) == HIGH){
 while(true){
    digitalWrite(redLight, HIGH);
    buzz(buzzer, NOTE_D4);
    if(checkButtonPresses(redInput)){
      digitalWrite(redLight, LOW);
      break;
    }
  }
}

//Listen for the yellow button to be pressed
if (digitalRead(yellowInput) == HIGH){
 while(true){
    digitalWrite(yellowLight, HIGH);
    buzz(buzzer, NOTE_E4);
    if(checkButtonPresses(yellowInput)){
      digitalWrite(yellowLight, LOW);
      break;
    }
  }
}

//Listen for the blue button to be pressed
if (digitalRead(blueInput) == HIGH){
 while(true){
    digitalWrite(blueLight, HIGH);
    buzz(buzzer, NOTE_F4);
    if(checkButtonPresses(blueInput)){
      digitalWrite(blueLight, LOW);
      break;
    }
  }
}

//Listen for the white button to be pressed
if (digitalRead(whiteInput) == HIGH){
 while(true){
    digitalWrite(whiteLight, HIGH);
    buzz(buzzer, NOTE_G4);
    if(checkButtonPresses(whiteInput)){
      digitalWrite(whiteLight, LOW);
      break;
    }
  }
}
}//end loop

void printWelcomeMessage(){
  Serial.println("\nWelcome to Piano Hero!");
  Serial.println("Free-Play Mode is Currently Engaged");
  Serial.println("The available songs are:");
  Serial.println("The 'Song of Storms' and 'Sarias Song!'");
  Serial.println("Type 'storms' or 'saria' to pick one!");
}

void playStartupTone(){
  buzz(buzzer, NOTE_E6,150);
  delay(50);
  buzz(buzzer, NOTE_E6,150);
  delay(200);
  buzz(buzzer, NOTE_E6,150);
  delay(200);
  buzz(buzzer, NOTE_C6,150);
  delay(25);
  buzz(buzzer, NOTE_E6,150);
  delay(200);
  buzz(buzzer, NOTE_G6,150);
  delay(600);
  buzz(buzzer, NOTE_G5,150);
}

void playSuccessTone(){
  buzz(buzzer, NOTE_E6,150);
}

void checkInputString(String inString){   
  if(inString.indexOf("help") >=0){
    printWelcomeMessage();
  }
  
  if(inString.indexOf("saria") >=0){
    playSuccessTone();
    Serial.println("\nPlaying Sarias' Song!");
    playSong(1);
  } 
  
  if(inString.indexOf("storms") >=0){
    playSuccessTone();
    Serial.println("\nPlaying Song of Storms!");
    playSong(2);
  }
}
/** 
  *  Choose which song to play
  *  To be called publically
*/
void playSong(int song){
  int length;
  //Play Saria's Song
  if(song == 1){
    length = 85;
    playSong(sariasSongButtonsOut,
    sariasSongButtonsIn,
    sariasSong,
    length);
  }
  //Play Song of Storms
  if(song == 2){
    length = 43;
    playSong(songOfStormsButtonsOut,
    songOfStormsButtonsIn,
    songOfStorms,
    length);
  }
}

/**To be called by playSong(int)*/
void playSong(int buttonsOut[], int buttonsIn[], int notes[], int length){
    int i = 0;
    while(true){
    //Light up LED
    digitalWrite(buttonsOut[i], HIGH);
    //Listen for PRESS signal
    if(digitalRead(buttonsIn[i]) == HIGH){
      while(true){
        //Play the note until the button is released
        buzz(buzzer, notes[i]);
        //Check for the button to be released
        if(digitalRead(buttonsIn[i]) == LOW){
          //Turn off the button light
          digitalWrite(buttonsOut[i], LOW);
          //Increment counter
          i++;
          //Delay in case a button is required to be pressed twice in a row
          delay(100);
          //Break the inner loop
          break;
        }
      }
    }
    //Check for reaching the end of the data arrays
    //ie: The end of the song
    if(i==length){
      Serial.println("\nThe Song is finished! Well done!\nReturning to Free Play.");
      delay(2000);
      playSuccessTone();
      break;
    }
  }
}

/**Buzz for a given amount of milliseconds*/
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
 
}

/**Buzz once - to be used in a loop*/
void buzz(int targetPin, long frequency){
  long delayValue = 1000000 / frequency / 2;
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
}

/**returns true if the current button becomes
released or any other button becomes pressed*/
bool checkButtonPresses(int currentButton){
  //If the current button becomes unpressed return true
  if(digitalRead(currentButton) == LOW){
    return true;
  }
  else{
    for(int i = 0; i < 5; i++){
      //If any other button becomes pressed return true
      if(buttons[i] != currentButton && digitalRead(buttons[i] == HIGH)){
        return true;
      }
    }
  }
  return false;
}
