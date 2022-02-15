#include <stdio.h>
#include <assert.h>
#include "BatteryStateChecker.h"


void testGetBatteryTempStatus(float temperature, int expectedStatus) {
	assert(getBatteryTempStatus(temperature) == expectedStatus);
}
 
void testGetBatterySoCStatus(float SoC, int expectedStatus) {
	assert(getBatterySoCStatus(SoC) == expectedStatus);
}

void testGetBatteryChargingRateStatus(float chargeRate, int expectedStatus){
	assert(getBatteryChargingRateStatus(chargeRate) == expectedStatus);
}
 
void testGetOverallBatteryStatus(float temperature, float SoC, float chargeRate, int expectedStatus){
	assert(getOverallBatteryStatus(temperature, SoC, chargeRate) == expectedStatus);
}

int main() {
	testGetBatteryTempStatus(30, 1 ,'C');
	testGetBatteryTempStatus(122, 0 ,'F' );
	testGetBatterySoCStatus(24, 1);
	testGetBatterySoCStatus(85, 0);
	testGetBatteryChargingRateStatus(0.6, 1);
	testGetBatteryChargingRateStatus(0.9, 0);
	testGetOverallBatteryStatus(20, 'C',45, 0.6, 1);
	testGetOverallBatteryStatus(122,'F', 90, 0.9, 0);
	testGetOverallBatteryStatus(40,'C', 97, 0.6, 0);
	testGetOverallBatteryStatus(40,'C', 77, 0.9, 0);

}
