#include <iostream>
#include "Standartio.h"
#include "MathFunctions.h"
#include "Scienseio.h"

std::string ScientificCAL::calSC(int a) {
	Calculate calc;
	switch (a)
	{
	case 1:
		std::cout << "¬ведите число:";
		int i1;
		std::cin >> i1;
		std::cout << calc.absolute(i1);
		break;
	case 2:
		std::cout << "¬ведите число:";
		double i2;
		std::cin >> i2;
		std::cout << calc.sqruareroot(i2);
		break;
	case 3:
		std::cout << "¬ведите число:";
		double i3;
		std::cin >> i3;
		std::cout << calc.reciprocalFunc(i3);
		break;
	default:
		std::cout << "ќй, вы выбрали что-то не то. »змените свой выбор";
		break;
	}
	std::string result = "Yep";
	return result;
}