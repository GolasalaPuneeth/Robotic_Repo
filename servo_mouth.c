#include <Servo.h>
// creating a servo object
Servo myservo;

int ServoPin = 9;
int SoundInPin = A2;

void setup()
{

    Serial.begin(115200);
    myservo.attach(ServoPin);
    pinMode(SoundInPin, INPUT);
}

void loop()
{
    int sensorValue = analogRead(SoundInPin);
    Serial.println("sensor value ...");
    Serial.println(sensorValue);
    sensorValue = map(sensorValue, 0, 40, 90, 130);
    Serial.println("sensor value after mapping ...");
    
    myservo.write(90);
   sensorValue=sensorValue+7;
   Serial.println(sensorValue);
    if (sensorValue > 110 && sensorValue <140)
    {
        for (short i = 90; i <= sensorValue; i++)
        {
            myservo.write(i);
            delay(5);
        }
    

        for (short j = sensorValue; j >= 90; j--)
        {
            myservo.write(j);
            delay(5);
        }
   
}
}
