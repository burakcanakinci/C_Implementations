/* Write a function, which performs bubble sort. The prototype of the function is "void Bubble(int* pArray, */
/* unsigned int uLen)”, where pArary is a pointer to unsorted array and uLen is its size.  */

#include <stdio.h>
#include <stdbool.h>

void Bubble(int* pArray, unsigned int uLen) {
    unsigned int i = 0;
    bool swapped;
    do {
        swapped = false;
        for (unsigned int j = 0; j < uLen - i - 1; ++j) {
            if (pArray[j] > pArray[j + 1]) {
                int temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
                swapped = true;
            }
        }
        i++;
    } while(swapped);
}

int main() {

    unsigned int arraySize;
    printf("Enter the size of the array: ");
    scanf("%u", &arraySize);

    int unsortedArray[arraySize];

    printf("Enter %u elements of the array:\n", arraySize);
    for (unsigned int i = 0; i < arraySize; ++i) {
        scanf("%d", &unsortedArray[i]);
    }

    printf("Unsorted Array: ");
    for (unsigned int i = 0; i < arraySize; ++i) {
        printf("%d ", unsortedArray[i]);
    }

    Bubble(unsortedArray, arraySize);

    printf("\nSorted Array: ");
    for (unsigned int i = 0; i < arraySize; ++i) {
        printf("%d ", unsortedArray[i]);
    }
    printf("\n");

    return 0;
}
