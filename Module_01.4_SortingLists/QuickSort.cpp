#include "QuickSort.h"

static int Partion(int numbers[], int i, int k) {
    int l = 0;
    int h = 0;
    int midPoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    midPoint = i + (k - i) / 2;     //find middle element
    pivot = numbers[midPoint];      //set to pivot

    l = i;
    h = k;

    while (!done) {
        while (numbers[l] < pivot) {        //while the element @ numbers[l] is less than the pivot, increment l
            ++l;
        }
        while (pivot < numbers[h]) {        //while the pivot is less than the element @ numbers[h], decrement h
            --h;
        }
        if (l >= h) {               //l and h are the same, partion is complete
            done = true;
        }
        else {                      //swap numbers[l] and numbers[h]
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }

    }
    return h;
}

static void QuickSort(int numbers[], int i, int k) {
    int j = 0;

    //base case: one or zero elements, partition is sorted
    if (i >= k) {
        return;
    }

    //partition data within array, 'j' is location of last element in 'low' partition
    j = Partion(numbers, i, k);

    //recursive sort low partion (i to j), and high partion (j + 1 to k)
    QuickSort(numbers, i, j);
    QuickSort(numbers, j + 1, k);

    return;

}
