#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
char buffer[40];
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int trigPin = 10;
const int echoPin = 9;

// defines variables
long duration;
int distance;
unsigned long currentMillis=0;
 int diff=0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000; // interval of 1000ms (1 second)
#include <Servo.h>
long cnt=0;
int dis=0;
int pdis=0;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
    lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(A0, OUTPUT);
      
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object

    digitalWrite(A0, HIGH);delay(200);
      digitalWrite(A0, LOW);delay(200);
        digitalWrite(A0, HIGH);delay(200);
          digitalWrite(A0, LOW);delay(200);
}

void loop() {
     
      
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);   
      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor


  if((distance>5)&&(distance<30)){  //data(pos+13 , 0);
cnt++;
    Serial.print("Distance: ");
  Serial.println(distance);
      Serial.print("angle: ");
  Serial.println(pos+10);

  }// waits 15 ms for the servo to reach the position
    currentMillis = millis();
    if (currentMillis - previousMillis >= 500) {
    previousMillis = currentMillis;
            Serial.print("cnt: ");
  Serial.println(cnt);
        Serial.println(" ");        if(cnt>=5){
          

          
    digitalWrite(A0, HIGH);delay(200);
      digitalWrite(A0, LOW);delay(200);
        digitalWrite(A0, HIGH);delay(200);
          digitalWrite(A0, LOW);delay(200);


       myservo.write(pos+1); delay(50);
        myservo.write(pos+2); delay(50);
        myservo.write(pos+3); delay(50);
        myservo.write(pos+4); delay(50);
        myservo.write(pos+5); delay(50);
        myservo.write(pos+6); delay(50);
        myservo.write(pos+7); delay(50);
        myservo.write(pos+8); delay(50);lcd.clear();
     lcd.setCursor(0,0);
  lcd.print("OBJECT DETECTED");
      digitalWrite(A0, HIGH);delay(200);
      digitalWrite(A0, LOW);delay(200);
        digitalWrite(A0, HIGH);delay(200);
          digitalWrite(A0, LOW);delay(200);
    delay(2000);lcd.clear();
          
          data(pos+11,1);
        }
   cnt=0;
  }
    lcd.setCursor(0,0);
        lcd.print("Angle - ");  
         sprintf(buffer, "%3u",pos);
        lcd.print(buffer);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);  
      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor


  if((distance>5)&&(distance<30)){
cnt++;
 //   data(pos+13 , 1);
    Serial.print("Distance: ");
  Serial.println(distance);
      Serial.print("angle: ");
  Serial.println(pos+10);

        Serial.println(" ");

  }// waits 15 ms for the servo to reach the position
 currentMillis = millis();
  if (currentMillis - previousMillis >= 500) {
    previousMillis = currentMillis;
            Serial.print("cnt: ");
  Serial.println(cnt);
        Serial.println(" ");
        if(cnt>=5){
           myservo.write(pos-1); delay(50);
        myservo.write(pos-2); delay(50);
        myservo.write(pos-3); delay(50);
        myservo.write(pos-4); delay(50);
        myservo.write(pos-5); delay(50);
        myservo.write(pos-6); delay(50);
        myservo.write(pos-7); delay(50);
        myservo.write(pos-8); delay(50);lcd.clear();
     lcd.setCursor(0,0);
        lcd.print("OBJECT DETECTED");
            digitalWrite(A0, HIGH);delay(200);
      digitalWrite(A0, LOW);delay(200);
        digitalWrite(A0, HIGH);delay(200);
          digitalWrite(A0, LOW);delay(200);
    delay(2000);lcd.clear();
     
          data(pos+11,1);
        }
   cnt=0;
  }

    lcd.setCursor(0,0);
        lcd.print("Angle - ");  
         sprintf(buffer, "%3u",pos);
        lcd.print(buffer);
  }





  
}

void data(int angle, int dir){

  int ct=0;
  while(1){


    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    ct++;
    previousMillis = currentMillis;



              // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
dis =distance;


diff = pdis - dis;


float speeed = (diff);
pdis=dis;
   Serial.print("speed: ");
  Serial.println(speeed);
      Serial.print("angle: ");
  Serial.println(angle);
      Serial.print("Distance: ");
  Serial.println(diff);

      Serial.println("  ");
lcd.clear();
             lcd.setCursor(0,0);
  lcd.print("angle ");lcd.print(angle);lcd.print(" "); lcd.print("Dis ");lcd.print(dis);lcd.print("cm");

         lcd.setCursor(0,1);
  lcd.print("speed ");lcd.print(speeed); lcd.print(" cm/s ");
  
 if(ct>20){lcd.clear();
  return;
 }
  }


 
  }
}
