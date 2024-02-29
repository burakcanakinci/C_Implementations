/* Write C function which takes signed 16 bit number (int) and convert it into ASCII null terminated */
/* string. Function prototype is "void Conv(int sValue, char *pBuffer)", where pBuffer is pointer to string */
/* buffer. Format of the string should be "-DDDDD", if the number is positive the first character is space. */
/* The string should not contain leading zeroes. */
/* Example: */
/* "-   26" */
/* " 16025"  */

#include <stdio.h>

void Conv(int sValue, char *pBuffer) {
    if (sValue < 0) {
        sprintf(pBuffer, "-%5d", -sValue);
    } else {
        sprintf(pBuffer, " %5d", sValue);
    }
}

int main() {
    char buffer1[8];  // Adjust the size as needed
    char buffer2[8];  // Adjust the size as needed

    Conv(-26, buffer1);
    Conv(16025, buffer2);

    printf("\"%s\"\n", buffer1);
    printf("\"%s\"\n", buffer2);

    return 0;
}
