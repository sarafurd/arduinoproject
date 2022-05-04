#include <Adafruit_NeoPixel.h>

//These are the number of LED's on each ring.
int ledCount1 = 24; //24 LED's on the outermost ring
int ledCount2 = 16;
int ledCount3 = 12;
int ledCount4 = 8;  //8 LED's on the innermost ring

//Each ring is connected to a specific pin on the Uno board
int ledPin1 = 7;  //Outermost ring on pin 7
int ledPin2 = 6;
int ledPin3 = 5;
int ledPin4 = 4;  //Innermost ring on pin 4

//Button pin
int buttonPin = 13;

//Parameters: Total number of LED's, what pin the ring is on, serial type info (the type of LED)
Adafruit_NeoPixel ringOne = Adafruit_NeoPixel(ledCount1, ledPin1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel ringTwo = Adafruit_NeoPixel(ledCount2, ledPin2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel ringThree = Adafruit_NeoPixel(ledCount3, ledPin3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel ringFour = Adafruit_NeoPixel(ledCount4, ledPin4, NEO_RGB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  ringFour.begin();
  ringThree.begin();
  ringTwo.begin();
  ringOne.begin();
  // randomSeed(analogRead(0));
}

void loop() {
  //patternOne();
  //patternTwo();
  int input = digitalRead(buttonPin);
  // Serial.println(input);

  if (input == 1) {
    turnOff();
  } else {
      int randNumber = random(2, 5);
      Serial.println(randNumber);
      if (randNumber == 2) {
        patternOne();
      } else if (randNumber == 3) {
        patternTwo();
      } else if (randNumber == 4) {
        patternThree();
      }
  }
  delay(500);
}

//COLOR GUIDE
//
//Color is dictated by different values for red, green, and blue
//
//0 0 0 = OFF
//0 10 0 = red
//0 0 10 = blue
//10 0 0 = green
//10 10 0 = yellow
// 0 10 10 = purple 


void turnOff() {
  // Ring 1: off
  for (int a = 0; a < ledCount1; a++) {
    ringOne.setPixelColor(a, 0, 0, 0);
  }
  ringOne.show();

  // Ring 2: off
  for (int b = 0; b < ledCount2; b++) {
    ringTwo.setPixelColor(b, 0, 0, 0);
  }
  ringTwo.show();

  // Ring 3: off
  for (int c = 0; c < ledCount3; c++) {
    ringThree.setPixelColor(c, 0, 0, 0);
  }
  ringThree.show();

  // Ring 4: off
  for (int d = 0; d < ledCount4; d++) {
    ringFour.setPixelColor(d, 0, 0, 0);
  }
  ringFour.show();
}


void patternOne() {
  // Turn on all the lights on the circles
  // Ring 4
  for (int i = 0; i < ledCount4; i++) {
    ringFour.setPixelColor(i, ringFour.Color(25, 25, 25)); // LED color: pink 
  }
  ringFour.show();
  delay(1000);
  for (int a = 0; a < ledCount4; a++) {
    ringFour.setPixelColor(a, 0, 0, 0); // LED color: off
  }
  ringFour.show();

  // Ring 3
  for (int j = 0; j < ledCount3; j++) {
    ringThree.setPixelColor(j, ringThree.Color(0, 25, 0)); // LED color: lime
  }
  ringThree.show();
  delay(1000);
  for (int b = 0; b < ledCount3; b++) {
    ringThree.setPixelColor(b, 0, 0, 0); // LED color: off
  }
  ringThree.show();

  // Ring 2
  for (int k = 0; k < ledCount2; k++) {
    ringTwo.setPixelColor(k, ringTwo.Color(25, 25, 25)); //LED color: blue
  }
  ringTwo.show();
  delay(1000);
  for (int c = 0; c < ledCount2; c++) {
    ringTwo.setPixelColor(c, 0, 0, 0); // LED color: off
  }
  ringTwo.show();

  // Ring 1
  for (int l = 0; l < ledCount1; l++) {
    ringOne.setPixelColor(l, ringOne.Color(0, 10, 10)); //LED color: purple
  }
  ringOne.show();
  delay(1000);
  for (int d = 0; d < ledCount1; d++) {
    ringOne.setPixelColor(d, 0, 0, 0); // LED color: off
  }
  ringOne.show();
}

void displayZero() {
  //Number 0
 // number, green, red, blue
    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(10, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(12, 5, 0, 0);
    ringOne.setPixelColor(13, 5, 0, 0);
    ringOne.setPixelColor(14, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);
    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(6, 5, 0, 0);
    ringTwo.setPixelColor(10, 5, 0, 0);
    ringTwo.setPixelColor(14, 5, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(3, 5, 0, 0);
    ringThree.setPixelColor(9, 5, 0, 0);
    ringThree.show();
    
    
    
    delay (1000);
    
    //Turn it off
    
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(10, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(12, 0, 0, 0);
    ringOne.setPixelColor(13, 0, 0, 0);
    ringOne.setPixelColor(14, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);
    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(6, 0, 0, 0);
    ringTwo.setPixelColor(10, 0, 0, 0);
    ringTwo.setPixelColor(14, 0, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(3, 0, 0, 0);
    ringThree.setPixelColor(9, 0, 0, 0);
    ringThree.show();
    
   
    delay (1000);


}

void displayOne() {
  //Number 1
    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(12, 5, 0, 0);
    ringOne.setPixelColor(13, 5, 0, 0);
    ringOne.show();
    
    ringTwo.setPixelColor(0, 5, 0, 0);
    ringTwo.setPixelColor(8, 5, 0, 0);
    ringTwo.setPixelColor(15, 5, 0, 0);
    ringTwo.setPixelColor(16, 5, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(0, 5, 0, 0);
    ringThree.setPixelColor(6, 5, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(0, 5, 0, 0);
    ringFour.setPixelColor(4, 5, 0, 0);
    ringFour.show();
    
    delay (1000);
    
    //Turn it off
    
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(12, 0, 0, 0);
    ringOne.setPixelColor(13, 0, 0, 0);
    ringOne.show();
    
    ringTwo.setPixelColor(0, 0, 0, 0);
    ringTwo.setPixelColor(8, 0, 0, 0);
    ringTwo.setPixelColor(15, 0, 0, 0);
    ringTwo.setPixelColor(16, 0, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(0, 0, 0, 0);
    ringThree.setPixelColor(6, 0, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(0, 0, 0, 0);
    ringFour.setPixelColor(4, 0, 0, 0);
    ringFour.show();
    
    delay (1000);
  

}

void displayTwo() {
    //Number 2
    
    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(6, 5, 0, 0);
    ringTwo.setPixelColor(10, 5, 0, 0);
    ringTwo.setPixelColor(11, 5, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(1, 5, 0, 0);
    ringThree.setPixelColor(5, 5, 0, 0);
    ringThree.setPixelColor(6, 5, 0, 0);
    ringThree.setPixelColor(7, 5, 0, 0);
    ringThree.setPixelColor(9, 5, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(7, 5, 0, 0);
    ringFour.setPixelColor(0, 5, 0, 0);
    ringFour.show();
    
    delay (1000);
    
    //Turn it off
    
    
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(6, 0, 0, 0);
    ringTwo.setPixelColor(10, 0, 0, 0);
    ringTwo.setPixelColor(11, 0, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(1, 0, 0, 0);
    ringThree.setPixelColor(5, 0, 0, 0);
    ringThree.setPixelColor(6, 0, 0, 0);
    ringThree.setPixelColor(7, 0, 0, 0);
    ringThree.setPixelColor(9, 0, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(7, 0, 0, 0);
    ringFour.setPixelColor(0, 0, 0, 0);
    ringFour.show();
    
    delay (1000);

}

void displayThree() {
    //Number 3

    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(9, 5, 0, 0);
    ringOne.setPixelColor(10, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(12, 5, 0, 0);
    ringOne.setPixelColor(13, 5, 0, 0);
    ringOne.setPixelColor(14, 5, 0, 0);
    ringOne.setPixelColor(15, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(5, 5, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(2, 5, 0, 0);
    ringThree.setPixelColor(3, 5, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(1, 5, 0, 0);
    ringFour.show();
    
    delay (1000);
    
    //Turn it off
    
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(9, 0, 0, 0);
    ringOne.setPixelColor(10, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(12, 0, 0, 0);
    ringOne.setPixelColor(13, 0, 0, 0);
    ringOne.setPixelColor(14, 0, 0, 0);
    ringOne.setPixelColor(15, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(5, 0, 0, 0);
    ringTwo.show();
    
    ringThree.setPixelColor(2, 0, 0, 0);
    ringThree.setPixelColor(3, 0, 0, 0);
    ringThree.show();
    
    ringFour.setPixelColor(1, 0, 0, 0);
    ringFour.show();
    
    delay (1000);

}

void displayFour() {
  //Number 4
    
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(3, 5, 0, 0);
    ringTwo.setPixelColor(7, 5, 0, 0);
    ringTwo.setPixelColor(14, 5, 0, 0);
    
    ringTwo.show();
    
    ringThree.setPixelColor(2, 5, 0, 0);
    ringThree.setPixelColor(5, 5, 0, 0);
    ringThree.setPixelColor(10, 5, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 5, 0, 0);
    ringFour.setPixelColor(1, 5, 0, 0);
    ringFour.setPixelColor(2, 5, 0, 0);
    ringFour.setPixelColor(3, 5, 0, 0);
    ringFour.setPixelColor(7, 5, 0, 0);
    
    ringFour.show();
    
    delay (1000);
    
    //Turn it off
    
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    
    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(3, 0, 0, 0);
    ringTwo.setPixelColor(7, 0, 0, 0);
    ringTwo.setPixelColor(14, 0, 0, 0);
    
    ringTwo.show();
    
    ringThree.setPixelColor(2, 0, 0, 0);
    ringThree.setPixelColor(5, 0, 0, 0);
    ringThree.setPixelColor(10, 0, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 0, 0, 0);
    ringFour.setPixelColor(1, 0, 0, 0);
    ringFour.setPixelColor(2, 0, 0, 0);
    ringFour.setPixelColor(3, 0, 0, 0);
    ringFour.setPixelColor(7, 0, 0, 0);
    
    ringFour.show();
    
    delay (1000);

}

void displayFive() {
  //Number 5
    
    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);

    
    ringOne.show();
    
    ringTwo.setPixelColor(6, 5, 0, 0);
    ringTwo.setPixelColor(7, 5, 0, 0);
    ringTwo.setPixelColor(8, 5, 0, 0);
    ringTwo.setPixelColor(9, 5, 0, 0);
    ringTwo.setPixelColor(10, 5, 0, 0);
    ringTwo.setPixelColor(14, 5, 0, 0);
    
    ringTwo.show();
    
    ringThree.setPixelColor(0, 5, 0, 0);
    ringThree.setPixelColor(1, 5, 0, 0);
    ringThree.setPixelColor(2, 5, 0, 0);
    ringThree.setPixelColor(3, 5, 0, 0);
    ringThree.setPixelColor(10, 5, 0, 0);
    ringThree.setPixelColor(11, 5, 0, 0);
    
    ringThree.show();
    
    delay (1000);
    
    //Turn it off
    
    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);

    
    ringOne.show();
    
    ringTwo.setPixelColor(6, 0, 0, 0);
    ringTwo.setPixelColor(7, 0, 0, 0);
    ringTwo.setPixelColor(8, 0, 0, 0);
    ringTwo.setPixelColor(9, 0, 0, 0);
    ringTwo.setPixelColor(10, 0, 0, 0);
    ringTwo.setPixelColor(14, 0, 0, 0);
    
    ringTwo.show();
    
    ringThree.setPixelColor(0, 0, 0, 0);
    ringThree.setPixelColor(1, 0, 0, 0);
    ringThree.setPixelColor(2, 0, 0, 0);
    ringThree.setPixelColor(3, 0, 0, 0);
    ringThree.setPixelColor(10, 0, 0, 0);
    ringThree.setPixelColor(11, 0, 0, 0);
    
    ringThree.show();
    
    delay (1000);     

}

void displaySix() {
  //Number 6
    
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(12, 5, 0, 0);
    ringOne.setPixelColor(13, 5, 0, 0);
    ringOne.setPixelColor(14, 5, 0, 0);
    ringOne.setPixelColor(15, 5, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(0, 5, 0, 0);
    ringTwo.setPixelColor(6, 5, 0, 0);
    ringTwo.setPixelColor(11, 5, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(4, 5, 0, 0);
    ringThree.setPixelColor(9, 5, 0, 0);
    ringThree.setPixelColor(10, 5, 0, 0);
    ringThree.setPixelColor(11, 5, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 5, 0, 0);
    ringFour.setPixelColor(1, 5, 0, 0);
    ringFour.setPixelColor(2, 5, 0, 0);
    ringFour.setPixelColor(7, 5, 0, 0);
    
    ringFour.show();
    
    delay (1000);
    
    //Turn it off

    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(12, 0, 0, 0);
    ringOne.setPixelColor(13, 0, 0, 0);
    ringOne.setPixelColor(14, 0, 0, 0);
    ringOne.setPixelColor(15, 0, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(0, 0, 0, 0);
    ringTwo.setPixelColor(6, 0, 0, 0);
    ringTwo.setPixelColor(11, 0, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(4, 0, 0, 0);
    ringThree.setPixelColor(9, 0, 0, 0);
    ringThree.setPixelColor(10, 0, 0, 0);
    ringThree.setPixelColor(11, 0, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 0, 0, 0);
    ringFour.setPixelColor(1, 0, 0, 0);
    ringFour.setPixelColor(2, 0, 0, 0);
    ringFour.setPixelColor(7, 0, 0, 0);
    
    ringFour.show();
    
    delay (1000);             

}

void displaySeven() {
  //Number 7

    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(1, 5, 0, 0);
    ringTwo.setPixelColor(10, 5, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(0, 5, 0, 0);
    ringThree.setPixelColor(8, 5, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(6, 5, 0, 0);
    ringFour.setPixelColor(7, 5, 0, 0);
    
    ringFour.show();
    
    delay (1000);
    
    //Turn it off

    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(1, 0, 0, 0);
    ringTwo.setPixelColor(10, 0, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(0, 0, 0, 0);
    ringThree.setPixelColor(8, 0, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(6, 0, 0, 0);
    ringFour.setPixelColor(7, 0, 0, 0);
    
    ringFour.show();
    
    delay (1000);      

}

void displayEight() {
  //Number 8

    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(9, 5, 0, 0);
    ringOne.setPixelColor(10, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(12, 5, 0, 0);
    ringOne.setPixelColor(13, 5, 0, 0);
    ringOne.setPixelColor(14, 5, 0, 0);
    ringOne.setPixelColor(15, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(5, 5, 0, 0);
    ringTwo.setPixelColor(11, 5, 0, 0);
    ringTwo.setPixelColor(14, 5, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(1, 5, 0, 0);
    ringThree.setPixelColor(3, 5, 0, 0);
    ringThree.setPixelColor(9, 5, 0, 0);
    ringThree.setPixelColor(11, 5, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 5, 0, 0);
    ringFour.setPixelColor(1, 5, 0, 0);
    ringFour.setPixelColor(7, 5, 0, 0);
    
    ringFour.show();
    
    delay (1000);
    
    //Turn it off

    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(9, 0, 0, 0);
    ringOne.setPixelColor(10, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(12, 0, 0, 0);
    ringOne.setPixelColor(13, 0, 0, 0);
    ringOne.setPixelColor(14, 0, 0, 0);
    ringOne.setPixelColor(15, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(5, 0, 0, 0);
    ringTwo.setPixelColor(11, 0, 0, 0);
    ringTwo.setPixelColor(14, 0, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(1, 0, 0, 0);
    ringThree.setPixelColor(3, 0, 0, 0);
    ringThree.setPixelColor(9, 0, 0, 0);
    ringThree.setPixelColor(11, 0, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 0, 0, 0);
    ringFour.setPixelColor(1, 0, 0, 0);
    ringFour.setPixelColor(7, 0, 0, 0);
    
    ringFour.show();
    
    delay (1000);    

}

void displayNine() {
  //Number 9

    ringOne.setPixelColor(0, 5, 0, 0);
    ringOne.setPixelColor(1, 5, 0, 0);
    ringOne.setPixelColor(2, 5, 0, 0);
    ringOne.setPixelColor(11, 5, 0, 0);
    ringOne.setPixelColor(22, 5, 0, 0);
    ringOne.setPixelColor(23, 5, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(2, 5, 0, 0);
    ringTwo.setPixelColor(7, 5, 0, 0);
    ringTwo.setPixelColor(14, 5, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(1, 5, 0, 0);
    ringThree.setPixelColor(2, 5, 0, 0);
    ringThree.setPixelColor(3, 5, 0, 0);
    ringThree.setPixelColor(4, 5, 0, 0);
    ringThree.setPixelColor(11, 5, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 5, 0, 0);
    
    
    ringFour.show();
    
    delay (1000);
    
    //Turn it off

    ringOne.setPixelColor(0, 0, 0, 0);
    ringOne.setPixelColor(1, 0, 0, 0);
    ringOne.setPixelColor(2, 0, 0, 0);
    ringOne.setPixelColor(11, 0, 0, 0);
    ringOne.setPixelColor(22, 0, 0, 0);
    ringOne.setPixelColor(23, 0, 0, 0);

    ringOne.show();
    
    ringTwo.setPixelColor(2, 0, 0, 0);
    ringTwo.setPixelColor(7, 0, 0, 0);
    ringTwo.setPixelColor(14, 0, 0, 0);

    ringTwo.show();

    ringThree.setPixelColor(1, 0, 0, 0);
    ringThree.setPixelColor(2, 0, 0, 0);
    ringThree.setPixelColor(3, 0, 0, 0);
    ringThree.setPixelColor(4, 0, 0, 0);
    ringThree.setPixelColor(11, 0, 0, 0);
    
    ringThree.show();
    
    ringFour.setPixelColor(0, 0, 0, 0);
    
    
    ringFour.show();
    
    delay (1000);

}

void patternTwo() {
  displayZero();
  displayOne();
  displayTwo();
  displayThree();
  displayFour();
  displayFive();
  displaySix();
  displaySeven();
  displayEight();
  displayNine();

}

void patternThree() {
  // Yellow smile face

  // Ring 1: circle
  for (int i = 0; i < ledCount1; i++) {
    ringOne.setPixelColor(i, ringOne.Color(25, 25, 0));
  }
  ringOne.show();

  // Ring 3: smile
  for (int j = 4; j < 9; j++) {
    ringThree.setPixelColor(j, ringThree.Color(25, 25, 0));
  }
  ringThree.show();

  // Ring 3: eyes
  ringThree.setPixelColor(2, ringThree.Color(25, 25, 0));
  ringThree.setPixelColor(10, ringThree.Color(25, 25, 0));
  ringThree.show();
  delay(2000);
}
