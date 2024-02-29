/* Write a C function which takes as input 8x8 pixels image and returns a vertical mirror of the image. */
/* Image is monochrome - each pixel is coded as one bit and each byte represents one image row. */
/* The prototype of the function is: "void VMirror(unsigned char *pImage)". */
/* Example: */
/* initial content of buffer : 0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00 */
/* after VMirror execution : 0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00  */

#include <stdio.h>
void VMirror(unsigned char *pImage) {
    // Reverse the order of the rows
    
    for (int i = 0; i < 4; i++) {
        unsigned char temp = pImage[i];
        pImage[i] = pImage[7 - i];
        pImage[7 - i] = temp;
    }

    // Reverse the bits within each row
    for (int i = 0; i < 8; i++) {
        pImage[i] = (pImage[i] >> 4) | (pImage[i] << 4);
        pImage[i] = ((pImage[i] & 0xCC) >> 2) | ((pImage[i] & 0x33) << 2);
        pImage[i] = ((pImage[i] & 0xAA) >> 1) | ((pImage[i] & 0x55) << 1);
    }
}

int main() {
    unsigned char image[] = {0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00};
    
    printf("Original image:\n");
    for (int i = 0; i < 8; i++) {
        printf("%02X", image[i]);
    }
    printf("\n");

    VMirror(image);

    printf("Vertically mirrored image:\n");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", image[i]);
    }
    printf("\n");

    return 0;
}
