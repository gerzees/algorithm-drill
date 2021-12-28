#include <stdio.h>
#include <stdlib.h>
enum
{
    CNT_MAX = 1000000
};
int cmp_int(const void *arg1, const void *arg2)
{
    int num1 = *(const int *)arg1;
    int num2 = *(const int *)arg2;
    if (num1 > num2)
        return 1;
    if (num1 == num2)
        return 0;
    if (num1 < num2)
        return -1;
}
int main(void)
{
    int N, num[CNT_MAX];
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", num + i);
    }
    qsort(num, N, sizeof(int), cmp_int);
    for (size_t i = 0; i < N; i++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
}