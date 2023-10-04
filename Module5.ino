//add current time variable
unsigned long currentTime;

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);

  //add header
Serial.println("ms,degC");

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
 void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  
  sensors.requestTemperatures(); // Send the command to get temperatures
  
    //add line to record current time 
  currentTime=millis(); 
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

     Serial.print(currentTime);
     Serial.print(",");
     Serial.println(tempC);

    if (currentTime > 100000){
      exit(0);
    }
    