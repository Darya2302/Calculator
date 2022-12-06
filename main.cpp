#include <iostream>
#include "MathFunctions.h"
#include "Standartio.h"
#include "Scienseio.h"


int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Выберите тип калькулятора:\n1.Стандартный\n2.Программистский\n3.Научный\n4.Сортировка\n";
	int type;
	std::cin >> type;
	switch (type){
	case 1:
		std::cout << "Вы можете использовать:\n+(сумма)\n-(разность)\n*(произведение)\n/(разность)\n%(деление по модулю)\nВведите выражение:";
		StandartCAL calcST;
		int term1, term2;
		char choice;
		std::cin >> term1 >> choice >> term2;
		calcST.cal(term1, choice, term2);
		break;
	case 2:
		break;
	case 3:
		std::cout << "Выберите операцию:\n1.Взятие модуля\n2.Нахождение квадратного корня\n3.Нахождение обратного\n";
		Calculate calc3;
		ScientificCAL calSc;
		int i;
		std::cin >> i;
		calSc.calSC(i);
		break;
	case 4:
		break;
	default:
		std::cout << "Ой, вы выбрали что-то не то. Измените свой выбор!";
		break;
	}
	}