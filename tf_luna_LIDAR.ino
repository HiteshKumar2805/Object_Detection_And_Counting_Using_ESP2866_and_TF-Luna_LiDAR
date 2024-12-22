#include <Wire.h>
#include <TFLI2C.h>
#include "ArduinoJson.h"

TFLI2C tfli2c;

int16_t tfDist;
int16_t tfAddr = TFL_DEF_ADR;

const int THRESHOLD_LIMIT = 80;         
const unsigned long MIN_DETECTION_TIME = 1000; 
const unsigned long MIN_RETRIGGER_TIME = 1000; 

unsigned long objectDetectedTime = 0;  
unsigned long objectLeaveTime = 0;     
unsigned long lastDetectionTime = 0;   
int detectionCount = 0;                 
bool isObjectDetected = false;        
bool isReappearedTooQuickly = false;  
StaticJsonDocument<200> doc;
void setup() {
    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
  if (tfli2c.getData(tfDist, tfAddr))
  {
    if (tfDist <= THRESHOLD_LIMIT) 
    { 
      if (!isObjectDetected) 
      {
        objectDetectedTime = millis();
        isObjectDetected = true;

        if (millis() - objectLeaveTime < MIN_RETRIGGER_TIME)
        {
          isReappearedTooQuickly = true; 
        }
        else
        {
          isReappearedTooQuickly = false;
        }
      }
      if (isObjectDetected && (millis() - objectDetectedTime >= MIN_DETECTION_TIME))
      {
        if (!isReappearedTooQuickly && millis() - lastDetectionTime >= MIN_RETRIGGER_TIME)
        {
          detectionCount++;
          lastDetectionTime = millis();
          objectLeaveTime = millis();
          isObjectDetected = false;
        }
      }
    }
    else
    { 
      if (isObjectDetected)
      { 
        objectLeaveTime = millis();
        isObjectDetected = false;
      }
    }
  } 
  String jsonOutput= GetJSONString(detectionCount,tfDist);
  Serial.println(jsonOutput);

  delay(100);
}
String GetJSONString(int a,int b)
{
  StaticJsonDocument<1024> staticJsonDocument;
  staticJsonDocument["Count"] = a;
  staticJsonDocument["Dist"] = b;
  char docBuf[1024];
  serializeJson(staticJsonDocument, docBuf);
  return String(docBuf);
}
