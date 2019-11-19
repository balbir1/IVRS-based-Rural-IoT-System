#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int Temp = 28;
int h = 23;
int num = 0;
char lol;
#define trigPin 3
#define echoPin 2
void setup()
{    pinMode(8, OUTPUT);
     pinMode(11, OUTPUT);
     pinMode(12, OUTPUT);
     pinMode(26, OUTPUT);
     pinMode(27, OUTPUT);
     pinMode(4, INPUT);
     pinMode(5, INPUT);
     pinMode(6, INPUT);
     pinMode(7, INPUT);
     pinMode(13, INPUT);
     pinMode(11, OUTPUT); 
     digitalWrite(8, LOW);
     delay(100);
     
     digitalWrite(25, HIGH);
     digitalWrite(8, HIGH);
     Serial.begin(9600);
     Serial.println("LED is HIGH");
     mySerial.begin(9600);
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(1000); 
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Final distance:");
  Serial.println(distance);
  
  mySerial.begin(9600);
  delay(2000); 
  digitalWrite(25, LOW);
  delay(100);
 mySerial.println("ATA");
  digitalWrite(25, HIGH);
  int o = digitalRead(13);
 /* if(mySerial.available() > -1 ){
    Serial.write(mySerial.read());
    Serial.println("hishkksfj");
    } */
//  digitalWrite(25, LOW);
  delay(100);
  digitalWrite(25, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  //Serial.println(lol);
  delay(100);
  Serial.println("Getting Response:");
  delay(1000);
  Serial.println("Reading Response:");
  a = digitalRead(4);
  b = 2*digitalRead(5);
  c = 4*digitalRead(6);
  d = 8*digitalRead(7);
  num = a+b+c+d;
  Serial.println(num);
  if(num != 0) {
    switch(num) {
      case 1:
        digitalWrite(11, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        mySerial.println("ATH");
        break;
      case 2:
        digitalWrite(11, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        mySerial.println("ATH");
        break;
      case 3:
        digitalWrite(27, HIGH);
        digitalWrite(26, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(27, LOW);
        digitalWrite(26, LOW);
        
        mySerial.println("ATH");
        if ( o == 1) {
              Serial.println("I have power");
              Serial.println("Sending Message");
               mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917002528736\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println("Have power.");// The SMS text you want to send
            delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(2000);
              mySerial.println("ATH");
               digitalWrite(8,LOW);
             delay(1000);
             digitalWrite(8,HIGH);   
              }  

             else { 
              Serial.println("I don't have power");
              mySerial.println("ATH");
              digitalWrite(8,LOW);
             delay(1000);
             digitalWrite(8,HIGH);
             Serial.println("Sending Message");
               mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917002528736\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println("NO power.");// The SMS text you want to send
            delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(2000); 
              
              } 
              break;
      case 4:
        digitalWrite(27, HIGH);
        digitalWrite(26, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(27, LOW);
        digitalWrite(26, LOW);
        mySerial.println("ATH");
        break;  
     case 5:
        digitalWrite(12, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        mySerial.println("ATH");
        break;
      case 6:
        digitalWrite(12, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        mySerial.println("ATH");
        break;             
     case 7:
        digitalWrite(11, LOW);
        digitalWrite(12-lllll,,mlllllllllllllllAZsAQQA, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        mySerial.println("ATH");
        break;                
      
      
      
      }
   
    
    }






   

}
