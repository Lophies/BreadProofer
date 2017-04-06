# BreadProofer
A program to control the temperature and humidity inside a bread proofing box using 3 DHT11 sensors and relays to drive a humidifier and 2 heating elements.

## Hardware used:

- [Arduino Nano](https://www.amazon.de/dp/B06XR1PPCL/ref=pe_386171_37038021_TE_3p_dp_1) (1x)
- [SODIAL 5V 4-Channel Relay Module](https://www.amazon.de/dp/B00L8VFVTK) (1x)
- [Ecloud Shop DHT11 sensor](https://www.amazon.de/dp/B01MQNMCKV) (3x)
- [Heating elements](http://www.conrad.be/ce/nl/product/189297/Thermo-Verwarmingsfolie-Zelfklevend-230-V-65-W-Veiligheidstype-IPX4-l-x-b-300-mm-x-120-mm) (6x)
- [Bionaire compact warm mist humidifier, model: CM1](http://www.bionaireeurope.com/Product.aspx?cid=1194&pid=7402) (1x)
      * 2.25 l Removable water tank
      * 4,8 l /24 h warm mist output
      * 220W

## Connections:

Ground and 5V lines go out from the Arduino Nano to the GND and VCC of each DTH11-sensor, as well as to the GND and VCC of the relay module.
The DATA pins on the 3 DHT11 sensors are connected to the MCU's pins 2, 3 and 4.
The IN1, IN2 and IN3 pins on the 4-channel relay board are connected to the MCU's pins 5, 6 and 7.
The IN4 pin on the relay board is connected to the MCU's pin 8.

The power cords of the 6 heating elements are cut and one wire of each pair is directly routed to the input power cable.
The other wires of elements 1 and 2 are joined and routed to the Normally Open (NO) contact of relay 1. Those of elements 3 and 4 are routed to the NO contact of relay 2. Those of 5 and 6 are route to the NO contact of relay 3. The Common contacts of relays 1, 2 and 3 are wired to the other wire of the input power cable.

As I want to keep the humidifier's power cable intact, an extension cord is used: one of the wires of the extension cord goes directly to the input power cable, the other of the two is connected to the NO contact of relay 4. The Common contact of relay 4 is wired to the input power cable.
