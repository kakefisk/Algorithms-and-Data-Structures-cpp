#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <cstddef>

namespace ads
{
    void swap(int* a, int* b);
    void swap(int& a, int& b);
    void bubblesort(int* array, size_t size);
    int add(int a, int b);
    int max(int* array, size_t size);
    int min(int* array, size_t size);
}

#endif // ALGORITHM_H
