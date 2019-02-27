#include"MorseCodes.h"

const int led = 13;

const long unit = 500;

long lastFlash = 0;

int i = 0;

bool light = false;

//initializes all global variables

// Argument: Any character
// Return Value: Either:
//                  1) If the character is a letter, the upper case equivalent.
//                  2) If the character is not a letter, the original value.
char toUpper(char c) {
  if (c >= 0x41 && c <= 0x5A) {
    return c;
  }
  else if (c >= 0x61 && c <= 0x7A) {
    return c ^ (1 << 5);
  }
  else return c;
}

//sanitizes input and only deals with characters that are either upper or lower case letters. All other input is just returned. 

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}
String elmo;

bool reading = false;
bool stillGoing;

//initializes variables needed for proper timing and morse functions
void convertIncomingCharsToMorseCode() {

  long now = millis();






  if (reading == true) {

    if (elmo[i] == '.' && stillGoing) {
      digitalWrite(13, HIGH);
      if ((now - lastFlash) >= unit)  {

        digitalWrite(13, LOW);
        lastFlash = millis();
        stillGoing = false;
      }
//case of dot is handled
    }
    if (elmo[i] == '-' && stillGoing) {
      digitalWrite(13, HIGH);
     
      if ((now - lastFlash) >= (3 * unit)) {
        digitalWrite(13, LOW);
        lastFlash = millis();
        stillGoing = false; 
      }
    }
    //case if dash is handled

    if (elmo[i] == ' ' && stillGoing) {
      if ((now - lastFlash) >= (7 * unit)) {
        digitalWrite(13, LOW);
       
        lastFlash = millis();
        stillGoing = false; 
      }
    }
//case of space is handled
    if ((now - lastFlash) >= unit && !stillGoing) {

      digitalWrite(13, LOW);
      light = false;
      lastFlash = millis();
      i++;
      stillGoing = true;
      Serial.print("hey");
      Serial.print(i);

    }
//light turning off for one unit after each symbol is processed
   
    \
      if (i == (elmo.length()) && stillGoing && ((now - lastFlash) >= (3 * unit))) {
        digitalWrite(13, LOW);
        light = true;
        lastFlash = millis();
       
reading = false;
      }
      //light turning off for 3 units after each letter is completed

  


  }
  //checking to make sure that another character is available from the input
  else {
    if (Serial.available() > 0) {
      char x;

      x = (char)Serial.read();
      lastFlash = millis();
      reading = true;
      stillGoing = true;
      elmo = morseEncode(x);
      i = 0;
    }

  }

}










// TODO





void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();
}
