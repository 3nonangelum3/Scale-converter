#include <iostream>
#include <string>
#include <vector>
#include "Action.h"
#include "Number.h"
#include "Calculator.h"
#include "Validator.h"
#include "Parser.h"

using std::getline;
using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::vector;

vector<string> split(string text, char symbol) {
	vector<string> result = {};
	string temp = "";
	for (auto& i : text)
	{
		if (i == symbol)
		{
			if (temp.size())
			{
				result.push_back(temp);
			}
			temp = "";
		}
		else {
			temp += i;
		}
	}
	if (temp.size())
	{
		result.push_back(temp);
	}
	return result;
}

int main()
{
#pragma region What to do
	Action action;
	do
	{
		cout << "Select action: \n" <<
			"<convert> or <1>\n" <<
			"<calculate> or <2>\n" << endl <<
			">>> ";
		string actionS = "";
		cin.clear();
		getline(cin, actionS);
		cin.clear();
		cout << endl;
		bool valid = false;
		if (actionS == "convert" || actionS == "1" ||
			actionS == "<convert>" || actionS == "<1>" ||
			actionS == "<convert> or <1>")
		{
			action = Action::CONVERT;
			break;
		}
		if (actionS == "calculate" || actionS == "2" ||
			actionS == "<calculate>" || actionS == "<2>" ||
			actionS == "<calculate> or <2>")
		{
			action = Action::CALCULATE;
			break;
		}
		cout << "Invalid input!!!" << endl;
	} while (true);
#pragma endregion
#pragma region Scenarios
	if (action == Action::CONVERT)
	{
		Number number;
		bool validInput = true;
		do
		{
			cout << "Enter a number an scale in brakes like number(scale)\n\n" <<
				">>> ";
			string input = "";
			cin >> input;
			cout << endl;
			cin.clear();
			number = *Parser::parseNumber(input, validInput);
		} while (validInput);
		do
		{
			cout << "Enter a new scale\n\n" <<
				">>> ";
			int scale;
			cin >> scale;
			cin.clear();
			cout << endl;
			if (Validator::valideScaleInput(scale) && scale != number.getScale())
			{
				number.convert(scale);
				cout << "result: " << number.toString() << endl << endl;
				break;
			}
		} while (true);
	}
	if (action == Action::CALCULATE)
	{
		Number startNumber = Number();
		do
		{
			cout << "Enter an expression like number(scale) symbol number(scale) ...(other numbers)\n\n" <<
				">>> ";
			string line = "";
			getline(cin, line);
			cin.clear();
			vector<string> splited = split(line, ' ');
			bool validInput = true;
			startNumber = *Parser::parseNumber(splited.at(0), validInput);
			if (!validInput)
			{
				cout << "invalid input!!!" << endl;
				continue;
			}
			for (int i = 1; i < splited.size() - 1; i += 2)
			{
				char sign = splited[i][0];
				Number* num = Parser::parseNumber(splited[i + 1], validInput);
				if (!validInput)
				{
					cout << "invalid input!!!" << endl;
					break;
				}
				startNumber = Calculator::calculate(&startNumber, num, sign);
				validInput = false;
			}
			if (!validInput)
			{
				break;
			}
		} while (true);
		cout << "result: " << startNumber.toString() << endl;
	}
#pragma endregion
}