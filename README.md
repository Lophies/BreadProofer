# BreadProofer
An Arduino-controlled bread proofing box that measures the temperature and humidity using DHT11 sensors and uses a relay board to drive a humidifier and heating elements to adjust the values accordingly.

## Hardware used:

- [Arduino Nano](https://www.amazon.de/dp/B06XR1PPCL/ref=pe_386171_37038021_TE_3p_dp_1) (1x)
- [SODIAL 5V 4-Channel Relay Module](https://www.amazon.de/dp/B00L8VFVTK) (1x)
    - Driver current: 15-20mA
    - Relay specs:  250V AC, 10A ; 30V DC, 10A
- [Ecloud Shop DHT11 sensor](https://www.amazon.de/dp/B01MQNMCKV) (3x)
    - Temperature: 0°C - 50°C (+/- 2°C)
    - Relative humidity: 20% - 95% (+/- 5%)
- [Heating elements](http://www.conrad.be/ce/nl/product/189297/Thermo-Verwarmingsfolie-Zelfklevend-230-V-65-W-Veiligheidstype-IPX4-l-x-b-300-mm-x-120-mm) (6x)
    - 230V, 65W max.
    - Surface temperature: 95°C
    - Size: 300 mm x 120 mm
- [Bionaire compact warm mist humidifier, model: CM1](http://www.bionaireeurope.com/Product.aspx?cid=1194&pid=7402) (1x)
    - 2.25 l Removable water tank
    - 4,8 l / 24 h warm mist output
    - 230V, 220W

## Connections:

Microcontroller/sensors/relay board power (5V): Ground and 5V lines go from the 5V @1A phone charger to an intermediary perfboard.
From here, the Arduino Nano is powered on its GND and Vin pins. The DHT11 sensors and the 4-channel relay board are powered from the perfboard to their GND and VCC lines.

Microcontroller/sensors/relay board data connections: The DATA lines on the 3 DHT11 sensors are connected to the MCU's pins 2, 3 and 4.
The IN1, IN2 and IN3 pins on the 4-channel relay board are connected to the MCU's pins 5, 6 and 7 (for the three pairs of heating elements), the IN4 pin on the relay board is connected to the MCU's pin 8 (for the humidifier).

Heating element power (230V): one wire each heating element power cable is connected to the main power cable. The other wires of elements 1 and 2 are joined and routed to the Normally Open (NO) contact of relay 1. Those of elements 3 and 4 are routed to the NO contact of relay 2. Those of 5 and 6 are route to the NO contact of relay 3. The Common (C) contacts of relays 1, 2 and 3 are wired to the other wire of the input power cable.

Humidifier power (230V): one of the wires of the humidifier power cable goes directly to the input power cable, the other of the two is connected to the NO contact of relay 4. The C contact of relay 4 is wired to the input power cable.

## Settings (to be verified empirically):

Humidity (min/max): 60% / 80%
The humidity levels are kept high to avoid the outer layer of the dough from cracking during the proofing process.

Temperature (min/max): 30.3°C / 34.3°C
The optimal growth temperature of Saccharomyces cerevisiae is 32.3°C. (https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3067424/pdf/1861-10.pdf)

## Current progress:

Done:
- Box (schematics TBD)
- Placement of humidifier
- Placement of heating elements (heat transfer might be insufficient so extra heat sinks may be needed to spread the heat)

To be done:
- Placement of 5V electronics
    - Arduino Nano
    - 4-channel relay board
    - DHT11 sensors
    - Connections from sensors to MCU
    - Connections from MCU to relay board
    -

- Placement of 230V electronics
    - 10A circuit breaker, used as main power switch
    - Power supply for 5V electronics (Motorola Pebl charger; 5V, 1000 mA)
    - Connections to heating elements
    - Connections to humidifier
    - Connections to outputs of relay board


## Pictures:

[![Imgur](http://i.imgur.com/R9KHoGP.jpg:large)](http://i.imgur.com/R9KHoGP.jpg)
