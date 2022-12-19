#pragma once
#include <ctime>
#include <iostream>
#include "DateTime.h"
class Note
{
public:
	Note(DateTime time, std::string text);

	~Note();
	std::string GetTime();
	void SetTime(int year, int month, int day, int hour, int minute);
	std::string GetText();
	void SetText(std::string text);

private:
	DateTime time;
	std::string text;
};

Note::Note(DateTime time, std::string text)
{
	this->time = time;
	this->text = text;
}

Note::~Note()
{
}
std::string Note::GetTime() {
	return this->time.GetTime();
}
void Note::SetTime(int year, int month, int day, int hour, int minute) {
	this->time.SetTime(year, month, day, hour, minute);
}
std::string Note::GetText() {
	return this->text;
}
void Note::SetText(std::string text) {
	this->text = text;
}