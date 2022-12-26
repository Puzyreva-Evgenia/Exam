#pragma once
#include <ctime>
class Note
{
public:
	Note(std::string text);

	~Note();
	std::string GetText();
	void SetText(std::string text);

private:
	std::string text;
};

Note::Note(std::string text)
{
	this->text = text;
}

Note::~Note()
{
}

std::string Note::GetText() {
	return this->text;
}
void Note::SetText(std::string text) {
	this->text = text;
}