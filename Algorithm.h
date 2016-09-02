#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace ads
{
    void swap(int* a, int* b)
    {
        int tmp = a;
        *a = *b;
        *b = tmp;
    }

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = a;
    }

    void bubblesort(int* array, size_t size)
    {
        bool sorted = false;
		bool firstRun = true;
		while (firstRun || !sorted) {
			firstRun = false;
			sorted = true;
			for (int i = 0; i < size - 1; i++) {
				if (array[i] > array[i + 1]) {
					swap(array, i, i + 1);
					sorted = false;
				}
			}
		}
    }
}

#endif // ALGORITHM_H
