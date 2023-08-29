#include <stdio.h>

int main(void)
{
    static char is_removed[1001] = {
        0,
    };
    int N, K;
    scanf("%d%d", &N, &K);
    printf("<");
    for (size_t i = 0, next = 0; i < N; i++)
    {
        int cnt = K;
        while (cnt != 0)
        {
            ++next;
            if (next > N)
                next -= N;
            if (is_removed[next])
                continue;
            --cnt;
        }
        is_removed[next] = 1;
        printf("%ld", next);
        if (i < N - 1)
            printf(", ");
    }
    printf(">");
    return 0;
}