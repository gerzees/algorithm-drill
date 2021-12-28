#include <stdio.h>
enum
{
    MAX_N = 100
};
int main(void)
{
    int N;            //the number of cards
    int M;            //the number that we must not exeed
    int cards[MAX_N]; //numbers written on Mirko's cards
    int sum = 0;      //the largest possible sum not greater than M
    scanf("%d%d", &N, &M);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", cards + i);
    }
    for (size_t i = 0; i < N - 2; i++)
    {
        for (size_t j = i + 1; j < N - 1; j++)
        {
            for (size_t k = j + 1; k < N; k++)
            {
                int one_of_sum = cards[i] + cards[j] + cards[k];
                if (sum < one_of_sum && one_of_sum <= M)
                    sum = one_of_sum;
            }
        }
    }
    printf("%d", sum);
    return 0;
}