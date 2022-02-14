#include <stdio.h>
#include <assert.h>
#include "BatteryStateChecker.h"

int printCallCount = 0;

int testShowBatteryStatus(const char* statement) {
	printf("%s \n",statement);
	printCallCount++;
	return 0;
}

void testGetBatteryTempStatus(float temperature, int expectedStatus) {
	assert(getBatteryTempStatus(temperature) == expectedStatus);
}
 
void testGetBatterySoCStatus(float SoC, int expectedStatus) {
	assert(getBatterySoCStatus(SoC) == expectedStatus);
}

void testGetBatteryChargingRateStatus(float chargeRate, int expectedStatus){
	assert(getBatteryChargingRateStatus(chargeRate) == expectedStatus);
}
 
void testgetOverallBatteryStatus(float temperature, float SoC, float chargeRate, int expectedStatus){
	assert(getOverallBatteryStatus(temperature, SoC, chargeRate) == expectedStatus);
}

int main() {
	fpPrint = &testShowBatteryStatus; //Assigning fake print function for testing
	testGetBatteryTempStatus(30, 1);
	testGetBatteryTempStatus(55, 0);
	testGetBatterySoCStatus(50, 1);
	testGetBatterySoCStatus(85, 0);
	testGetBatteryChargingRateStatus(0.7, 1);
	testGetBatteryChargingRateStatus(0.9, 0);
	testGetOverallBatteryStatus(20, 45, 0.6, 1);
	testGetOverallBatteryStatus(55, 100, 0.9, 0);
	testGetOverallBatteryStatus(43, 90, 0.6, 0);
	testGetOverallBatteryStatus(43, 70, 0.9, 0);
	assert(printCallCount == 6);
}
