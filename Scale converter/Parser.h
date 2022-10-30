#pragma once
#include <string>
#include "Number.h"

using std::string;

class Parser
{
public:
	static Number* parseNumber(string input, bool& validInput);
};

