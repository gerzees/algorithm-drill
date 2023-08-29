#include <stdio.h>
enum
{
    BASE = 10
};
int main(void)
{
    int A, B, C, num, i;
    int num_count[BASE] = {
        0,
    };
    long long AxBxC;
    scanf("%d%d%d", &A, &B, &C);
    AxBxC = A * B * C;
    do
    {
        num = AxBxC % BASE;
        ++num_count[num];
        AxBxC /= BASE;
    } while (!AxBxC == 0);

    for (i = 0; i < BASE; ++i)
        printf("%d\n", num_count[i]);
    return 0;
}