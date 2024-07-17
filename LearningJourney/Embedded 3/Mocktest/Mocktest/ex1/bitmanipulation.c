#include <stdio.h>
void printBinary(unsigned int num)
{
    unsigned int mask = 1 << 31;
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
    unsigned int X = 0b10101111001110000011101101010111;
    unsigned int r = X;
    printf("X = ");
    printBinary(X);
    unsigned int tmp = (X >> 0) & 0b111111;
    unsigned int tmp2 = 0b1010;
    tmp |= (tmp2 << 6);
    unsigned int tmp3 = (X >> 6) & 0xFFFFFF;
    tmp |= (tmp3 << 10);
    X = tmp;
    printf("X = ");
    printBinary(X);
}