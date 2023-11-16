My Atmega32-based temperature meter project offers the following features:

- Measurement of temperatures ranging from −55°C to 150°C.
- Capability to handle negative temperatures.
- Detection and indication of temperature conditions.
- An alarm system triggered at high temperatures, serving as a fire indicator.

Key hardware components include:
1. LM35 Temperature Sensor
2. 2X16 LCD Display
3. Internal ADC
4. Atmega32 Microcontroller
5. Buzzer
6. LED

The software program is structured into three layers:
1. MCAL Layer, encompassing GPIO functionalities.
2. HAL Layer, which integrates modules for LCD, ADC, LED, and buzzer.
3. Application Layer, managing the overall application logic.

In the operational process, the temperature sensor captures temperature as an analog signal. The internal ADC then converts this signal into a digital format. The resulting digital signal is interpreted to identify the voltage initially detected by the temperature sensor. This voltage is further processed through a coded equation to obtain a decimal value, which is finally displayed on the LCD screen.
