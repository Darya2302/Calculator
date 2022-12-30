#include <iostream>
#include "MathFunctions.h"
#include "Standartio.h"
#include "Scienseio.h"
#include "Sort.h"


int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Âûáåðèòå òèï êàëüêóëÿòîðà:\n1.Ñòàíäàðòíûé\n2.Ïðîãðàììèñòñêèé\n3.Íàó÷íûé\n4.Ñîðòèðîâêà\n";
	int type;
	std::cin >> type;
	switch (type){
	case 1:
		std::cout << "Âû ìîæåòå èñïîëüçîâàòü:\n+(ñóììà)\n-(ðàçíîñòü)\n*(ïðîèçâåäåíèå)\n/(ðàçíîñòü)\n%(äåëåíèå ïî ìîäóëþ)\nÂâåäèòå âûðàæåíèå:";
		StandartCAL calcST;
		int term1, term2;
		char choice;
		std::cin >> term1 >> choice >> term2;
		calcST.cal(term1, choice, term2);
		break;
	case 2:
		break;
	case 3:
		std::cout << "Âûáåðèòå îïåðàöèþ:\n1.Âçÿòèå ìîäóëÿ\n2.Íàõîæäåíèå êâàäðàòíîãî êîðíÿ\n3.Íàõîæäåíèå îáðàòíîãî\n";
		Calculate calc3;
		ScientificCAL calSc;
		int i;
		std::cin >> i;
		calSc.calSC(i);
		break;
	case 4: sort();
		break;
	default:
		std::cout << "Îé, âû âûáðàëè ÷òî-òî íå òî. Èçìåíèòå ñâîé âûáîð!";
		break;
	}
	}
