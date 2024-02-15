void establish_client() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client.");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        // Read char by char HTTP request and store characters to string
        if (readString.length() < 100) {readString += c;}

        // If HTTP request has ended
        if (c == '\n') {
          Serial.println(readString);

          client.println("HTTP/1.1 200 OK");    // Send new page
          client.println("Content-Type: text/html");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
          client.println("<TITLE>Webserver</TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<H1>Webserver</H1>");
          client.println("<hr />");
          client.println("<br>");
          client.println("<br>");

          // Button activated
          if (readString.indexOf("?turnON") > 0) {
            button_state = true;

            client.println("<H2><B>Turned ON</B></H2>");
            client.println("<br>");
            client.println("<br>");
            client.println("<a href=\"/?turnOFF\"\">Turn OFF</a>");
          }
          else if (readString.indexOf("?turnOFF") > 0) {
            button_state = false;

            client.println("<H2><B>Turned OFF</B></H2>");
            client.println("<br>");
            client.println("<br>");
            client.println("<a href=\"/?turnON\"\">Turn ON</a>");
          }
          else if (button_state == true) {
            client.println("<H2><B>Turned ON</B></H2>");
            client.println("<br>");
            client.println("<br>");
            client.println("<a href=\"/?turnOFF\"\">Turn OFF</a>");
          }
          else if (button_state == false) {
            client.println("<H2><B>Turned OFF</B></H2>");
            client.println("<br>");
            client.println("<br>");
            client.println("<a href=\"/?turnON\"\">Turn ON</a>");
          }

          // ----- BUTTON STATE -----
          client.println("<br>");
          client.println("<br>");
          client.println("<H3>Button State: </H2>");
          client.println(button_state);
          client.println("<br>");
          client.println("<br>");
          
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          client.stop();      // Stopping client
          
          readString = "";    // Clearing string for next read
        }
      }
    }
  }
}
