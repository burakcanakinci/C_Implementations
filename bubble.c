/* Problem 6 */
/* Write a function, which performs bubble sort. The prototype of the function is "void Bubble(int* pArray, */
/* unsigned int uLen)”, where pArary is a pointer to unsorted array and uLen is its size.  */

#include <stdio.h>
#include <stdbool.h>
void Bubble(int* pArray, unsigned int uLen) {
    int i, j;
    bool swapped;

    for (i = 0; i < uLen - 1; i++) {
        swapped = false;
        printf("Swapped false\n");
        for (j = 0; j < uLen - i - 1; j++) {
            if (pArray[j] > pArray[j + 1]) {
                int temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
                printf("Swapped true\n");
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    unsigned int uLen;
    printf("Enter the size of the array: ");
    scanf("%u", &uLen);

    int array[uLen];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < uLen; i++) {
        scanf("%d", &array[i]);
    }

    printf("\nUnsorted Array:\n");
    for (int i = 0; i < uLen; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    Bubble(array, uLen);
    printf("\nSorted Array:\n");
    for (int i = 0; i < uLen; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 0;
}
