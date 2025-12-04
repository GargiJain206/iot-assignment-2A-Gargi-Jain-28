//add owner

#include <Wire.h> // Required for I2C communication
#include <Adafruit_GFX.h> // Graphics library
#include <Adafruit_SSD1306.h> // SSD1306 driver library

// Define screen dimensions (change if using 128x32)
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // The I2C address of your display

// Initialize the display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // Initialize display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Clear the display buffer
  display.clearDisplay(); 

  // Set up text properties
  display.setTextSize(1);      // Set text size to 1 (smallest)
  display.setTextColor(WHITE); // Set color to white
  display.setCursor(0, 0);     // Set cursor to the top-left corner (0, 0)
  
  // Print text to the display buffer
  display.println("Hello World!"); 

  // Show the content in the display buffer on the screen
  display.display(); 
  
  delay(2000); // Wait for 2 seconds
}

void loop() {
  // Your main loop code goes here
}