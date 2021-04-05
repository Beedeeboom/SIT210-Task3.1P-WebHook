#include <Adafruit_DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    dht.begin();

}

void loop() {
    
    //collect the data in celcius 
    float temperature = dht.getTempCelcius(); 
    
    //output the data in specified string format
    String temp = String::format ("%.1f C", temperature);
    
    //publish data to particle console
    Particle.publish("temperature", temp, PRIVATE);
    
    //wait 30 seconds
    delay(30000);

}
