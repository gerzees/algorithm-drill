#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char numbers[10000000];
int main(void)
{
    int count, input, max, min;
    char *pch;

    // runtime error: NeverBeNull
    // ??why
    // fgets(numbers,8,stdin);
    // count=atoi(numbers);
    scanf("%d", &count);
    getchar();
    fgets(numbers, 10000000, stdin);

    pch = strtok(numbers, " \n");
    input = atoi(pch);
    max = input;
    min = input;
    --count;

    while (count > 0)
    {
        pch = strtok(NULL, " \n");
        input = atoi(pch);
        --count;
        if (input > max)
            max = input;
        if (input < min)
            min = input;
    }

    printf("%d %d", min, max);
    return 0;
}