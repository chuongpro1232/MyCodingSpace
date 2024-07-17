#include <stdio.h>
// Function to print out number in binary format
void printBinary(unsigned int num)
{
    unsigned int mask = 1 << 31; // start with the MSB bit
    printf("0b");
    while (mask > 0)
    {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}
int main()
{
    unsigned int X = 0b10101111001110010011010101010111; // Initial value of X
    printf(" X = ");
    printBinary(X);
    unsigned int r = X;                        // read data from X(the only once read)
    unsigned int tmp = (r >> 0) & 0b111111111; // store only bits 8-0 of X to tmp
    unsigned int tmp2 = 0b11010;               // store the data that we need to swap to tmp2
    unsigned int tmp3 = (r >> 14) & 0x3FFFF;   // store the remain of r(x) from 31-14 to tmp3
    tmp |= tmp3 << 9;                          // set tmp3 (the remain of r(X)) to bit 26-9 of tmp
    tmp |= tmp2 << 27;                         // set tmp2 (data need to put in) from bit 13-9
    X = tmp;                                   // set X=tmp(the only once set)
    printf(" X = ");
    printBinary(X);
    return 0;
}
