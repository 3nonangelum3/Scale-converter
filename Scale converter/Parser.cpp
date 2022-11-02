#include "Parser.h"
#include "Validator.h"

Number* Parser::parseNumber(string input, bool &validInput)
{
	bool scaleStarted = false;
	string number, scale;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			scaleStarted = true;
			continue;
		}
		if (input[i] == ')')
			continue;
		if (scaleStarted)
		{
			scale += input[i];
		}
		else {
			number += input[i];
		}
	}
	if (scale == "") {
		scale = "10";
	}
	if (Validator::valideScaleInput(stoi(scale)))
	{
		Number* num = new Number(number, stoi(scale));
		validInput |= Validator::validateNumberInput(num);
		return num;
	}
	else {
		validInput = false;
		return new Number();
	}
}