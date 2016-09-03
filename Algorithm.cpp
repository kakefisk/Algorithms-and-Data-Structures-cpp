#include "Algorithm.h"

int ads::add(int a, int b)
{
    return a + b;
}

void ads::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ads::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void ads::bubblesort(int* array, size_t size)
{
    bool sorted = false;
    bool firstRun = true;
    while (firstRun || !sorted) {
        firstRun = false;
        sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
    }
}
