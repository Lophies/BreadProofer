#include <dht11.h>

dht11 DHT11_1;
dht11 DHT11_2;
dht11 DHT11_3;

#define DHT11_1_PIN 2   //First DHT11 sensor pin
#define DHT11_2_PIN 3   //Second DHT11 sensor pin
#define DHT11_3_PIN 4   //Third DHT11 sensor pin

void setup()
{
}

void loop()
{
  float sumtemp = 0;    //Reset sumtemp at the start of each for loop
  float sumhum = 0;     //Reset sumhum at the start of each for loop
  for (int i = 0; i < 10; i++)
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

    delay(1000);    //Sets the length of the measuring interval / 10
  }

  float avgtemp = sumtemp / 30;   //Calculate the average temperature over the measuring interval (# of sensors * # of measurements)
  float avghum = sumhum / 30;   //Calculate the average humidity over the measuring interval (# of sensors * # of measurements)
}
