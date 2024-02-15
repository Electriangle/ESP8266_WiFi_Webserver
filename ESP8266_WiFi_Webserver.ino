/*
 * Title: ESP8266_WiFi_Webserver
 * 
 * Description: 
 *      - This sketch was created as a template for generating a local ESP8266 web server. The default webpage will load a single ON/OFF button.
 *        Update the WiFi parameters below before uploading sketch in order to access the webpage. Then, add your I/O pins and adjust HTTP code 
 *        in the Client.ino tab according to your specific project.
 *
 * Author: Electriangle
 *      - Channel: https://www.youtube.com/@Electriangle
 *
 * Date Created: 2/14/2024
 * Last Updated: 2/14/2024
*/

// ------------------------- LIBRARIES -------------------------
#include <ESP8266WiFi.h>
// -------------------------------------------------------------

// ------------------------- NETWORK SETTINGS -------------------------
const char* ssid = "YOUR_WIFI_SSID";                // Enter your WiFi SSID
const char* password = "YOUR_WIFI_PASS";            // Enter your WiFi Password
WiFiServer server(80);
IPAddress local_IP(192, 168, 1, YOUR_STATIC_IP);    // Enter your desired static IP address
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);
String readString;
// --------------------------------------------------------------------

// ------------------------- CODE PARAMETERS -------------------------
// ----- PINS -----


// ----- VARIABLES -----
bool button_state = false;
// -------------------------------------------------------------

// ------------------------- SETUP -------------------------
void setup() {
  // ----- INITIAL SETUP -----
  Serial.begin(115200);
  
  // ----- CONNECT TO WIFI AND BEGIN SERVER -----
  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure.");
  }
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
// ---------------------------------------------------------

// ------------------------- LOOP -------------------------
void loop() {
  // ----- CREATE CONNECTION WITH CLIENT -----
  establish_client();

}
// --------------------------------------------------------
