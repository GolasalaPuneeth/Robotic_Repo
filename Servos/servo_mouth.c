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
    int sensor_Value = map(sensorValue, 0, 250, 90, 0);
    // Serial.println("sensor value after mapping ...");
    Serial.println(sensor_Value);
    if (sensor_Value < 80 && sensor_Value > 65)
    {
        //sensor_Value = sensor_Value - 7;
        for (short i = 90; i >= sensor_Value; i--)
        {
            myservo.write(i);
            delay(12);
        }
        for (short j = sensor_Value; j <= 90; j++)
        {
            myservo.write(j);
            delay(12);
        }
    }
}