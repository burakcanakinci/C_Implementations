/* Write a C function which takes as input 8x8 pixels image and returns a vertical mirror of the image. */
/* Image is monochrome - each pixel is coded as one bit and each byte represents one image row. */
/* The prototype of the function is: "void VMirror(unsigned char *pImage)". */
/* Example: */
/* initial content of buffer : 0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00 */
/* after VMirror execution : 0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00  */

#include <stdio.h>

void VMirror(unsigned char *pImage) {
    for (int i = 0; i < 8; ++i) {
        unsigned char row = pImage[i];
        unsigned char mirroredRow = 0;

        for (int j = 0; j < 8; ++j) {
            mirroredRow |= ((row >> j) & 0x01) << (7 - j);
        }

        pImage[i] = mirroredRow;
    }
}

int main() {
    unsigned char image[] = {0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00};

    printf("Initial Content: ");
    for (int i = 0; i < 8; ++i) {
        printf("0x%02X ", image[i]);
    }

    VMirror(image);

    printf("\nAfter VMirror Execution: ");
    for (int i = 0; i < 8; ++i) {
        printf("0x%02X ", image[i]);
    }

    return 0;
}
