#include <stdio.h>

int main(void)
{
    int title = 666;
    int N;
    scanf("%d", &N);
    while (--N)
    {
        while (++title)
        {
            int cnt = 0;
            for (int n = title; n != 0 && !(cnt == 3); n /= 10)
            {
                if (n % 10 == 6)
                    cnt++;
                else
                    cnt = 0;
            }
            if (cnt == 3)
                break;
        }
    }
    printf("%d", title);
    return 0;
}