#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN 2

const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";

WebServer server(80);

/* LED ON */
void led_on()
{
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
}

/* LED OFF */
void led_off()
{
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
}

/* Home page */
void handle_root()
{
    server.send(
        200,
        "text/html",
        "<html>"
        "<body>"
        "<h1>ESP32 LED Control</h1>"
        "<a href='/on'><button>LED ON</button></a>"
        "<br><br>"
        "<a href='/off'><button>LED OFF</button></a>"
        "</body>"
        "</html>"
    );
}

/* ON request */
void handle_on()
{
    led_on();

    server.send(
        200,
        "text/html",
        "<h1>LED is ON</h1>"
        "<a href='/'>Back</a>"
    );
}

/* OFF request */
void handle_off()
{
    led_off();

    server.send(
        200,
        "text/html",
        "<h1>LED is OFF</h1>"
        "<a href='/'>Back</a>"
    );
}

/* Setup */
void setup()
{
    Serial.begin(115200);

    /* GPIO configuration */
    pinMode(LED_PIN, OUTPUT);

    /* Initially OFF */
    digitalWrite(LED_PIN, LOW);

    /* Connect Wi-Fi */
    Serial.println("Connecting to Wi-Fi...");

    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Wi-Fi connected!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    /* HTTP routes */
    server.on("/", handle_root);
    server.on("/on", handle_on);
    server.on("/off", handle_off);

    /* Start server */
    server.begin();

    Serial.println("Web server started!");
}

/* Main loop */
void loop()
{
    server.handleClient();
}
