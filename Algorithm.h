#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <cstddef>

namespace ads
{
    void swap(int* a, int* b);
    void swap(int& a, int& b);
    void bubblesort(int* array, size_t size);
    int add(int a, int b);
}

#endif // ALGORITHM_H
