#include <stdio.h>
enum
{
    CNT_MAX = 100,
    CNT_ALPHABET = 26// mistake: 24
};
int main(void)
{
    char S[CNT_MAX] = {
        '\0',
    };
    size_t position;
    int position_in_S[CNT_ALPHABET];
    size_t alphabet; // 0~25, 0==a, 1==b, ..., 25==z
    scanf("%s", S);
    for (alphabet = 0; alphabet < CNT_ALPHABET; alphabet++)
        position_in_S[alphabet] = -1;
    for (position = 0; position < CNT_MAX; position++)
    {
        alphabet = S[position] - 'a';
        if(alphabet<0)
            break;
        if (position_in_S[alphabet] == -1)
            position_in_S[alphabet] = position;
    }
    for (alphabet = 0; alphabet < CNT_ALPHABET; alphabet++)
        printf("%d ", position_in_S[alphabet]);

    return 0;
}