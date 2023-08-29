#include <stdio.h>
int main(void)
{
    int score, sum, i, cnt_test;
    char quiz_result;
    scanf("%d", &cnt_test);
    for (i = 0; i < cnt_test; ++i)
    {
        sum = 0;
        score = 0;
        quiz_result = '\0';
        while (!(quiz_result == 'O' || quiz_result == 'X'))
            scanf("%c", &quiz_result);
        for (; quiz_result == 'O' || quiz_result == 'X'; scanf("%c", &quiz_result))
        {
            if (quiz_result == 'O')
                sum += (++score);
            else
                score = 0;
        }
        printf("%d\n", sum);
    }

    return 0;
}