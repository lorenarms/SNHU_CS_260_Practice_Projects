#include <iostream>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "MergeSort.cpp"
#include "SortingLists.h"
#include "SelectionSort.cpp"
#include "QuickSort.cpp"


using namespace std;

int main() {

    int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
    
    const int NUMBERS_SIZE = 8;
    int i = 0;

    cout << "UNSORTED: ";
    for (i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << ' ';
    }
    cout << endl;

  
    MergeSort(numbers, 0, NUMBERS_SIZE - 1);
    QuickSort(numbers, 0, NUMBERS_SIZE - 1);

    SelectionSort(numbers, NUMBERS_SIZE);

    cout << "SORTED: ";
    for (i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << ' ';
    }
    cout << endl;

    cin.get();

    return 0;

}
