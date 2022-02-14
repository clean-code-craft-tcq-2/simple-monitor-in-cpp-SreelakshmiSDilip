#include <iostream>
#include <string.h>
#include "BatteryStateChecker.h"
using namespace std;
char alertString[100] = " Battery Status Out of Range Alert!! For: ";
char lowWarningString[100] = "Battery Status low Warning!!For : ";
char highWarningString[100] = "Battery Status high Warning!!For : 

int (*fpPrint) (const char*) = &showBatteryStatus;

int showBatteryStatus(const char* statement) {
	cout<<" \n" << statement;
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
	else if(parameterValue  > max_limit - 4){
	    char statement[100];
	    strcpy(statement, highWarningString);
	    strcat(statement, parameter);
	}
	return 1;
}
bool IsEarlyAlertRequiredforCurrentValue(float parameterValue, float min_threshold, float max_threshold){
	char statement[100];
	bool earlyAlertLimitReached = false;
	if((parameterValue -4) < min_threshold)
	{
	    strcpy(statement, lowWarningString);
	    strcat(statement, parameter);
	    earlyAlertLimitReached = true;
	}
	else if((parameterValue + 4) > max_threshold){
	    strcpy(statement, highWarningString);
	    strcat(statement, parameter);
	    earlyAlertLimitReached = true;
	}
        if (warningLimitReached == 0) {
		(*fpPrint)(statement);
	return earlyAlertLimitReached;
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
	if(status){
		bool l_earlyAlert = IsEarlyAlertRequiredforCurrentValue(temperature, MIN_THRESHOLD_TEMP, MAX_THRESHOLD_TEMP);
	}
	return status;
}

bool getBatterySoCStatus(float SoC) {
	bool status;
	status = IsParameterInRange(SoC, MIN_THRESHOLD__SoC, MAX_THRESHOLD_SoC);
	status = getParameterStatus(status, "State of Charge");
	if(status){
		bool l_earlyAlert = IsEarlyAlertRequiredforCurrentValue(temperature, MIN_THRESHOLD_TEMP, MAX_THRESHOLD_TEMP);
	}
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
