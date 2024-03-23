#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // -1 indicates no reset pin

SoftwareSerial mySerial(D5, D6);  // RX, TX for fingerprint sensor
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
void setup() 
{
  Serial.begin(115200);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("Fingerprint Enrollment with OLED Display");

  // OLED Display Initialization
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay(); // Clear the display buffer.
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Fingerprint Enroll"));
  display.display();
  delay(2000);
  display.clearDisplay();

  // Fingerprint Sensor Initialization
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
}
uint8_t readnumber(void) 
{
  uint8_t num = 0;

  while (num == 0) 
  {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}


void loop() 
{
  Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
  display.clearDisplay(); // Clear the display buffer.
  display.setTextSize(1.3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Please type in the ID # (from 1 to 127)");
  display.display();
  delay(1000);
  display.clearDisplay();
  id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);
  display.clearDisplay(); // Clear the display buffer.
  display.setTextSize(1.3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Enrolling id ");
  display.println(id);
  display.display();
  delay(1000);
  display.clearDisplay();

  while (!  enrollFingerprint() );
}
bool enrollFingerprint()
{
  uint8_t p = finger.getImage();
  switch (p) 
  {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      display.clearDisplay(); // Clear the display buffer.
      display.setTextSize(1.3);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Add your finger");
      display.display();
      return false;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return false;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return false;
    default:
      Serial.println("Unknown error");
      return false;
  }

  // OK success!
  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return false;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return false;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return false;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return false;
    default:
      Serial.println("Unknown error");
      return false;
  }

  // OK converted!
  Serial.println("Remove finger");
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Remove finger");
  display.display();
  delay(1000);

  p = 0;
  while (p != FINGERPRINT_NOFINGER) 
  {
    p = finger.getImage();
  }

  Serial.println("Place same finger again");
  display.clearDisplay();
  display.setTextSize(1.2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Place same finger again(in 2 sec)");
  display.display();
  delay(2000);

  p = finger.getImage();
  if (p != FINGERPRINT_OK) {
    Serial.println("Error capturing fingerprint");
    return false;
  }

  // OK success!
  p = finger.image2Tz(2);
  switch (p) 
  {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return false;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return false;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return false;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return false;
    default:
      Serial.println("Unknown error");
      return false;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) 
  {
    p = finger.storeModel(id);
    if (p == FINGERPRINT_OK) {
      Serial.println("Fingerprint enrolled successfully!");
      display.clearDisplay();
      display.setTextSize(1.3);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print(F("Fingerprint enrolled in id "));
      display.print(id);
      display.display();
      delay(3000);
      return true;
    } else {
      Serial.println("Error storing fingerprint");
      return false;
    }
  } 
  else 
  {
    Serial.println("Error enrolling fingerprint");
    return false;
  }
}

  // OK converted!
  