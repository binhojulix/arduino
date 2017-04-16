#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <string.h>
#include "utility/debug.h"

// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!
// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10
// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11
Adafruit_CC3000 connection = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT, SPI_CLOCK_DIVIDER); // you can change this clock speed

#define WLAN_SSID       "fabio"           // cannot be longer than 32 characters!
#define WLAN_PASS       "my_senha1"
// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

#define IDLE_TIMEOUT_MS  3000      // Amount of time to wait (in milliseconds) with no data 
                                   // received before closing the connection.  If you know the server
                                   // you're accessing is quick to respond, you can reduce this value.

// What page to grab!
#define WEBSITE      "192.168.0.242:3000"
#define WEBPAGE      "/listar"


uint32_t ip;

void setup(void)
{
  Serial.begin(9600);

 
  if (!connection.begin())
  {
    Serial.println(F("Nao foi possivel se conectar! Check sua conexao?"));
    while(1);
  }

  
  Serial.print(F("\n Pronto para se conectar com "));
  Serial.println(WLAN_SSID);
  if (!connection.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println(F("Failed!"));
    while(1);
  }


  /* Wait for DHCP to complete */
  Serial.println(F("Request DHCP"));
  while (!connection.checkDHCP())
  {
    delay(100); // ToDo: Insert a DHCP timeout!
  }  



  uint32_t ip = connection.IP2U32(192,168,0,242);


  connection.printIPdotsRev(ip);
  


  Adafruit_CC3000_Client cliente = connection.connectTCP(ip, 3000);
  if (cliente.connected()) {
  		cliente.fastrprint(F("GET "));
  		cliente.fastrprint(WEBPAGE);
  		cliente.fastrprint(F(" HTTP/1.1\r\n"));
  		cliente.fastrprint(F("Host: ")); 
  		cliente.fastrprint(WEBSITE);
  		cliente.fastrprint(F("\r\n"));
  		cliente.fastrprint(F("\r\n"));
  		cliente.println();
  } else {
		  Serial.println(F("Connection failed"));    
    return;
  }




  //ler data ate a conexao ser fechada ou o tempo estourar
  unsigned long lastRead = millis();
  while (cliente.connected() && (millis() - lastRead < IDLE_TIMEOUT_MS)) {
    while (cliente.available()) {
      char c = cliente.read();
      Serial.print(c);
      lastRead = millis();
    }
  }

  
  cliente.close();
  connection.disconnect();
  
}

void loop(void)
{
 delay(1000);
}














