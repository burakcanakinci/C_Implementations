/* Write C function which takes 16 bit number and should determine whether exactly one bit in this */
/* number is set. If one bit is set, the function should return "1" otherwise "0". The prototype of function is */
/* "unsigned char CheckBit(unsigned int uValue)". */
/* Example: */
/* Input = 0x0400, Output = 0x01 */
/* Input = 0x0600, Output = 0x00 */
/* Input = 0x0000, Output = 0x00  */

#include <stdio.h>

unsigned char CheckBit(unsigned int uValue) {
    // Check if exactly one bit is set in the 16-bit number
    return (uValue != 0 && (uValue & (uValue - 1)) == 0) ? 0x01 : 0x00;
}

int main() {
    unsigned int input1 = 0x0400;
    unsigned int input2 = 0x0600;
    unsigned int input3 = 0x0000;

    printf("Input = 0x%04X, Output = 0x%02X\n", input1, CheckBit(input1));
    printf("Input = 0x%04X, Output = 0x%02X\n", input2, CheckBit(input2));
    printf("Input = 0x%04X, Output = 0x%02X\n", input3, CheckBit(input3));

    return 0;
}
