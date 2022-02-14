#define MIN_THRESHOLD_TEMP 0
#define MAX_THRESHOLD_TEMP 45
#define MIN_THRESHOLD__SoC 20
#define MAX_THRESHOLD_SoC 80
#define MAX_THRESHOLD_CHARGE_RATE 0.8


extern int checkBatteryTemp(float temperature);
extern int checkBatterySoC(float SoC);
extern int checkBatteryChargeRate(float chargeRate);
extern int checkBatteryStatus(float temperature, float SoC, float chargeRate);
int showBatteryStatus(const char* statement);
extern int (*fpPrint) (const char*);
