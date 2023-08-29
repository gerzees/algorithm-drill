#include <stdio.h>
//Parenthesis String, PS
// Valid PS, VPS
// '(' is -1, ')' is 1,
// accumulate
//   if positive == wrong, if negetive at end == wrong
enum
{
    LEN_MAX = 50
};
int main(void)
{
    int T; // the number of test cases
    char string[LEN_MAX];
    scanf("%d", &T);
    for (size_t i = 0; i < T; i++)
    {
        scanf("%s", string);
        int not_valid = 0; //0 means valid PS
        char *parenthesis = string;
        for (; *parenthesis != '\0' && not_valid <= 0; ++parenthesis)
        {
            if (*parenthesis == '(')
                --not_valid;
            else
                ++not_valid;
        }
        if (!not_valid)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}