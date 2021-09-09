#include "InsertionSort.h"

static void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap

    for (i = 1; i < numbersSize; ++i) {
        j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && numbers[j] < numbers[j - 1]) {

            // Swap numbers[j] and numbers[j - 1]
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }

    return;
}

