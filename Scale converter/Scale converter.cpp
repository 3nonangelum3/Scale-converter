#include <iostream>
#include <string>
#include "Action.h"
#include "Number.h"
#include "Validator.h"
#include "Parser.h"

using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	while (true) {
		Action action;
		do
		{
			cout << "Select action: \n" <<
				"<convert> or <1>\n" <<
				"<calculate> or <2>\n" <<
				"<end> or <-1> (you will exit)" << endl <<
				">>>";
			string actionS = "";
			getline(cin, actionS);
			cin.ignore(20000, '\n');
			cin.clear();
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
			if (actionS == "end" || actionS == "-1" ||
				actionS == "<end>" || actionS == "<-1>" ||
				actionS == "<end> or <-1>")
			{
				action = Action::END;
				break;
			}
			cout << "Invalid input!!!" << endl;
		} while (true);
		if (action == Action::END)
		{
			break;
		}
		if (action == Action::CONVERT)
		{
			Number number;
			bool validInput = true;
			do
			{
				cout << "Enter a number an scale in brakes like number(scale)\n" <<
					">>>" << endl;
				string input = "";
				cin >> input;
				cin.ignore(20000, '\n');
				cin.clear();
				number = *Parser::parseNumber(input, validInput);
			} while (!validInput);
			do
			{
				cout << "Enter a new scale" <<
					">>>" << endl;
				int scale;
				cin >> scale;
				cin.ignore(20000, '\n');
				cin.clear();
				if (Validator::valideScaleInput(scale) && scale != number.getScale())
				{
					break;
				}
			} while (true);
		}
	}
}