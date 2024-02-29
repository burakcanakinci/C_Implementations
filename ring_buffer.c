/* Realize queue from integers with array (ring buffer). Push and Pop function should be realized, e.g.: */
/* int arr[ MAX_SIZE ]; */
/* int top = 0; */
/* int bottom = 0; */
/* int IsEmpty() - functions returns 0 if queue is empty and > 0 if not */
/* int IsFull() - function return 0 if the queue is full and new element cannot be added, otherwise > 0 */
/* void Push(int nNewValue) - Functions adds new element to the queue. We assume, that previously */
/* “IsFull()” was called to check whether is possible to insert element, i.e. it is always possible to insert */
/* element */
/* int Pop() - retrieve an element from the queue. We assume that the queue is not empty.  */

#include <linux/limits.h>
#include <stdio.h>
#define MAX_SIZE 30

int arr[MAX_SIZE];
int top = 0;
int bottom = 0;

int IsEmpty() {
    return top == bottom;
}

int IsFull() {
    return (top + 1) % MAX_SIZE == bottom;
}

void Push(int nNewValue) {
    arr[top] = nNewValue;
    top = (top + 1) % MAX_SIZE;
}

int Pop() {
    int value = arr[bottom];
    bottom = (bottom + 1) % MAX_SIZE;
    return value;
}

int main() {
    Push(10);
    Push(20);
    Push(30);

    while (!IsEmpty()) {
        int value = Pop();
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
