#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <SocketIOClient.h>//#include <SocketIOsocket.h>
#include <ArduinoJson.h>
#include <WiFiManager.h>

#define evento "/post/dispositivo/"
#define serial "lampada001"
#define debugar true
#define luz D2

String JSON;
StaticJsonBuffer<100> jsonBuffer;

JsonObject& root = jsonBuffer.createObject();
root["serial"] = serial;  //  root["time"] = 1351824120;   //  JsonArray& data = root.createNestedArray("data");  //  data.add(double_with_n_digits(48.756080, 6));  //  data.add(double_with_n_digits(2.302038, 6));
root.printTo(JSON);

SocketIOClient socket;

volatile unsigned long tempoConexao;
volatile unsigned long tempoEmit;
volatile unsigned long tempoDebug;

char host[] = "api.saiot.ect.ufrn.br";
int port = 80;
unsigned long previousMillis = 0;



void setup() {

  WiFiManager wifs;
  wifs.autoConnect();
  pinMode(luz, OUTPUT);
  Serial.begin(115200);
  delay(10);

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (!socket.connect(host, port)) {
    Serial.println("connection failed");
    return;
  }
  if (socket.connected())
  {
    Serial.println("\n\n\n\n\nConectou no servidor\n\n\n");
    socket.emit("/post/dispositivo/", JSON);

    tempoConexao = millis();
    Seiral.print("\n\n\ntempo conexão: ");
    Serial.println(tempoConexao);
  }
  socket.on("atuar", Atuar);
  socket.on("debug", Debug);
  socket.on("estado", Estado);
  socket.on("valor", Valor);
}

void loop() {
  socket.monitor();
  Teste();
}
