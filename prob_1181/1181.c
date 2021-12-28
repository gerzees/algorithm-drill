#include <stdio.h>
#include <stdlib.h>
enum
{
    MAX_LEN = 50,
    MAX_CNT = 20000
};
//w1 - w2
int compare_word(const void *arg1, const void *arg2)
{
    const char *w1 = *(const char **)arg1;
    const char *w2 = *(const char **)arg2;
    int len1, len2;
    for (len1 = 0; w1[len1] != '\0'; ++len1)
        ;
    for (len2 = 0; w2[len2] != '\0'; ++len2)
        ;
    if (len1 == len2)
    {
        int i;
        for (i = 0; i < len1 && w1[i] == w2[i]; ++i)
            ;
        if (i < len1)
            return w1[i] - w2[i];
    }
    return len1 - len2;
}
int main(void)
{
    char word[MAX_CNT][MAX_LEN + 1];
    char *ordered_word[MAX_CNT];
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i)
    {
        scanf("%s", word[i]);
        ordered_word[i] = word[i];
    }
    qsort(ordered_word, cnt, sizeof(char *), compare_word);
    // printf("\n");
    printf("%s\n", ordered_word[0]);
    for (int i = 1; i < cnt; i++)
    {
        if (compare_word(ordered_word + i - 1, ordered_word + i) != 0)
            printf("%s\n", ordered_word[i]);
    }

    return 0;
}