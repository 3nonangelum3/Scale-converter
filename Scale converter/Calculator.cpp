#include "Calculator.h"

Number Calculator::calculate(Number* a, Number* b, char sign)
{
	switch (sign)
	{
	case '+': return *a + *b;
	case '-': return *a - *b;
	case '*': return *a * *b;
	case '/': return *a / *b;
	default: return 0;
	}
}
