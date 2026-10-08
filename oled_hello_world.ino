#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED screen resolution
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define OLED I2C address (default is usually 0x3C or 0x3D)
#define OLED_ADDR   0x3C

// Create OLED object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Wire.begin(22,21);
  // Initialize OLED screen
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Infinite loop to terminate program
  }
  
  // Clear display buffer
  display.clearDisplay();
  
  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
}

void loop() {
  display.clearDisplay();

  display.print("Hello");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.print("World");
  display.display();
  delay(2000);
  display.clearDisplay();

  
}
