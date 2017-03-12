void ethernet()
{

   // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<font size=7>");
          client.print("**************");
          client.println("<br />");
          client.print("* Domogarden *");
          client.println("<br />");
          client.println("**************");
          client.println("<br />");
          client.println("</font>");

          client.println("<font size=5>");
          
          switch (rtc.dayOfWeek())
          {
            case 1:
                client.print("Lundi ");
                break;
            case 2: 
                client.print("Mardi ");
                break;
            case 3:
                client.print("Mercredi ");
                break;
            case 4:
                client.print("Jeudi ");
                break;
            case 5:
                client.print("Vendredi ");
                break;
            case 6:
                client.print("Samedi ");
                break;
            case 7:
                client.print("Dimanche ");
                break;
            default:
                client.print("Erreur ");
                break;
          }
          client.print(rtc.hour());
          client.print(":");
          client.print(rtc.minute()/10);
          client.println(rtc.minute()%10);
          client.print("<br />");
          client.print("<br />");
          client.println("<font size=4>");
          client.print("Valeur Ph : ");
          client.println(ph_value_float);
          client.println("<br />");
          
          client.print("Valeur Chlore : ");
          client.println(redox_value_float);
          client.println("<br />");
          
          client.print("Temperature : ");
          client.println(temp);
          client.println(" Deg C");
          client.println("<br />");
          client.println("<br />");
          client.println("</font>");

          client.println("<font size=5>");
          client.println("Filtration : ");
          client.println("<br />");
          client.println("</font>");
          client.println("<font size=4>");
          client.println("Depart : ");
          client.println(depart_filtration);
          client.println("<br />");
          client.println("Duree : ");
          client.println(duree_filtration);       
          client.println("</font>");
          client.println("<br />");

          if (filtrationON == 1){
            client.println("ON");
          }
          else {
              client.println("OFF");
          }
          client.println("<br />");
          client.println("<br />");

          client.println("<font size=5>");
          client.println("Robot : ");
          client.println("<br />");
          client.println("</font>");
          client.println("<font size=4>");
          client.println("Depart : ");
          client.println(depart_robot);
          client.println("<br />");
          client.println("Duree : ");
          client.println(duree_robot);
          client.println("</font>");
          client.println("<br />");

          if (robotON == 1){
            client.println("ON");
          }
          else {
              client.println("OFF");
          }
          client.println("<br />");
          client.println("<br />");

          client.println("<font size=5>");
          client.println("Hors Gel : ");
          client.println("<br />");
          client.println("</font>");
          client.println("<font size=4>");
          client.println("Consigne : ");
          client.println(conshorsgel);
          client.println("<br />");
          client.println("</font>");
          if (robotON == 1){
            client.println("ON");
          }
          else {
              client.println("OFF");
          }
          
          client.println("</font>");
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
