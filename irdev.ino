
/*spi configuration
** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 5
end of spi configuration*/

/*i2c configuration*/



#include<SPI.h>
#include<SD.h>
//#include<Wire.h>

const int ir=4;
const int cS=5;
const int Buzzer=6;
void setup() {
  // put your setup code here, to run once:
pinMode(Buzzer,OUTPUT);
/*esp8266(uart) initilazation*/
pinMode(13,OUTPUT);
pinMode(ir,INPUT);
Serial.begin(115200);
Serial.print("ir detection using uart between arduino and node mcu\n");
delay(2500);
/*end of esp8266(uart) initilazation*/

/*************************************************************************************************/

/*sd card(spi) initaluization*/
 if (!SD.begin(cS)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
/*end of sd card initilazation(spi)*/
delay(2500);
}

/*************************************************************************************************/
/*lcd(I2C) initilazation*/

/*end of lcd(i2C) inilatization*/


void loop() {
  // put your main code here, to run repeatedly:
/*uart communication to node mcu */
if(digitalRead(ir)==HIGH)
{
digitalWrite(13,LOW);
Serial.println("free to go ");
}
else
{
 digitalWrite(13,HIGH);
 Serial.println("object detected please hold");
}
/*uart code end*/

/* sd card(spi code)*/

File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(ir);
    dataFile.close();
    // print to the serial port too:
    Serial.println("data saved succesfully");
  }
  // if the file isn't open, pop up an error:
  else {
    //Serial.println("error opening datalog.txt");
  }

}
