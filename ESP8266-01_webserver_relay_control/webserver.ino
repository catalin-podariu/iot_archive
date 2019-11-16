#include <ESP8266WiFi.h>
 
const char* ssid = "UPC6E81C15";//type your ssid
const char* password = "cxw4Zk8Esmpt";//type your password

//Hex command to send to serial for open relay
byte switchON[] = {0xA0, 0x01, 0x01, 0xA2};

//Hex command to send to serial for close relay
byte switchOFF[] = {0xA0, 0x01, 0x00, 0xA1}; 

int ledPin = 0 ; // GPIO2 of ESP8266
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  //make sure the relay is off before moving forward
  Serial.write(switchOFF, sizeof(switchOFF));
  delay(10);
  Serial.write(switchOFF, sizeof(switchOFF));
   
  // Connect to WiFi network   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   
  // Start the server
  server.begin();  
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  client.flush();

  // Match the request
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    Serial.write(switchON, sizeof(switchON));
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    Serial.write(switchOFF, sizeof(switchOFF));
    value = LOW;
  }

  writeHeader(client);
  writeStatus(client, value);
  writeOptions(client);
  
  delay(10);
}

void writeHeader(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
}

void writeStatus(WiFiClient client, int value) {
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
}

void writeOptions(WiFiClient client) {
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");
}
