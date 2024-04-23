// InfoClip Starter Code
// Zane Cochran
// 13 APR 2024

// Setup
const char* ssid = "EZConnect";
const char* password = "HackBerryPlay";
String apiUrl = "https://www.7timer.info/bin/astro.php?lon=-85.164&lat=34.257&product=civil&output=json";


// Information
// int currentTemp = 0;
// String isRaining = "";
// //String isHumid = "";
// int isCloudy = 0;
// int isWindy = 0;


// State Machine
int mode = -1;
int lastMode = -1;

void setup() {
  Serial.begin(115200);
  delay(2000);
  wifiConnect();
  wifiRequest();
  initDisplay();
  initButtons();
}

void loop() {

  switch(mode){
    case -1: showIntro(); break;
    case 0: showSleep(); break;
    case 1: showTemp(); break;
    case 2: showRain(); break; 
    case 3: showCloudy(); break;
    case 4: showWindy(); break;
  }
  checkButtons();
  checkSleep();
}
