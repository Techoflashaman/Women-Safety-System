/*
Author: Mohd Aman Ansari
embed
https://embed.org.in
*/

#define push = 2;
#define rx = tx;
#define tx = rx;
#define BUZZER 4

int state = 0;
const int pin = 2;
void setup()
{
 

  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
 
}

void loop()
{
  if (digitalRead(pin) == HIGH && state == 0) 
  {
    digitalWrite(BUZZER, HIGH);
    delay(10000);
    digitalWrite(BUZZER, LOW);
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    
    //Replace XXXXXXXXXX to 10 digit mobile number
    Serial.print("AT+CMGS=\"+915555555555\"\r");
    delay(1000);
    
    //The text of the message to be sent.
    Serial.print("I need help......");
    Serial.print("https://maps.app.goo.gl/ofbCDdM6CWFsXuPn8.......");
    Serial.print("Latitude : ........ Longitude : ........");
    Serial.write(0x1A);
    delay(1000);
    state = 1;
  }
  
 if (digitalRead(pin) == LOW && state == 1) 
 {
    state = 0;
    
  }
}
