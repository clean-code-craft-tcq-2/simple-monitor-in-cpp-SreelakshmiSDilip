#include <stdio.h>
#include <string.h>
#include "BatteryStateChecker.h"

char alertString[100] = "Alert: Battery Status: Out of Range: ";

  fpPrint = &showBatteryStatus;

int showBatteryStatus(const char* statement) {
	printf("%s \n", statement);
	return 0;
}

bool IsParameterInRange(float parameterValue, float min_threshold, float max_threshold) {
	if (parameterValue < min_threshold || parameterValue > max_threshold) {
		return 0;
	}
	return 1;
}

bool IsParameterIsWithinLimit(float parameterValue, float max_limit) {
	if (parameterValue  > max_limit) {
		return 0;
	}
	return 1;
}

bool getParameterStatus(bool status, const char* parameter) {
	char statement[100];
	strcpy(statement, alertString);
	strcat(statement, parameter);
	if (status == 0) {
		(*fpPrint)(statement);
	}
	return status;
}

bool getBatteryTempStatus(float temperature) {
	bool status;
	status = IsParameterInRange(temperature, MIN_THRESHOLD_TEMP, MAX_THRESHOLD_TEMP);
	status = getParameterStatus(status, "Temperature");
	return status;
}

bool getBatterySoCStatus(float SoC) {
	bool status;
	status = IsParameterInRange(SoC, MIN_THRESHOLD__SoC, MAX_THRESHOLD_SoC);
	status = getParameterStatus(status, "State of Charge");
	return status;
}

bool getBatteryChargingRateStatus(float chargingRate){
	bool status;
	status = IsParameterIsWithinLimit(chargingRate, MAX_THRESHOLD_CHARGE_RATE);
	status = getParameterStatus(status, "Charge Rate");
	return status;
}

bool getOverallBatteryStatus(float temperature, float SoC, float chargingRate){
	bool batt_status;
	batt_status =(getBatteryTempStatus(temperature)) && (getBatterySoCStatus(SoC)) && (getBatteryChargingRateStatus(chargingRate));
	return batt_status;	
}
