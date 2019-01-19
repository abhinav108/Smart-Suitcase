#include <AFMotor.h>
int ledPin = 13;


AF_DCMotor right_motor(1, MOTOR12_8KHZ);
AF_DCMotor left_motor(2, MOTOR12_8KHZ);
AF_DCMotor right_motorlock(1, MOTOR12_8KHZ);
AF_DCMotor left_motorlock(2, MOTOR12_8KHZ);

char readString='0';


void setup() {
  Serial.begin(9600);

}

void loop()
{



  if (Serial.available()>0)
  /*{
    delay(50);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString);
    //lightoff and speed high*/
  {readString=Serial.read();
    if (readString == 'a') {
      right_motor.setSpeed(255);
      left_motor.setSpeed(255);
      right_motor.run(FORWARD);
      left_motor.run(FORWARD);
      delay(500);
    }
    //right
    if (readString == 'b') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
    }
    //stop
    if (readString == 'c') {
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
    }
    //left
    if (readString == 'd') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);

      delay(500);


    }
    //back
    if (readString == 'e') {
      right_motor.setSpeed(255);
      left_motor.setSpeed(255);
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);

      delay(500);
    }







    
    //light on and speed high

    if (readString == 'f') {
      right_motor.setSpeed(255);
      left_motor.setSpeed(255);
      right_motor.run(FORWARD);
      left_motor.run(FORWARD);
      digitalWrite(13, HIGH);
      delay(500);
    }
    //right
    if (readString =='g') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      digitalWrite(13, HIGH);
      delay(500);

    }
    //stop
    if (readString == 'h') {
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      digitalWrite(13, HIGH);

      delay(500);
    }
    //left
    if (readString == 'i') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);

      digitalWrite(13, HIGH);

      delay(500);


    }
    //back
    if (readString == 'j') {
      right_motor.setSpeed(255);
      left_motor.setSpeed(255);
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);

      digitalWrite(13, HIGH);

      delay(500);
    }







    

    //////////lock open

    if (readString == 'k') {
      right_motorlock.setSpeed(100);
      left_motorlock.setSpeed(100);
      right_motorlock.run(FORWARD);
      left_motorlock.run(FORWARD);
      delay(500);
    }
    //////////lock close
    if (readString == 'l') {
      right_motorlock.setSpeed(80);
      left_motorlock.setSpeed(80);
      right_motorlock.run (BACKWARD);
      left_motorlock.run (BACKWARD);
    }
// ////// lock stop 
if (readString == 'm') {
      right_motorlock.run (RELEASE);
      left_motorlock.run (RELEASE);
    }






    
    //left
    if (readString == 'n') {
      right_motor.setSpeed(80);
      left_motor.setSpeed(80);
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);

      delay(500);


    }
    //back
    if (readString == 'o') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);

      delay(500);
    }
    // speed low light on

    if (readString == 'p') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run(FORWARD);
      left_motor.run(FORWARD);
      digitalWrite(13, HIGH);
      delay(500);
    }
    //right
    if (readString == 'q') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      digitalWrite(ledPin, HIGH);
      delay(500);

    }
    //stop
    if (readString == 'r') {
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      digitalWrite(13, HIGH);

      delay(500);
    }
    //left
    if (readString == 's') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);

      digitalWrite(ledPin, HIGH);

      delay(500);


    }
    //back
    if (readString == 't') {
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);
      digitalWrite(ledPin, HIGH);

      delay(500);
    }
    //line follower;
    if (readString == 'u') {

      for (int ia = 1; ia <= 300; ia++) {
        #define left A4
        #define right A0

        pinMode(left, INPUT);
        pinMode(right, INPUT);
        Serial.println("working");


        right_motor.setSpeed(255);
        left_motor.setSpeed(255);
        //values printing
        Serial.println(analogRead(left));
        Serial.println(analogRead(right));
        //line detected by both
        if (analogRead(left) <= 400 && analogRead(right) <= 400) {
         right_motor.run(FORWARD);
          left_motor.run(FORWARD);
          Serial.println("working");
        }

        else if (analogRead(left) <= 400 && !analogRead(right) <= 400) {
          Serial.println("left");
          Serial.println("workingb");

          right_motor.run(FORWARD);
          left_motor.run(BACKWARD);

        }
        //line detected by riht sensor
        else if (!analogRead(left) <= 400 && analogRead(right) <= 400) {
          Serial.println("right");
          right_motor.run(BACKWARD);
          Serial.println("workinga");
          left_motor.run(FORWARD);
        }
        //line detected by none
        else if (!analogRead(left) <= 400 && !analogRead (right) <= 400) {
          Serial.println("sto");
          right_motor.run(RELEASE);
          Serial.println("workinga");

          left_motor.run(RELEASE);
        }



      }
    }
    if (readString == 'v') {
      right_motor.run(RELEASE);
      left_motor.run(RELEASE);

    }

    if (readString == 'x') {
      digitalWrite(13, HIGH);

    }
    if(readString=='y'){
   right_motor.setSpeed(255);
    left_motor.setSpeed(255);}
      if(readString=='z'){
      right_motor.setSpeed(100);
      left_motor.setSpeed(100);}
    
    if (readString == 'w') {
      digitalWrite(13, LOW);
    }
    Serial.println(readString);

    //readString = "";
  }






}
