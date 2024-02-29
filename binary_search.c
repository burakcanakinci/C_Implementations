/* Problem 7 */
/* Write a function which performs binary search. The prototype of the function is: */
/* "unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)", where */
/* pArray is pointer to sorted array with ascending order of elements, uArraySize is number of elements in */
/* the array and uValue is the searched value. If the uValue is found, the function should return it index, */
/* otherwise 0xFFFF.  */

#include <stdio.h>

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue) {
    unsigned int low = 0;
    unsigned int high = uArraySize - 1;
    unsigned int iterations = 0; // Counter for iterations

    while (low <= high) {
        iterations++; // Increment with each loop iteration

        unsigned int mid = low + (high - low) / 2;

        if (pArray[mid] == uValue) {
            printf("Value found in %u iterations\n", iterations); 
            return mid; 
        } else if (pArray[mid] < uValue) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    printf("Value not found in %u iterations\n", iterations); 
    return 0xFFFF; 
}

int main() {
    unsigned int uArraySize, uValue;

    printf("Enter the size of the sorted array: ");
    scanf("%u", &uArraySize);

    int array[uArraySize];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < uArraySize; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the value to search: ");
    scanf("%u", &uValue);

    unsigned int result = BinSearch(array, uArraySize, uValue);

    if (result != 0xFFFF) {
        printf("Value found at index: %u\n", result);
    } else {
        printf("Value not found\n");
    }

    return 0;
}
