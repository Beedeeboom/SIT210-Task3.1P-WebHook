#include <Adafruit_DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT22

String tempData;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    dht.begin();

}

void loop() {
    
    //delay data collection by 5 seconds
    delay(5000);
    
    //collect the data in celcius 
    float temperature = dht.getTempCelcius(); 
    
    //output the data in specified format
    tempData = String::format ("%.1f °C", temperature);
    
    //publish data to particle console
    Particle.publish("roomTemperature", tempData);

}