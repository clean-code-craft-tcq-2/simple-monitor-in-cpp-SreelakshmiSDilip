#include <stdio.h>
#include <assert.h>
#include "BatteryStateChecker.h"


void testGetBatteryTempStatus(TemperatureStruct temperature, int expectedStatus) {
	assert(getBatteryTempStatus(temperature) == expectedStatus);
}
 
void testGetBatterySoCStatus(float SoC, int expectedStatus) {
	assert(getBatterySoCStatus(SoC) == expectedStatus);
}

void testGetBatteryChargingRateStatus(float chargeRate, int expectedStatus){
	assert(getBatteryChargingRateStatus(chargeRate) == expectedStatus);
}
 
void testGetOverallBatteryStatus(TemperatureStruct   temperature, float SoC, float chargeRate, int expectedStatus){
	assert(getOverallBatteryStatus(temperature, SoC, chargeRate) == expectedStatus);
}

int main() {
	TemperatureStruct testTemp_C ={30,"C"};
	TemperatureStruct testTemp_F = {122,"F"};
	testGetBatteryTempStatus(testTemp_C, 1 );
	testGetBatteryTempStatus(testTemp_F, 0  );
	testGetBatterySoCStatus(24, 1);
	testGetBatterySoCStatus(85, 0);
	testGetBatteryChargingRateStatus(0.6, 1);
	testGetBatteryChargingRateStatus(0.9, 0);
	testGetOverallBatteryStatus(testTemp_C,45, 0.6, 1);
	testGetOverallBatteryStatus(testTemp_F, 90, 0.9, 0);
	testGetOverallBatteryStatus(testTemp_C, 97, 0.6, 0);
	testGetOverallBatteryStatus(testTemp_C, 77, 0.9, 0);

}
