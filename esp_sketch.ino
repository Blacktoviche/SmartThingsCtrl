#include <ESP8266WiFi.h>
 
const char* ssid = "<SSID>>";
const char* password = "<PASSWORD>>";
 
int ledPin = 13; // GPIO13
WiFiServer server(80);

String d0VS, d1VS, d2VS, d3VS, d4VS, d5VS, d6VS, d7VS, d8VS;
void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, LOW);
  pinMode(D3, OUTPUT);
  digitalWrite(D3, LOW);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
  pinMode(D5, OUTPUT);
  digitalWrite(D5, LOW);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, LOW);
  pinMode(D7, OUTPUT);
  digitalWrite(D7, LOW);
  pinMode(D8, OUTPUT);
  digitalWrite(D8, LOW);
  
  Serial.print("Hello.... ");
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println("request is: ");
  Serial.println(request);
  client.flush();
 
  // Match the request

  if(request.indexOf("/led/read/") != -1 ){
    
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println("Access-Control-Allow-Origin: *");
  client.println("");
  
  d0VS = String(digitalRead(D0));
  d1VS = String(digitalRead(D1));
  d2VS = String(digitalRead(D2));
  d3VS = String(digitalRead(D3));
  d4VS = String(digitalRead(D4));
  d5VS = String(digitalRead(D5));
  d6VS = String(digitalRead(D6));
  d7VS = String(digitalRead(D7));
  d8VS = String(digitalRead(D8));
  
  client.print("{\"D0\":"+d0VS+",\"D1\":"+d1VS+",\"D2\":"+d2VS+",\"D3\":"+d3VS+",\"D4\":"+d4VS+",\"D5\":"+d5VS+",\"D6\":"+d6VS+",\"D7\":"+d7VS+",\"D8\":"+d8VS+"}");
    return;
  }

  
  int value = LOW;

   if(request.indexOf("/led/0/") != -1){
      
   if (request.indexOf("/0/1") != -1)  {
    digitalWrite(D0, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/0/0") != -1)  {
    digitalWrite(D0, LOW);
    returnJSON(client);
    return;
  }
  }

   if(request.indexOf("/led/1/") != -1){
      
   if (request.indexOf("/1/1") != -1)  {
    digitalWrite(D1, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/1/0") != -1)  {
    digitalWrite(D1, LOW);
    returnJSON(client);
    return;
  }
  }

   if(request.indexOf("/led/2/") != -1){
      
   if (request.indexOf("/2/1") != -1)  {
    digitalWrite(D2, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/2/0") != -1)  {
    digitalWrite(D2, LOW);
    returnJSON(client);
    return;
  }
  }

   if(request.indexOf("/led/3/") != -1){
      
   if (request.indexOf("/3/1") != -1)  {
    digitalWrite(D3, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/3/0") != -1)  {
    digitalWrite(D3, LOW);
    returnJSON(client);
    return;
  }
  }

   if(request.indexOf("/led/4/") != -1){
      
   if (request.indexOf("/4/1") != -1)  {
    digitalWrite(D4, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/4/0") != -1)  {
    digitalWrite(D4, LOW);
    returnJSON(client);
    return;
  }
  }
  
  if(request.indexOf("/led/5/") != -1){
      
   if (request.indexOf("/5/1") != -1)  {
    digitalWrite(D5, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/5/0") != -1)  {
    digitalWrite(D5, LOW);
    returnJSON(client);
    return;
  }
  }

   if(request.indexOf("/led/6/") != -1){

   if (request.indexOf("/6/1") != -1)  {
    digitalWrite(D6, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/6/0") != -1)  {
    digitalWrite(D6, LOW);
    returnJSON(client);
    return;
  }
  }

 if(request.indexOf("/led/7/") != -1){
      
   if (request.indexOf("/7/1") != -1)  {
    digitalWrite(D7, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/7/0") != -1)  {
    digitalWrite(D7, LOW);
    returnJSON(client); 
    return;
  }
  }
  
   if(request.indexOf("/led/8/") != -1){

   if (request.indexOf("/8/1") != -1)  {
    digitalWrite(D8, HIGH);
    returnJSON(client);
    return;
  }
  if (request.indexOf("/8/0") != -1)  {
    digitalWrite(D8, LOW);
    returnJSON(client);
    return;
  }
  }
  
  //return json
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println("Access-Control-Allow-Origin: *");
  client.println("");
  client.print("{\"key1\":\"test1\",\"key2\":\"test2\",\"key3\":\"test3\"}");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}


void returnJSON(WiFiClient client){
  //return json
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println("Access-Control-Allow-Origin: *");
  client.println("");
  client.print("{\"Message\":\"Success\"}");
 }