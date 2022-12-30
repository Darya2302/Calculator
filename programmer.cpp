#include <iostream>
#include <vector>
#include <cmath>
#include "Programmer.h"

using namespace std;

int value(int term) {//вычисляет размер вектора после перевода в двоичную систему
	int quantity = 0;
	while (term >= 2) {
		term /= 2;
		quantity++;
	}
	return quantity;
}

vector <int> bitwise(int term) {//перевод из десятичной системы счисления в двоичную
	int ter = term;
	int quantity = value(term);

	vector <int> bit(quantity + 1);

	int i = quantity;

	while (ter >= 2) {
		bit[i] = ter % 2;
		ter /= 2;
		i--;
		if (ter < 2) {
			bit[i] = ter;
		}
	}

	return bit;
}

int decimal(vector <int> term, int quantity) {//перевод из двоичной системы счисления в десятичную
	int answer = 0;

	for (int j = 0; j <= quantity; j++) {
		answer += term[j] * pow(2, quantity - j);
	}

	return answer;
}

vector <int> biggest(int term1, int term2) {//подгоняет меньший вектор в двоичной системе к большему
	int quantity1 = value(term1), quantity2 = value(term2);
	int shift;

	if (quantity1 > quantity2) {
		vector <int> new_term1(quantity1 + 1);
		new_term1 = bitwise(term1);

		vector <int> old_term2(quantity2 + 1);
		old_term2 = bitwise(term2);

		vector <int> new_term2(quantity1 + 1);

		shift = quantity1 - quantity2;
		for (int i = 0; i < shift; i++) {
			new_term2[i] = 0;
		}
		for (int i = shift; i <= quantity2; i++) {
			new_term2[i] = old_term2[i - shift];
		}
		return new_term2;
	}
	else if (quantity2 > quantity1) {
		shift = quantity2 - quantity1;

		vector <int> old_term1(quantity1 + 1);
		old_term1 = bitwise(term1);

		vector <int> new_term2(quantity2 + 1);
		new_term2 = bitwise(term2);

		vector <int> new_term1(quantity2 + 1);

		for (int i = 0; i < shift; i++) {
			new_term1[i] = 0;
		}
		for (int i = shift; i <= quantity1; i++) {
			new_term1[i] = old_term1[i - shift];
		}
		return new_term1;
	}
	else {
		vector <int> new_term1(quantity1 + 1);
		new_term1 = bitwise(term1);
		return new_term1;
	}
}

int bitwiseNOT(int term) {

	int quantity = value(term);

	vector <int> bit_term(quantity + 1);

	bit_term = bitwise(term);

	vector <int> new_term(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if (bit_term[j] == 0) {
			new_term[j] = 1;
		}
		else new_term[j] = 0;

	}
	return decimal(new_term, quantity);
}

vector <int> max(int term1, int term2) {
	int quantity1 = value(term1), quantity2 = value(term2);
	if (quantity1 > quantity2) {
		vector <int> new_term1(quantity1 + 1);
		new_term1 = bitwise(term1);
		return new_term1;
	}
	else if (quantity2 > quantity1) {
		vector <int> new_term2(quantity2 + 1);
		new_term2 = bitwise(term2);
		return new_term2;
	}
	else {
		vector <int> new_term2(quantity2 + 1);
		new_term2 = bitwise(term2);
		return new_term2;
	}
}


int bitwiseAND(int term1, int term2) {

	vector <int> new_term1 = biggest(term1, term2);
	vector <int> new_term2 = max(term1, term2);

	int quantity = value(term1);

	vector <int> answer(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if (new_term1[j] == 1 && new_term2[j] == 1) {
			answer[j] = 1;
		}
		else answer[j] = 0;

	}

	return decimal(answer, quantity);
}

int bitwiseOR(int term1, int term2) {

	vector <int> new_term1 = biggest(term1, term2);
	vector <int> new_term2 = max(term1, term2);

	int quantity = value(term1);

	vector <int> answer(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if (new_term1[j] == 1 || new_term2[j] == 1) {
			answer[j] = 1;
		}
		else answer[j] = 0;

	}

	return decimal(answer, quantity);
}

int bitwiseXOR(int term1, int term2) {

	vector <int> new_term1 = biggest(term1, term2);
	vector <int> new_term2 = max(term1, term2);

	int quantity = value(term1);

	vector <int> answer(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if ((new_term1[j] == 1 && new_term2[j] == 1) || (new_term1[j] == 0 && new_term2[j] == 0)) {
			answer[j] = 0;
		}
		else answer[j] = 1;

	}

	return decimal(answer, quantity);
}

int bitwiseNAND(int term1, int term2) {

	vector <int> new_term1 = biggest(term1, term2);
	vector <int> new_term2 = max(term1, term2);

	int quantity = value(term1);

	vector <int> answer(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if (new_term1[j] == 1 && new_term2[j] == 1) {
			answer[j] = 0;
		}
		else answer[j] = 1;

	}

	return decimal(answer, quantity);
}

