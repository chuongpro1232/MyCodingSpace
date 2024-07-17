#include <stdio.h>
void printBinary(unsigned int num)
{
    unsigned int mask = 1 << 31; // why we need this
    // why using "="
    printf("0b");
    while (mask > 0)
    {
        printf("%d", (num & mask) ? 1 : 0); // the mechanism of compare?
        mask >>= 1;                         // why using "="
    }
    printf("\n");
}

int main()
{
    unsigned int X = 0b111001100;
    unsigned int r = X;
    printf("X = ");
    printBinary(X);
    // swapping
    unsigned int tmp = (r >> 4) & 0b1111;   // store bits 7-4 of X to tmp
    unsigned int tmp2 = (r >> 10) & 0b1111; // store bits 13-10 of X to tmp2
    r &= ~((0b1111 << 4) | (0b1111 << 10));
    r |= ((tmp << 10) | (tmp2 << 4));
    X = r;
    printf("X = ");
    printBinary(X);
}