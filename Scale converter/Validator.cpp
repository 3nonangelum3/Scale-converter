#include "Validator.h"
#include "Ascii.h"

bool Validator::validateNumberInput(Number* Number) {
	string number = Number->getNumber();
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] < '0' || (number[i] > '9' && number[i] < 'A') || number[i] > 'Z') return false;
	}
	for (int i = 0; i < number.length(); i++)
	{
		if (Ascii::convertToChar(number[i]) >= Number->getScale()) return false;
	}
	return true;
}
bool Validator::valideScaleInput(int scale) {
	return scale > 1 && scale <= 35;
}