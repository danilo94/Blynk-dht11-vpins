#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
char auth[] = "";
char ssid[] = "";
char pass[] = "";
BlynkTimer timer;

float humidity=0;
float temperature=0;

void myTimerEvent()
{
  updateDataSensor();
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V1, temperature);
}

void setup()
{

  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void updateDataSensor(){
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
}
