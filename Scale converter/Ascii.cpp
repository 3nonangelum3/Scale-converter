#include "Ascii.h"
char Ascii::convertToChar(int number)
{
	switch (number)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	default: if (number >= 10 && number <= 35) return static_cast<char>(number + 55);
	}
}
int Ascii::toTenScale(char symbol)
{
	switch (symbol)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: if (symbol >= 'A' && symbol <= 'Z') return static_cast<int>(symbol) - 55;
	}
}