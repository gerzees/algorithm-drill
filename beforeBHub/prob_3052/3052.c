#include <stdio.h>
enum
{
    CNT = 10,
    DIVISOR = 42
};
int main(void)
{
    int is_remainder[DIVISOR] = {
        0,
    };
    int num[CNT];
    int count_remainder = 0;
    for (size_t i = 0; i < CNT; i++)
    {
        scanf("%d", &num[i]);
        ++is_remainder[num[i] % DIVISOR];
    }
    for (size_t i = 0; i < DIVISOR; i++)
    {
        if (is_remainder[i] != 0)
            count_remainder++;
    }
    printf("%d", count_remainder);

    return 0;
}