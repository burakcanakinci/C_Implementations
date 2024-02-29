/* Problem 1 */
/* Write C function which takes 16 bit number and should determine whether exactly one bit in this */
/* number is set. If one bit is set, the function should return "1" otherwise "0". The prototype of function is */
/* "unsigned char CheckBit(unsigned int uValue)". */
/* Example: */
/* Input = 0x0400, Output = 0x01 */
/* Input = 0x0600, Output = 0x00 */
/* Input = 0x0000, Output = 0x00  */

#include <stdio.h>
#include <stdbool.h>

unsigned char CheckBit(unsigned int uValue) {
    bool oneBitIsSet = (uValue != 0) && ! (uValue & (uValue - 1));
    return oneBitIsSet ? '1' : '0';
}

int main() {
    unsigned int uValue;

    printf("Enter a 16-bit unsigned integer: ");
    scanf("%u", &uValue);

    unsigned char result = CheckBit(uValue);
    printf("Result: %c\n", result);

    return 0;
}
