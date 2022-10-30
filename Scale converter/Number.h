#pragma once
#include <string>

using std::string;
using std::to_string;

class Number
{
public:
	Number();
	Number(int number);
	Number(string number, int scale);
	Number convert(int newScale);
	static Number convert(Number* number, int newScale);
	int toTenScale();
	string getNumber() { return number + string("(") + string(to_string(this->scale)) + string(")"); }
	int getScale() { return scale; }
	Number operator+(Number number);
	Number operator-(Number number);
	Number operator*(Number number);
	Number operator/(Number number);
private:
	string number;
	int scale;
};

