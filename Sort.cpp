#include<iostream>
#include "Sort.h"

void insertionSort(int list[], int len)
{
    int key = 0;
    int i = 0;
    for (int j = 1; j < len; j++) {
        key = list[j];
        i = j - 1;
        while (i >= 0 && list[i] > key) {
            list[i + 1] = list[i];
            i = i - 1;
            list[i + 1] = key;
        }
    }
}

void shellSort(int list[], int len)
{
    for (int step = len / 2; step > 0; step /= 2)
    {
        for (int i = step; i < len; i += 1)
        {
            int j = i;
            while (j >= step && list[j - step] > list[i])
            {
                swap(list[j], list[j - step]);
                j -= step;
                cout << "\n";
            }
        }
    }
}

void bubbleSort(int list[], int len)
{
    while (len--)
    {
        bool swapped = false;

        for (int i = 0; i < len; i++)
        {
            if (list[i] > list[i + 1])
            {
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void oddEvenSort(int list[], int len)
{
    bool isSorted = false; 

    while (!isSorted) {
        isSorted = true;

        for (int i = 1; i <= len - 2; i = i + 2) {
            if (list[i] > list[i + 1]) {
                swap(list[i], list[i + 1]);
                isSorted = false;
            }
        }

        for (int i = 0; i <= len - 2; i = i + 2) {
            if (list[i] > list[i + 1]) {
                swap(list[i], list[i + 1]);
                isSorted = false;
            }
        }
    }

    return;
}

void shakerSort(int list[], int len)
{
    int tmp, k;
    int s = len; 
    long long cnt = 0;
    while (len > 1) {
        if (s < 1) s = 1;
        k = 0; 
        for (int i = 0; i + s < len; ++i) { 
            if (list[i] / 10 > list[i + s] / 10) {
                tmp = list[i];
                list[i] = list[i + s];
                list[i + s] = tmp;
                k = i;
            }
            ++cnt;
        }
        if (s == 1)
            len = k + 1;
    }
}

void combSort(int list[], int len) {
    int sz = len - list;
    if (sz <= 1) return;
    double k = 1;
    int step = sz - 1;
    while (step > 1) {
        for (int* i = list; i + step < len; i++) {
            if (*i > *(i + step))
                swap(*i, *(i + step));
        }
        step /= k;
    }
    bool b = true;
    while (b) {
        b = false;
        for (int* i = list; i + 1 < len; i++) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                b = true;
            }
        }
    }
}

bool list::is_empty() {
    return first == nullptr;
}

void list::push_back(int val) {
    knode* p = new knode(val);
    if (is_empty()) {
        first = p;
        last = p;
        size++;
        return;

    }

    last->next = p;
    last = p;
}


void  list::printlist() {
    knode* p = first;
    if (is_empty())return;
    while (p != nullptr) {
        std::cout << p->info << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void sort() {
    std::cout << "Введите длину списка: ";
    int n;
    std::cin >> n;
    list l;
    std::cout << "Введите " << n << " элементов для сортировки : ";
    for (int i = 1; i <= n; ++i) {
        int val;
        std::cin >> val;
        l.push_back(val);
    }
    std::cout << "Выберите сортировку:\n1.Сортировка вставками\n2.Сортировка Шелла\n3.Пузырьковая сортировка\n4.Четно-нечетная сортировка\n5.Шейкерная сортировка\n6.Сортировка расчёской\n";
    int type;
    std::cin >> type;
    switch (type) {
    case 1: insertionSort(l, n);
    case 2:shellSort(l, n);
    case 3:bubbleSort(l, n);
    case 4:oddEvenSort(l, n);
    case 5:shakerSort(l, n);
    case 6:combSort(l, n);
    }
 
}