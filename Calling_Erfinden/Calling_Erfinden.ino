//ERFINDER CODE
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int Temp = 28;
int h = 23;
int num = 0;

#define trigPin 3
#define echoPin 2
void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(100);
  pinMode(34, OUTPUT);
  pinMode(30, OUTPUT);
digitalWrite(13, HIGH);

Serial.begin(9600);
Serial.println("LED is HIGH");
mySerial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

}

void loop() // run over and over
{
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
Serial.println("Calling through GSM Modem");

// set the data rate for the SoftwareSerial port
mySerial.begin(9600);
delay(2000);
//mySerial.println("ATD9435660815;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
/* if(distance < 5 ) {
  Serial.println("Sending Message");
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Some one entered your field.");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z, To end the process of seding messgage
  delay(1000);
  } */
  if(Temp > 30 ) {
  Serial.println("Sending Message");
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("There might be chance of fire.");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
mySerial.println("ATA");
Serial.println("Getting Response:");
delay(1000);
Serial.println("Reading Response:");
a = digitalRead(22);
b = 2*digitalRead(24);
c = 4*digitalRead(26);
d = 8*digitalRead(28);
num = a+b+c+d;
int o = digitalRead(32);
//32 for status of power;
      if(num !=0) {
         Serial.print("Response ");
         Serial.println(num);
         switch(num) {
          case 1:
             digitalWrite(30, HIGH);
             delay(1000);
             digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
             mySerial.println("ATH");
             break;

          case 2: 
             digitalWrite(30, LOW);     
             delay(100);
             digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
             //mySerial.println("ATH");
             break;

         case 3:
             Serial.println("Power status");
             
              digitalWrite(34, HIGH);
             delay(1000);
             digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
             mySerial.println("ATH");
             break;
             if ( o == 1) {
              /*Serial.println("I have power");
              Serial.println("Sending Message");
               mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println("Have power.");// The SMS text you want to send
            delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(2000);
              mySerial.println("ATH");
               digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);   
              */}  

             else { /*
              Serial.println("I don't have power");
              mySerial.println("ATH");
              digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
             Serial.println("Sending Message");
               mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println("NO power.");// The SMS text you want to send
            delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(2000); */
              
              } 
              break;
          case 4: 
             digitalWrite(34, LOW);
             delay(1000);
             digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
             mySerial.println("ATH");
             break;

             case 5: 
             digitalWrite(34, HIGH);
             digitalWrite(30, HIGH);
             delay(100);
             digitalWrite(13,LOW);
             delay(100);
             digitalWrite(13,HIGH);
             mySerial.println("ATH");
             break;
             case 6: 
             digitalWrite(34, LOW);
             digitalWrite(30, LOW);
             delay(100);
             digitalWrite(13,LOW);
             delay(100);
             digitalWrite(13,HIGH);
             mySerial.println("ATH");
             break;
            /* Serial.println("Sending temprature values");
            mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println(Temp);// The SMS text you want to send
            delay(100);
         mySerial.println((char)26); 
         mySerial.println("ATH");
              digitalWrite(13,LOW);
             delay(1000);
             digitalWrite(13,HIGH);
            */
              break;
          /* case 5: 
            //Humiidty
              break;
          case 6: 
            // Moisture
              break;
          case 7: 
            //For this time motor should be on!!
              break;
          case 8: 
              break;
          case 9: 
              break;
          case 10: 
              break;
          */
          case 11: 
          digitalWrite(13,LOW);
          delay(1000);
          digitalWrite(13,HIGH);   
          int j;
          int lol[3];
          Serial.println("Waiting for 3 more inputs");
          for(j=0;j<3;j++){
          a = digitalRead(22);
          b = 2*digitalRead(24);
          c = 4*digitalRead(26);
          d = 8*digitalRead(28);
         lol[j] = a+b+c+d;
          delay(2000);
           digitalWrite(13,LOW);
          delay(500);
          digitalWrite(13,HIGH);  
          }
          delay(1000);
          mySerial.println("ATH");
          int k = 100 * lol[0] + 10 * lol[1] + lol[2];
          int i;
         
          for(i=0; i<k;i++) {
            digitalWrite(30, HIGH);
            delay(1000);
            
          }
           digitalWrite(30, LOW);
            Serial.println("TAsk DOne" );
            Serial.println("Sending Message");
               mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
                delay(1000);  // Delay of 1000 milli seconds or 1 second
                mySerial.println("AT+CMGS=\"+917086867361\"\r"); // Replace x with mobile number
              delay(1000);
           mySerial.println("Your Task is completed");// The SMS text you want to send
            delay(100);
         mySerial.println((char)26);

            
               break;
         /* case 12: 
                break; */
          } 
          
          
          
   
          
          delay(100);
      }

   

// print response over serial port

} 
