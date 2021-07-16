/********************************Description of this project****************************************************/
Object etectidon and Collision Avoidance using IR Sensor, Arduino and ESP8266

working:-
This project is to show how to communicate between devices(uart,spi,i2c,mqtt) and then with cloud(for sensor data)
there are two part of this project i,e arduino(main code) and esp8266(cloud communication)

part 1:- arduino using ir sensor detects object detection and sends the data to esp8266(for cloudusing MQTT) and stores an offline copy(sd card using spi)
and display the message locally(on lcd using i2c ) with sound alert

part 2:-
here esp8266 receives the data from arduino and when ever it senses it just upload to the cloud with timestamp 
and retrieves the data with the help of desktop app /python code
/********************************************end of description of project*************************************/



/*********************************************Hardware Required *******************************************************/
Arduino UNO-1
ESP8266-1
IR sensor-1
SDcard module with sdcard-1
Buzzer-1
LCD display(i2c supported)-1
Jumper wires both male to male and male to female
Bread Board -1  
/*************************************end of hardware required********************************************************/


/********************************************Software Required********************************************************/
arduino ide
cloud account(here ask sensors account is used)
/**********************************************end of software required*********************************************/


/********************************************************************how to use *********************************************/
how to use 
1)find the i2c address of the lcd usind i2c scanner code i,e connect the lcd and upload the code in arduino board in serial monitor it shows you the address 
of i2c device note it down

2) upload irdev code to arduino board

3)upload node mcu code to esp8266(dont forget to fill your wifi ssid(name),password,cloudaccountapi,port number you are free to use)

4)now make the hardware connections as per schematics

5)now check serial monitors of both the codes,cloud account,and compare same data is being replicated or not

6)use the retrival code for offline visulazation /analytics purposes
/**********************************************************************End of how to use*********************************************/

/*******************************************hardware connections*******************************************************/
SPI:-

MOSI - pin 11
MISO - pin 12
CLK - pin 13
CS - pin 5
vcc /pwr -3.3V
gnd gnd of uno

UART:-
TX pin of arduino to esp8266 RX pin 
RX pin of arduino to esp8266 TX pin

I2C:-
pwr/Vcc +5V/3.3V
gnd gnd of uno
sda A4
scl A5

BUZZER:-
positive terminal - (uno) pin6
negative terminal -(uno) gnd 

/**************************************************end of hardware connections******************************/

Reference links :-
https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
https://www.instructables.com/Micro-SD-Card-Tutorial/
ask sensors tutorials


/**************************************************future implemenatation************************************/
1)implementing using stm board for developing a mini autopilot with 8-10 sensors
2)implementing motor control for user end
/***********************************************************************************************************/
