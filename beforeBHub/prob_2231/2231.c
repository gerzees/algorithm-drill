#include <stdio.h>
int get_digit_sum(int number)
{
    int digit_sum = number;
    while (number != 0)
    {
        digit_sum += number % 10;
        number /= 10;
    }
    return digit_sum;
}
int get_digit(int number)
{
    int digit = 0;
    for (; number != 0; number /= 10)
        ++digit;
    return digit;
}

int main(void)
{
    int N;

    int generator = 0;
    int i;

    scanf("%d", &N);
    i = N - get_digit(N) * 9;
    if (i < 0)
        i = 0;
    for (; i < N && !(get_digit_sum(i) == N); i++)
        ;
    if (i < N)
        generator = i;
   
    printf("%d\n", generator);
    return 0;
}