#define MIN_THRESHOLD_TEMP 0
#define MAX_THRESHOLD_TEMP 45
#define MIN_THRESHOLD__SoC 20
#define MAX_THRESHOLD_SoC 80
#define MAX_THRESHOLD_CHARGE_RATE 0.8

typedef enum{
   e_TEMPERATURE,
   e_SoC,
   e_CHARGERATE
}ParameterTypeEnum;

float convertTempToCelcius(float temperature, string unit)
 bool getBatteryTempStatus(float temperature,string unit);
 bool getBatterySoCStatus(float SoC);
 bool getBatteryChargingRateStatus(float chargeRate);
 bool getOverallBatteryStatus(float temperature, float SoC, float chargeRate);
 int showBatteryStatus(const char* statement);
