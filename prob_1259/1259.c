#include <stdio.h>
enum
{
    MAX_LEN = 5,
    TRUE = 1,
    BASE = 10
};
int main(void)
{
    int num;
    int digit[MAX_LEN];
    int done = 0;
    size_t i, a, b;
    while (!done)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            done = TRUE;
            continue;
        }
        for (i = 0; i < MAX_LEN && !(num == 0); ++i)
        {
            digit[i] = num % BASE;
            num /= BASE;
        }
        for (a = 0, b = i - 1; a < b && digit[a] == digit[b]; ++a, --b)
            ;
        if (a < b)
            printf("no\n");
        else
            printf("yes\n");
    }

    return 0;
}