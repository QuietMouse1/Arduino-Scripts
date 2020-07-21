#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("DESKTOP-GI17MH6 9715", "Q4843$6c");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.printf("Connection status: %d\n", WiFi.status());
  delay(1000);
  WiFi.printDiag(Serial);
  }
