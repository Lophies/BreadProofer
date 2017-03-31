#include <dht11.h>

dht11 DHT11_1;
dht11 DHT11_2;
dht11 DHT11_3;

#define DHT11_1_PIN 2   //Arduino input pin for DHT11 sensor 1
#define DHT11_2_PIN 3   //Arduino input pin for DHT11 sensor 2
#define DHT11_3_PIN 4   //Arduino input pin for DHT11 sensor 3
#define RELAY_TEMP_1_PIN 5  //Arduino output pin that controls the heating element 1 relay
#define RELAY_TEMP_2_PIN 6  //Arduino output pin that controls the heating element 2 relay
#define RELAY_HUM_PIN 7     //Arduino output pin that controls the humidifier relay

void setup()
{
    pinMode(5, OUTPUT); //Set all relay pins as outputs
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    float sumtemp = 0;    //Reset sumtemp at the start of each for loop
    float sumhum = 0;     //Reset sumhum at the start of each for loop
    for (int i = 0; i < 10; i++)    //Measure temperature and humidity 10 times for each sensor
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

        sumtemp += temp1 += temp2 += temp3;
        sumhum += hum1 += hum2 += hum3;

        delay(1000);    //Length of the measuring interval / # of measurements
                        //Note: DHT11 has a 1 Hz sampling rate so the delay must be >= 1000 ms
    }

    float avgtemp = sumtemp / 30;   //Calculate the average temperature over the measuring interval (# of sensors * # of measurements)
    float avghum = sumhum / 30;   //Calculate the average humidity over the measuring interval (# of sensors * # of measurements)

    if (avgtemp < 35) //Low temperature at which the heating elements turn on (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, HIGH);
        digitalWrite(RELAY_TEMP_2_PIN, HIGH);
    }
    else if (avg temp > 38)   //High temperature at which the heating elements turn off (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, LOW);
        digitalWrite(RELAY_TEMP_2_PIN, LOW);
    }
    if (avghum < 60)  //Low humidity at which the humidifier turns on (in %)
    {
        digitalWrite(RELAY_HUM_PIN, HIGH);
    }
    else if (avghum > 80) //High humidity at which the humidifier turns off (in %)
    {
        digitalWrite(RELAY_HUM_PIN, LOW);
    }
}
