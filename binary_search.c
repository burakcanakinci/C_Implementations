/* Write a function which performs binary search. The prototype of the function is: */
/* "unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)", where */
/* pArray is pointer to sorted array with ascending order of elements, uArraySize is number of elements in */
/* the array and uValue is the searched value. If the uValue is found, the function should return it index, */
/* otherwise 0xFFFF.  */

#include <stdio.h>

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue) {
    int low = 0;
    int high = uArraySize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (pArray[mid] == uValue) {
            return mid;  // Value found, return its index
        } else if (pArray[mid] < uValue) {
            low = mid + 1;  // Discard left half
        } else {
            high = mid - 1;  // Discard right half
        }
    }
    return 0xFFFF;  // Value not found
}

int main() {
    unsigned int sortedArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    unsigned int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    unsigned int searchValue = 80;

    unsigned int result = BinSearch(sortedArray, arraySize, searchValue);

    if (result != 0xFFFF) {
        printf("Value %u found at index %u\n", searchValue, result);
    } else {
        printf("Value %u not found in the array\n", searchValue);
    }

    return 0;
}
