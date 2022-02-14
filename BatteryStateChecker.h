#define MIN_THRESHOLD_TEMP 0
#define MAX_THRESHOLD_TEMP 45
#define MIN_THRESHOLD__SoC 20
#define MAX_THRESHOLD_SoC 80
#define MAX_THRESHOLD_CHARGE_RATE 0.8


 bool getBatteryTempStatus(float temperature);
 bool getBatterySoCStatus(float SoC);
 bool getBatteryChargingRateStatus(float chargeRate);
 bool getOverallBatteryStatus(float temperature, float SoC, float chargeRate);
 int showBatteryStatus(const char* statement);

