#include <stdio.h>

int main(void)
{
    int N, K, dividend, divisor;
    scanf("%d%d", &N, &K);
    // N!/(k!*(N-K)!)
    // N N-1 N-2 ... N-(K-1)
    // k k-1 k-2 ..  k-(k-1)
    dividend = divisor = 1;
    for (size_t i = 0; i < K; i++)
    {
        dividend *= N - i;
        divisor *= K - i;
    }
    printf("%d", dividend / divisor);
    return 0;
}