int bitwiseNOR(int term1, int term2) {

	vector <int> new_term1 = biggest(term1, term2);
	vector <int> new_term2 = max(term1, term2);

	int quantity = value(term1);

	vector <int> answer(quantity + 1);

	for (int j = 0; j <= quantity; j++) {
		if (new_term1[j] == 1 || new_term2[j] == 1) {
			answer[j] = 0;
		}
		else answer[j] = 1;

	}

	return decimal(answer, quantity);
}

char logicNOT(char term) {

	char answer;
	if (term == 'T') {
		answer = 'F';
	}
	else answer = 'T';
	return answer;
}

char logicAND(char term1, char term2) {

	char answer;
	if (term1 == 'T' && term2 == 'T') {
		answer = 'T';
	}
	else answer = 'F';
	return answer;
}

char logicOR(char term1, char term2) {

	char answer;
	if (term1 == 'F' && term2 == 'F') {
		answer = 'F';
	}
	else answer = 'T';
	return answer;
}

char logicXOR(char term1, char term2) {

	char answer;
	if ((term1 == 'F' && term2 == 'F') || (term1 == 'T' && term2 == 'T')) {
		answer = 'F';
	}
	else answer = 'T';
	return answer;
}

char logicNAND(char term1, char term2) {

	char answer;
	if (term1 == 'T' && term2 == 'T') {
		answer = 'F';
	}
	else answer = 'T';
	return answer;
}

char logicNOR(char term1, char term2) {

	char answer;
	if (term1 == 'F' && term2 == 'F') {
		answer = 'T';
	}
	else answer = 'F';
	return answer;
}

int main() {

	int operation;
	std::cout << "Выберите операцию:\n1. bitwise NOT\n2. bitwise AND\n3. bitwise OR\n4. bitwise XOR\n";
	std::cout << "5. bitwise NAND\n6. bitwise NOR\n7. logic NOT\n8. logic AND\n";
	std::cout << "9. logic OR\n10. logic XOR\n11. logic NAND\n12. logic NOR\n";
	std::cin >> operation;

	if (operation == 1) {
		int term;
		std::cout << "Введите значение:" << std::endl;
		std::cin >> term;
		int answer1 = bitwiseNOT(term);
		std::cout << answer1;
	}
	else if (operation == 2) {
		int term1, term2;
		std::cout << "Введите 2 значения:" << std::endl;
		std::cin >> term1 >> term2;
		int answer2 = bitwiseAND(term1, term2);
		std::cout << answer2;
	}
	if (operation == 3) {
		int term1, term2;
		std::cout << "Введите 2 значения:" << std::endl;
		std::cin >> term1 >> term2;
		int answer3 = bitwiseOR(term1, term2);
		std::cout << answer3;
	}
	else if (operation == 4) {
		int term1, term2;
		std::cout << "Введите 2 значения:" << std::endl;
		std::cin >> term1 >> term2;
		int answer4 = bitwiseXOR(term1, term2);
		std::cout << answer4;
	}
	if (operation == 5) {
		int term1, term2;
		std::cout << "Введите 2 значения:" << std::endl;
			std::cin >> term1 >> term2;
		int answer;
		answer = bitwiseNAND(term1, term2);
		std::cout << answer;
	}
	else if (operation == 6) {
		int term1, term2;
		std::cout << "Введите 2 значения:" << std::endl;
		std::cin >> term1 >> term2;
		int answer = bitwiseNOR(term1, term2);
		std::cout << answer;
	}
	else if (operation == 7) {
		char term;
		std::cout << "Введите значение выражения (T or F):" << std::endl;
		std::cin >> term;
		char answer = logicNOT(term);
		std::cout << answer;
	}
	else if (operation == 8) {
		char term1, term2;
		std::cout << "Введите значения двух выражений (T or F):" << std::endl;
		std::cin >> term1 >> term2;
		char answer = logicAND(term1, term2);
		std::cout << answer;
	}
	else if (operation == 9) {
		char term1, term2;
		std::cout << "Введите значения двух выражений (T or F):" << std::endl;
		std::cin >> term1 >> term2;
		char answer = logicOR(term1, term2);
		std::cout << answer;
	}
	else if (operation == 10) {
		char term1, term2;
		std::cout << "Введите значения двух выражений (T or F):" << std::endl;
		std::cin >> term1 >> term2;
		char answer = logicXOR(term1, term2);
		std::cout << answer;
	}
	else if (operation == 11) {
		char term1, term2;
		std::cout << "Введите значения двух выражений (T or F):" << std::endl;
		std::cin >> term1 >> term2;
		char answer = logicNAND(term1, term2);
		std::cout << answer;
	}
	else if (operation == 12) {
		char term1, term2;
		std::cout << "Введите значения двух выражений (T or F):" << std::endl;
		std::cin >> term1 >> term2;
		char answer = logicNOR(term1, term2);
		std::cout << answer;
	}

	return 0;
}