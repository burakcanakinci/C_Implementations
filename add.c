/* Write a function, which performs addition of positive numbers, represented as strings. The result is */
/* stored into a buffer, passed as parameter to the function. We assume that the result buffer is always big */
/* enough. The prototype of the function is "void Add(const char* p1, const char* p2, char* result);” */
/* Example: */
/* if the function is called as follows: Add( “12345”, “678”, result) , the content of “result” must be */
/* “13023” or " 13023".  */

#include <stdio.h>
#include <string.h>

void Add(const char* p1, const char* p2, char* result) {
    int len1 = strlen(p1);
    int len2 = strlen(p2);
    int carry = 0;
    int resultIndex = 0;

    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int digit1 = (i >= 0) ? p1[i] - '0' : 0;
        int digit2 = (j >= 0) ? p2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        result[resultIndex++] = (sum % 10) + '0';
    }

    result[resultIndex] = '\0';

    // Reverse the result string
    int start = 0, end = resultIndex - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        ++start;
        --end;
    }
}

int main() {
    const char* num1 = "12345";
    const char* num2 = "678";
    char result[10];  // Adjust the size as needed

    Add(num1, num2, result);

    printf("Result: %s\n", result);

    return 0;
}
