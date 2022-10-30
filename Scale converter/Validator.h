#pragma once
#include <string>
#include "Number.h"

using std::string;

class Validator
{
public:
	static bool validateNumberInput(Number* Number);
	static bool valideScaleInput(int scale);
};

