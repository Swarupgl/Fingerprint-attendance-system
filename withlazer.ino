#include <IFTTTMaker.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <ArduinoJson.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
const int ledpin = 0;

String NAME;
String ID;
String Event_Name;
String Key;
String resource;
const char* server = "maker.ifttt.com";
const char* ssid     = "Swarup's Galaxy F54 5G";
const char* password = "Swaruplokamanya";
void makeIFTTTRequest();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 
SoftwareSerial mySerial(D5, D6);  
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
void setup() 
{
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
  while (!Serial);  
  delay(100);
  Serial.println("detectint test ");
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  mySerial.begin(57600);
  delay(5);
  if (finger.verifyPassword()) 
  {
    Serial.println("Found fingerprint sensor!");
  } else 
  {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) 
    {
      delay(1);
    }
  }
   Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  Serial.print("Connecting to: ");
  Serial.print(ssid);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("connecting to:");
  display.print(ssid);
  display.display();
  WiFi.begin(ssid, password);

  int timeout = 10 * 4; // 10 seconds
  while (WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect, going back to sleep");
  }

  Serial.print("WiFi connected in: ");
  Serial.print(millis());
  Serial.print(", IP address: ");
  Serial.println(WiFi.localIP());
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("wifi connected in: ");
  display.print(millis());
  display.print(", IP adress: ");
  display.println(WiFi.localIP());
  display.display();
} 

void loop()                     // run over and over again
{
  digitalWrite(D0, HIGH);
  getFingerprintIDez();
  if (finger.fingerID == 101 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Alka Mam";
    ID = "Mat001";
    Event_Name = "maths";
    Key = "cwhvHHa92glxYHhocLbNSD";
    resource = "/trigger/" + Event_Name + "/with/key/" + Key;
    if (finger.confidence >= 90) 
    {
      Serial.print("hi  "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("hi  ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
      
    }
  }
  if (finger.fingerID == 102 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Jahnvi Mam ";
    ID = "ID131";
    Event_Name = "dsd";
    Key = "d9dJhhmP3Yj7Z5RN7zSdq8";
    resource = "/trigger/" + Event_Name + "/with/key/" + Key;
    if (finger.confidence >= 90) 
    {
      Serial.print("hi "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("hi ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }      
  }
  if (finger.fingerID == 103 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Natesha Sir ";
    ID = "ID130";
    Event_Name = "ITP";
    Key = "d_cE1yqjH1NjvyDl68Z-hu";
    resource = "/trigger/" + Event_Name + "/with/key/" + Key;
    if (finger.confidence >= 100) 
    {
      Serial.print("hi "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("hi ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }      
  }
  if (finger.fingerID == 104 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Sardhan Sir ";
    ID = "LA";
    Event_Name = "Assistive Technology";
    Key = "b04ehccIJnQ0GWJNiHo_eB";
    resource = "/trigger/" + Event_Name + "/with/key/" + Key;
    if (finger.confidence >= 100) 
    {
      Serial.print("hi "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("hi ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }      
  }
  if (finger.fingerID == 53 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "swarup";
    ID = "53";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    } 
  } 
  if (finger.fingerID == 59 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "vardha";
    ID = "59";
    if (finger.confidence >= 50) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 54 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = " Sai Praneeth";
    ID = "54";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 7 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Ashutosh Kumar";
    ID = "7";
    if (finger.confidence >= 50) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 19 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Gowrab Kumar Sharma";
    ID = "19";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }    
  if (finger.fingerID == 35 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Nikhil Nagar ";
    ID = "35";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }    
  if (finger.fingerID == 11 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "B Harika";
    ID = "11";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }    
  if (finger.fingerID == 56) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "poojitha";
    ID = "56";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }    
  if (finger.fingerID == 31 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Mayank Pal";
    ID = "31";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }    
  if (finger.fingerID == 55 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Nabiketh";
    ID = "55";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 26 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Sejal Shah";
    ID = "26";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 29 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Manvi";
    ID = "29";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 51 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Pranavi Blessy";
    ID = "51";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 12 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "B Abhishek";
    ID = "12";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 13 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Vasu Dev";
    ID = "13";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 38 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Nithin N G";
    ID = "38";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 21 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Harsh Tripati";
    ID = "21";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 30 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Tarun reddy";
    ID = "30";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 34 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Satya Narayana Murthy";
    ID = "34";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 24 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Lakshmi Shravani";
    ID = "24";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 60 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Santosh";
    ID = "60";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 40 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "p.Lohith Kumar";
    ID = "40";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 39 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "O Vinay Readdy";
    ID = "39";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 20 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "G Jashwanth";
    ID = "20";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 43 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "P Charukesh";
    ID = "43";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 58 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "V S Mayur";
    ID = "58";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 48 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Sai Pranay";
    ID = "48";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 22 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Hemanth Parte";
    ID = "22";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 9 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Ayush Raj Singh";
    ID = "9";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  } 
  if (finger.fingerID == 4 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Anil Kumar";
    ID = "4";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 5 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Ansh Guptha";
    ID = "5";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
 
  if (finger.fingerID == 23 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Kaustubh Deshmukh";
    ID = "23";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 42 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Priyansh Agrawal";
    ID = "42";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 15 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Darshan Gowda";
    ID = "15";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 36 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Nikunj Sharma";
    ID = "36";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 41 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Priyakrith P S";
    ID = "41";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 27 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Lakashay Mittal";
    ID = "27";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 44 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Rahul Dhaka";
    ID = "44";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 47 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Rudra";
    ID = "47";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 1 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Abhay Tiwari";
    ID = "1";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 16 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Deepak Kumar";
    ID = "16";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  if (finger.fingerID == 8 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Ashwath Bajaj";
    ID = "8";
    if (finger.confidence >= 60) 
    {
      Serial.print("Attendace Marked for "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("attendance marked for ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
    }
  }
  
  if (finger.fingerID == 70 ) 
  {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    digitalWrite(2, LOW);
    NAME = "Swarup";
    ID = "hlo";
    Event_Name = "trial";
    Key = "h9GgAEQFz8S7BuCwvJoqp9wC04HWiathMqn7m9iht_H";
    resource = "/trigger/" + Event_Name + "/with/key/" + Key;
    if (finger.confidence >= 100) 
    {
      Serial.print("hi  "); Serial.println(NAME);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("hi  ");
      display.setTextSize(2);
      display.println(NAME);
      display.display();
      makeIFTTTRequest();
      digitalWrite(D0, LOW);
      delay(4000);
      
    }
  }
  
       
  finger.fingerID = 0;
}

uint8_t getFingerprintID() 
{
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}
  int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
void makeIFTTTRequest() 
{
  Serial.print("Connecting to ");
  Serial.print(server);
  WiFiClient client;
  int retries = 5;
  while (!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if (!!!client.connected()) {
    Serial.println("Failed to connect...");
  }
  Serial.print("Request resource: ");
  Serial.println(resource);
  String jsonObject = String("{\"value1\":\"") + NAME + "\",\"value2\":\"" + ID
                      + "\"}";

  client.println(String("POST ") + resource + " HTTP/1.1");
  client.println(String("Host: ") + server);
  client.println("Connection: close\r\nContent-Type: application/json");
  client.print("Content-Length: ");
  client.println(jsonObject.length());
  client.println();
  client.println(jsonObject);

  int timeout = 5 * 10; // 5 seconds
  while (!!!client.available() && (timeout-- > 0)) {
    delay(100);
  }
  if (!!!client.available()) {
    Serial.println("No response...");
  }
  while (client.available()) {
    Serial.write(client.read());
  }

  Serial.println("\nclosing connection");
  client.stop();
}

