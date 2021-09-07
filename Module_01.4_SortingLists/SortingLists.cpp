#include <iostream>

using namespace std;

void SelectionSort(int numbers[], int numbersSize) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;

	int temp = 0;  // Temporary variable for swap

    for (i = 0; i < numbersSize - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {

            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }

}

void InsertionSort(int numbers[], int numbersSize) {
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

int Partion(int numbers[], int i, int k) {
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

void QuickSort(int numbers[], int i, int k) {
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

void Merge(int numbers[], int i, int j, int k) {
    int mergedSize = k - i + 1;                // Size of merged partition
    int mergePos = 0;                          // Position to insert merged number
    int leftPos = 0;                           // Position of elements in left partition
    int rightPos = 0;                          // Position of elements in right partition
    int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                               // for merged numbers

    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
}

void MergeSort(int numbers[], int i, int k) {
    int j = 0;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}


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
    //QuickSort(numbers, 0, NUMBERS_SIZE - 1);
    //SelectionSort(numbers, NUMBERS_SIZE);

    cout << "SORTED: ";
    for (i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << ' ';
    }
    cout << endl;

    cin.get();

    return 0;

}
