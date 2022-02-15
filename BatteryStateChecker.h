#include<string>

#define MIN_THRESHOLD_TEMP 0
#define MAX_THRESHOLD_TEMP 45
#define MIN_THRESHOLD__SoC 20
#define MAX_THRESHOLD_SoC 80
#define MAX_THRESHOLD_CHARGE_RATE 0.8
using namespace std;

const int c_WarningLimitFactor = 4;
struct TemperatureStruct{
   float tempValue;
   string tempUnit;
};

float convertTempToCelcius(float temperature , string unit);
 bool getBatteryTempStatus(TemperatureStruct temperature);
 bool getBatterySoCStatus(float SoC);
 bool getBatteryChargingRateStatus(float chargeRate);
 bool getOverallBatteryStatus(TemperatureStruct  temperature, float SoC, float chargeRate);
 int showBatteryStatus(const char* statement);
