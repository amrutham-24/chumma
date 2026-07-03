#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "RGB_Control";
const char* password = "rgb12345";

WebServer server(80);
HardwareSerial mySerial(1);

// Web UI
String page = R"rawliteral(
<!DOCTYPE html>
<html>
<body style="text-align:center; font-family:sans-serif;">
<h2>RGB LED Control</h2>

<input type="color" id="picker" value="#ff0000">
<br><br>
<button onclick="sendColor()">Set Color</button>

<script>
function sendColor() {
  let color = document.getElementById("picker").value;
  let r = parseInt(color.substr(1,2),16);
  let g = parseInt(color.substr(3,2),16);
  let b = parseInt(color.substr(5,2),16);

  fetch(`/set?r=${r}&g=${g}&b=${b}`);
}
</script>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", page);
}

void handleSet() {
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt();

  // Send to Teensy
  mySerial.printf("C,%d,%d,%d,255\n", r, g, b);

  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);

Serial.println("Starting AP...");
WiFi.softAP(ssid, password);
Serial.print("IP: ");
Serial.println(WiFi.softAPIP());

  mySerial.begin(115200, SERIAL_8N1, 16, 17); // RX, TX

  server.on("/", handleRoot);
  server.on("/set", handleSet);
  server.begin();
}

void loop() {
  server.handleClient();
}
