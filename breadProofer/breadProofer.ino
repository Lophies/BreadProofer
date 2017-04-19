#include <dht11.h>    //Uses the DHT11 Arduino library: http://playground.arduino.cc/Main/DHT11Lib

dht11 DHT11_1;
dht11 DHT11_2;
dht11 DHT11_3;

#define DHT11_1_PIN 2   //Arduino input pin for DHT11 sensor 1
#define DHT11_2_PIN 3   //Arduino input pin for DHT11 sensor 2
#define DHT11_3_PIN 4   //Arduino input pin for DHT11 sensor 3
#define RELAY_TEMP_1_PIN 5  //Arduino output pin that controls the heating elements 1-2 relay, connected to IN1 on the relay board
#define RELAY_TEMP_2_PIN 6  //Arduino output pin that controls the heating elements 3-4 relay, connected to IN2 on the relay board
#define RELAY_TEMP_3_PIN 7  //Arduino output pin that controls the heating elements 5-6 relay, connected to IN3 on the relay board
#define RELAY_HUM_PIN 8     //Arduino output pin that controls the humidifier relay, connected to IN4 on the relay board

float minHum = 60;
float maxHum = 80;
float minTemp = 30.3;     //Optimal growth temperature of Saccharomyces cerevisiae is 32.3°C (https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3067424/pdf/1861-10.pdf)
float maxTemp = 34.3;
int numSensors = 3;
int numMeasurements = 10;

void setup()
{
    pinMode(RELAY_TEMP_1_PIN, OUTPUT); //Set all relay pins as outputs
    pinMode(RELAY_TEMP_2_PIN, OUTPUT);
    pinMode(RELAY_TEMP_3_PIN, OUTPUT);
    pinMode(RELAY_HUM_PIN, OUTPUT);
    Serial.start(9600);     //Starting the serial console for graph output
}

void loop()
{
    float sumTemp = 0;    //Reset sumTemp at the start of each for loop
    float sumHum = 0;     //Reset sumHum at the start of each for loop
    for (int i = 0; i < numMeasurements; i++)    //Measure temperature and humidity (numMeasurements) times for each sensor
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

        sumTemp += temp1;
        sumTemp += temp2;
        sumTemp += temp3;
        sumHum += hum1;
        sumHum += hum2;
        sumHum += hum3;

        delay(1000);    //Length of the measuring interval / # of measurements
                        //Note: DHT11 has a 1 Hz sampling rate so the delay must be >= 1000 ms
    }

    float avgTemp = sumTemp / (numSensors * numMeasurements);   //Calculate the average temperature over the measuring interval (# of sensors * # of measurements)
    float avgHum = sumHum / (numSensors * numMeasurements );   //Calculate the average humidity over the measuring interval (# of sensors * # of measurements)

    //Serial output of the average temperature and average humidity values that can be plotted using the Arduino IDE's serial plotter
    Serial.print(avgTemp);
    Serial.print('\t');
    Serial.println(avgHum);

    if (avgTemp < minTemp) //Low temperature at which the heating elements turn on (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, LOW);
        digitalWrite(RELAY_TEMP_2_PIN, LOW);
        digitalWrite(RELAY_TEMP_3_PIN, LOW);
    }
    else if (avgTemp > maxTemp)   //High temperature at which the heating elements turn off (in °C)
    {
        digitalWrite(RELAY_TEMP_1_PIN, HIGH);
        digitalWrite(RELAY_TEMP_2_PIN, HIGH);
        digitalWrite(RELAY_TEMP_3_PIN, HIGH);
    }
    if (avgHum < minHum)  //Low humidity at which the humidifier turns on (in %)
    {
        digitalWrite(RELAY_HUM_PIN, LOW);
    }
    else if (avgHum > maxHum) //High humidity at which the humidifier turns off (in %)
    {
        digitalWrite(RELAY_HUM_PIN, HIGH);
    }
}
