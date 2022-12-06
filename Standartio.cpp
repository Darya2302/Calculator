#include <iostream>
#include "Standartio.h"
#include "MathFunctions.h"

std::string StandartCAL::cal(int term1, char choice, int term2) {
	Calculate calc;
	switch (choice)
	{
	case '+':
		std::cout << calc.sum(term1, term2);
		break;
	case '-':
		std::cout << calc.sub(term1, term2);
		break;
	case '*':
		std::cout << calc.mult(term1, term2);
		break;
	case '/':
		std::cout << calc.division(term1, term2);
		break;
	case '%':
		std::cout << calc.mod(term1, term2);
		break;

	default:
		std::cout << "��, �� ������� ���-�� �� ��. �������� ���� �����";
		break;
	}
	std::string result = "Yep";
	return result;
}