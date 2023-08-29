#include <stdio.h>

// last card = (N-2^k)*2, N/2<=2^k<N or N==2^k
// N        last card   power of 2  (binary)
// 1        1           1
// 10       10          10
// 11       10          10
// 100      100         100
// 101      10          100
// 110      100         100
// 111      110         100
// 1000     1000        1000
// 1001     10          1000
// 1010     100         1000
//  ...     ...         ...
int main(void)
{
    int N;
    int exponent = 0;
    int power_of_two = 1;
    scanf("%d", &N);
    for (; !(N <= power_of_two); ++exponent, power_of_two *= 2)
        ;
    if (N == power_of_two)
        printf("%d", N);
    else
    {
        printf("%d", 2 * N - power_of_two);
    }
    return 0;
}