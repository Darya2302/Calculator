#include <iostream>
#include "MathFunctions.h"
#include "Standartio.h"
#include "Scienseio.h"


int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "�������� ��� ������������:\n1.�����������\n2.���������������\n3.�������\n4.����������\n";
	int type;
	std::cin >> type;
	switch (type){
	case 1:
		std::cout << "�� ������ ������������:\n+(�����)\n-(��������)\n*(������������)\n/(��������)\n%(������� �� ������)\n������� ���������:";
		StandartCAL calcST;
		int term1, term2;
		char choice;
		std::cin >> term1 >> choice >> term2;
		calcST.cal(term1, choice, term2);
		break;
	case 2:
		break;
	case 3:
		std::cout << "�������� ��������:\n1.������ ������\n2.���������� ����������� �����\n3.���������� ���������\n";
		Calculate calc3;
		ScientificCAL calSc;
		int i;
		std::cin >> i;
		calSc.calSC(i);
		break;
	case 4:
		break;
	default:
		std::cout << "��, �� ������� ���-�� �� ��. �������� ���� �����!";
		break;
	}
	}