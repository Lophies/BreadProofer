#include <dht11.h>    //Uses the DHT11 Arduino library: http://playground.arduino.cc/Main/DHT11Lib

dht11 DHT11_1;
dht11 DHT11_2;
dht11 DHT11_3;

#define DHT11_1_PIN 2   //Arduino input pin for DHT11 sensor 1
#define DHT11_2_PIN 3   //Arduino input pin for DHT11 sensor 2
#define DHT11_3_PIN 4   //Arduino input pin for DHT11 sensor 3
#define RELAY_TEMP_1_PIN 5  //Arduino output pin that controls the heating element 1 relay
#define RELAY_TEMP_2_PIN 6  //Arduino output pin that controls the heating element 2 relay
#define RELAY_HUM_PIN 7     //Arduino output pin that controls the humidifier relay

float minHum = 60;
float maxHum = 80;
float minTemp = 35;
float maxTemp = 40;
int numSensors = 3;
int numMeasurements = 10;

void setup()
{
    pinMode(5, OUTPUT); //Set all relay pins as outputs
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    float sumTemp = 0;    //Reset sumTemp at the start of each for loop
    float sumHum = 0;     //Reset sumHum at the start of each for loop
    for (int i = 0; i < numMeasurements; i++)    //Measure temperature and humidity 10 times for each sensor
    {
        DHT11_1.read(DHT11_1_PIN);    //Read sensor 1
        float temp1 = DHT11_1.temperature;
        float hum1 = DHT11_1.humidity;

        DHT11_2.read(DHT11_2_PIN);    //Read sensor 2
        float temp2 = DHT11_2.temperature;
        float hum2 = DHT11_2.humidity;

        DHT11_3.read(DHT11_3_PIN);    //Read sensor 3
        float temp3 = DHT11_3.temperature;
        float hum3 = DHT11_3.humidity;

        sumTemp += temp1 += temp2 += temp3;
        sumHum += hum1 += hum2 += hum3;

        delay(1000);    //Length of the measuring interval / # of measurements
                        //Note: DHT11 has a 1 Hz sampling rate so the delay must be >= 1000 ms
    }

    float avgTemp = sumTemp / (numSensors * numMeasurements);   //Calculate the average temperature over the measuring interval (# of sensors * # of measurements)
    float avgHum = sumHum / (numSensors * numMeasurements );   //Calculate the average humidity over the measuring interval (# of sensors * # of measurements)

    if (avgTemp < minTemp) //Low temperature at which the heating elements turn on (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, HIGH);
        digitalWrite(RELAY_TEMP_2_PIN, HIGH);
    }
    else if (avgTemp > maxTemp)   //High temperature at which the heating elements turn off (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, LOW);
        digitalWrite(RELAY_TEMP_2_PIN, LOW);
    }
    if (avgHum < minHum)  //Low humidity at which the humidifier turns on (in %)
    {
        digitalWrite(RELAY_HUM_PIN, HIGH);
    }
    else if (avgHum > maxHum) //High humidity at which the humidifier turns off (in %)
    {
        digitalWrite(RELAY_HUM_PIN, LOW);
    }
}
