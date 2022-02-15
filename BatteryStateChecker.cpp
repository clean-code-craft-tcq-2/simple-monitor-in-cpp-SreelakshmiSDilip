#include <iostream>
#include <string.h>
#include "BatteryStateChecker.h"
using namespace std;
char alertString[100] = " Battery Status Out of Range Alert!! For: ";
char lowWarningString[100] = "Battery Status low Warning!!For : ";
char highWarningString[100] = "Battery Status high Warning!!For :";
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

bool IsParameterWithinLimit(float parameterValue, float max_limit,const char* parameter) {
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
bool IsEarlyLowAlertRequired(float parameterValue, float min_threshold, const char* parameter){
	char statement[100];
	bool earlyAlertLimitReached = false;
	if((parameterValue -4) < min_threshold)
	{
	    strcpy(statement, lowWarningString);
	    strcat(statement, parameter);
	    earlyAlertLimitReached = true;
	}
        if (earlyAlertLimitReached) {
		(*fpPrint)(statement);
	}
	return earlyAlertLimitReached;
}

bool IsEarlyHighAlertRequired(float parameterValue, float max_threshold, const char* parameter){
	char statement[100];
	bool earlyAlertLimitReached = false;
        if((parameterValue + 4) > max_threshold){
	    strcpy(statement, highWarningString);
	    strcat(statement, parameter);
	    earlyAlertLimitReached = true;
	}
        if (earlyAlertLimitReached) {
		(*fpPrint)(statement);
	}
	return earlyAlertLimitReached;
}
float convertParamtoStandardUnit(ParameterTypeEnum parameter ,float parameterValue , string unit)
{
  switch(parameter)
  case e_TEMPERATURE:
       convertTempToCelcius(parameterValue,unit);
	   break;
  case e_SoC:
  //define fn here
        break;
  case e_CHARGERATE:
       break;
  default:
	   break;
}
  
  
}
float convertTempToCelcius(float temperature, string unit)
{
    if(unit == "F")
        return ((temperature - 32.0)/1.8);
    else 
        return temperature;
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

bool getBatteryTempStatus(TemperatureStruct temperature) {
	bool status;
	temperature = convertParamtoStandardUnit(e_TEMPERATURE,temperature.tempValue,temperature.tempUnit);
	status = IsParameterInRange(temperature.tempValue, MIN_THRESHOLD_TEMP, MAX_THRESHOLD_TEMP);
	status = getParameterStatus(status, "Temperature");
	if(status){
		bool l_earlyLowAlert = IsEarlyLowAlertRequired(temperature, MIN_THRESHOLD_TEMP,"Temperature");
		bool l_earlyHighAlert = IsEarlyHighAlertRequired(temperature, MIN_THRESHOLD_TEMP,"Temperature");
	}
	return status;
}
bool getBatterySoCStatus(float SoC) {
	bool status;
	status = IsParameterInRange(SoC, MIN_THRESHOLD__SoC, MAX_THRESHOLD_SoC);
	status = getParameterStatus(status, "State of Charge");
	if(status){
		bool l_earlyLowAlert = IsEarlyLowAlertRequired(SoC, MIN_THRESHOLD__SoC,"State of Charge");
		bool l_earlyHighAlert = IsEarlyHighAlertRequired(SoC, MAX_THRESHOLD_SoC,"State of Charge");
	}
	return status;
}
bool getBatteryChargingRateStatus(float chargingRate){
	bool status;
	status = IsParameterWithinLimit(chargingRate, MAX_THRESHOLD_CHARGE_RATE, "Charge Rate");
	status = getParameterStatus(status, "Charge Rate");
	return status;
}

bool getOverallBatteryStatus(TemperatureStruct temperature, float SoC, float chargingRate){
	bool batt_status;
	batt_status =(getBatteryTempStatus(temperature)) && (getBatterySoCStatus(SoC)) && (getBatteryChargingRateStatus(chargingRate));
	return batt_status;	
}
