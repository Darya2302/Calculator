#pragma once
#include<iostream>

void insertionSort(int data[], int len);
	void shellSort(int list[], int len);
	void bubbleSort(int list[], int len);
	void oddEvenSort(int list[], int len);
	void shakerSort(int list[], int len);
	void combSort(int list[], int len);

	void sort();

class knode {
public:
	int info;
	knode* next;
	explicit knode(int _val) : info(_val), next(nullptr) {}
};

class list {
public:
	knode* first;
	knode* last;
	list() :first(nullptr), last(nullptr) {};
	int size = 0;
	bool is_empty();
	void push_back(int val);
	void printlist();
}