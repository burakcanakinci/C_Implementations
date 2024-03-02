/* Realize function that reverses null terminated string. The prototype of the function is "void */
/* Reverse(char* ptr);”. Do not use standard library functions. */
/* Example: If e.g. “This is a test\0” is passed to the function, the function must produce “tset a si sihT\0”  */

#include <stdio.h>
void Reverse(char* ptr) {
    if (ptr == NULL || *ptr == '\0') return;

    int start = 0, end = 0;
    
    // Find the end of the string (null terminator)
    while (ptr[end] != '\0') {
        end++;
    }
    end--; // Move back to the last character before null terminator

    // Swap characters from the beginning and end until pointers meet or cross
    while (start < end) {
        char temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;

        start++;
        end--;
    }
}

int main () {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin); // fgets to handle potential spaces

    Reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
