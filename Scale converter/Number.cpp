#include "Number.h"
#include "Ascii.h"
#include <string>

using std::to_string;

Number::Number() : Number(0) {}
Number::Number(int number) : number(to_string(number)), scale(10) {}
Number::Number(string number, int scale) : number(number), scale(scale) {}

string reverseString(string input) {
	std::string answer = "";
	for (size_t i = input.length() - 1; i < input.length(); i--)
	{
		answer += input[i];
	}
	return answer;
}

Number Number::convert(int newScale)
{
	string answer = "";
	int num = this->toTenScale();
	while (num) {
		answer += Ascii::convertToChar(num % newScale);
		num /= newScale;
	}
	this->number = reverseString(answer);
	this->scale = newScale;
	return Number(reverseString(answer), newScale);
}
Number* Number::convert(Number* number, int newScale)
{
	string answer = "";
	int num = number->toTenScale();
	while (num) {
		answer += Ascii::convertToChar(num % newScale);
		num /= newScale;
	}
	return new Number(reverseString(answer), newScale);
}

int Number::toTenScale()
{
	int sum = 0;
	for (int i = 0; i < this->number.length(); i++)
	{
		sum += Ascii::toTenScale(this->number[i]) * pow(this->scale, this->number.length() - 1 - i);
	}
	return sum;
}

Number Number::operator+(Number number)
{
	int result = this->toTenScale() + number.toTenScale();
	if (this->scale == number.scale)
	{
		return Number(Number::convert(new Number(result), scale)->getNumber(), scale);
	}
	else {
		return Number(result);
	}
}
Number Number::operator-(Number number)
{
	int result = this->toTenScale() - number.toTenScale();
	if (this->scale == number.scale)
	{
		return Number(Number::convert(new Number(result), scale)->getNumber(), scale);
	}
	else {
		return Number(result);
	}
}
Number Number::operator*(Number number)
{
	int result = this->toTenScale() * number.toTenScale();
	if (this->scale == number.scale)
	{
		return Number(Number::convert(new Number(result), scale)->getNumber(), scale);
	}
	else {
		return Number(result);
	}
}
Number Number::operator/(Number number)
{
	int result = this->toTenScale() / number.toTenScale();
	if (this->scale == number.scale)
	{
		return Number(Number::convert(new Number(result), scale)->getNumber(), scale);
	}
	else {
		return Number(result);
	}
}