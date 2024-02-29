/* Write C function which takes signed 16 bit number (int) and convert it into ASCII null terminated */
/* string. Function prototype is "void Conv(int sValue, char *pBuffer)", where pBuffer is pointer to string */
/* buffer. Format of the string should be "-DDDDD", if the number is positive the first character is space. */
/* The string should not contain leading zeroes. */
/* Example: */
/* "- 26" */
/* " 16025"  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Conv(int sValue, char *pBuffer) {
    bool isNegative = sValue < 0;
    int absValue = abs(sValue);

    int i = 5;
    pBuffer[6] = '\0';

    if(absValue == 0) {
        pBuffer[i--] = '0';
    }

    while (absValue > 0) {
        pBuffer[i--] = (absValue % 10) + '0';
        absValue /= 10;
    }

    // Shift digits if necessary (to accomodate the extra space)
    if (!isNegative) {
        for (int j = 5; j > 0; j--) {
            pBuffer[j] = pBuffer[j - 1];
        }
    }
    pBuffer[0] = isNegative ? '-' : ' ';
}

int main() {
    int number;
    char buffer[7]; // Allocate enough space for the string "-DDDDD\0"

    printf("Enter a signed 16-bit integer: ");
    while (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a number: ");
        scanf("%*[^\n]"); // Clear invalid input from the buffer
    }

    Conv(number, buffer);
    printf("Converted string: %s\n", buffer);
}

