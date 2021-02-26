/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "I_BSjdz7ieyuh-vSaqlN-82erlItCfm5";
char ssid[] = "Pentea's WiFi";
char pass[] = "@p@teului26A!";

int relayBedroom1_1 = 15; // for ESP32 microcontroller
int relayBedroom1_2 = 2; // for ESP32 microcontroller

int relayBedroom2_1 = 0; // for ESP32 microcontroller
int relayBedroom2_2 = 4; // for ESP32 microcontroller

int relayBedroom3_1 = 16; // for ESP32 microcontroller
int relayBedroom3_2 = 17; // for ESP32 microcontroller



#define DHTTYPE DHT11 // DHT 11
#define DHTPIN 21 // Digital pin connected to the DHT sensor
#define DHTPIN 22 // Digital pin connected to the DHT sensor
#define DHTPIN 23 // Digital pin connected to the DHT sensor
#define DHTPIN 34 // Digital pin connected to the DHT sensor
#define DHTPIN 35 // Digital pin connected to the DHT sensor

DHT dht(21, DHTTYPE);
DHT dht2(22, DHTTYPE);
DHT dht3(23, DHTTYPE);
DHT dht4(34, DHTTYPE);
DHT dht5(35, DHTTYPE);

BlynkTimer timer;

void sensorBedroom1()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup() {

Blynk.begin(auth, ssid, pass);
dht.begin();

pinMode(15, OUTPUT);
pinMode(2, OUTPUT);
pinMode(0, OUTPUT);
pinMode(4, OUTPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);

}


void loop()
{

  Blynk.run();
}
