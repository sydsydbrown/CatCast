// Images
#include "introPic.h"
#include "thermoPic.h"
#include "rainPic.h"
#include "humidPic.h";
#include "cloudPic.h";
#include "windPic.h";
#include "plainCat.h";
#include "sleepyCat.h";


// Screen Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay(){
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setRotation(0);
}

void showIntro(){
  display.drawBitmap(0, 0, introPic, 128, 64, SH110X_WHITE);
  display.display();
  delay(3000);
  //display.print ("intro!");
}

void showTemp(){
  display.drawBitmap(0, 0, thermoPic, 128, 64, SH110X_WHITE);
  display.setCursor(50, 30);
  display.setTextWrap(true);
  display.setTextSize(3);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  //display.print(currentTemp);
  display.print("24");
  display.print("C");
  display.display();
}

void showRain(){
  display.drawBitmap(0, 0, rainPic, 128, 64, SH110X_WHITE);
  display.setCursor(68, 30);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  display.print("none");
  //display.print(isRaining);
  display.display();
}

// void showHumidity(){
//   display.drawBitmap(0, 0, humidPic, 128, 64, SH110X_WHITE);
//   display.setCursor(68, 30);
//   display.setTextWrap(true);
//   display.setTextSize(2);
//   display.setTextColor(SH110X_WHITE, SH110X_BLACK);
//   display.print("43%");
//   //display.print(isHumid);
//   display.display();
// }

void showCloudy(){
  display.drawBitmap(0, 0, cloudPic, 128, 64, SH110X_WHITE);
  display.setCursor(68, 30);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  //display.print(isCloudy);
  display.print ("4");
  display.print ("/10");
  display.display();
}

void showWindy(){
  display.drawBitmap(0, 0, windPic, 128, 64, SH110X_WHITE);
  display.setCursor(68, 30);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  //display.print(isWindy);
  display.print("2");
  display.print("mph");
  display.display();
}

void showSleep(){
  display.drawBitmap(0, 0, sleepyCat, 128, 64, SH110X_WHITE);
  display.display();
}

void clearDisplay(){display.clearDisplay();}