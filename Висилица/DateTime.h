#pragma once
#include <string>
struct DateTime {
	int year;
	int month; 
	int day;
	int hour; 
	int minute;
	DateTime (int year, int month, int day, int hour, int minute) {
		SetTime(year, month, day, hour, minute);
	}
	DateTime(){}
	std::string GetTime() {
		std::string time = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute);
		return time;
	}
	void SetTime(int year, int month, int day, int hour, int minute) {
		this->year = year;
		this->month = month;
		this->day =day;
		this->hour = hour;
		this->minute = minute;
	}
};