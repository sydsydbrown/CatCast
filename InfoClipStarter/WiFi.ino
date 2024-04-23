#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Connect to WiFi
void wifiConnect(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {delay(1000); Serial.println("Connecting...");}
  Serial.println("Connected to the WiFi network");
}

void wifiRequest(){
  HTTPClient http;
  http.begin(apiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println("API Response:");
    Serial.println(payload);
    wifiExtract(payload);
  } 
  else {
    Serial.print("Error in HTTP request: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void wifiExtract(String payload){
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {Serial.print("deserializeJson() failed: "); Serial.println(error.c_str()); return;}

    // // Grab Temp
    // JsonObject dataseries = doc["dataseries"][0];      // chatgpt mkay
    // currentTemp = dataseries["temp2m"];
    //currentTempF = (currentTemp * 9/5)+32;

    // // Extract specific data
    // isRaining = (const char*)doc["dataseries"][0]["prec_type"];
    // //isHumid = (const char*)doc["dataseries"][0]["rh2m"];
    // isCloudy = (int)doc["dataseries"][0]["cloudcover"];
    // isWindy = (int)doc["dataseries"][0]["wind10m"]["speed"];
 
    // Serial.print("Temperature: "); Serial.println(currentTemp);
    // Serial.print("Rain: "); Serial.println(isRaining);
    // //Serial.print("Humidity: "); Serial.println(isHumid);
    // Serial.print("Cloud Coverage: "); Serial.println(isCloudy);
    // Serial.print("Wind Speed: "); Serial.println(isWindy);

}
