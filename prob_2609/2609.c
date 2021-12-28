#include <stdio.h>

int main(void)
{
    int GCD = 1, LCM = 1;
    int a, b, i = 0, done = 0;
    int prime[10000] = {2};
    scanf("%d%d", &a, &b);
    while (!done)
    {
        while (a != 1 && b != 1 && a % prime[i] == 0 && b % prime[i] == 0)
        {
            GCD *= prime[i];
            LCM *= prime[i];
            a /= prime[i];
            b /= prime[i];
        }
        while (a != 1 && a % prime[i] == 0)
        {
            LCM *= prime[i];
            a /= prime[i];
        }
        while (b != 1 && b % prime[i] == 0)
        {
            LCM *= prime[i];
            b /= prime[i];
        }
        if (a == 1 && b == 1)
        {
            done = 1;
            continue;
        }
        int next_prime = prime[i] + 1;
        int prime_found = 1;
        while (!prime_found)
        {
            int j;
            for (int j = 0; j <= i && !(next_prime % prime[j] == 0); ++j)
                ;
            if (j <= i)
                ++next_prime;
            else
                prime_found = 1;
        }
        prime[++i] = next_prime;
    }
    printf("%d\n%d", GCD, LCM);

    return 0;
}