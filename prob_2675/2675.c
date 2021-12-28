#include <stdio.h>
#include <string.h>
#define S_MAX_LEN 21
#define R_MAX 8
#define T_MAX 1000
char S[S_MAX_LEN];                 //string
int S_LEN;                         //the length of string
char P[T_MAX * S_MAX_LEN * R_MAX]; //string made by repeating S
int R;                             //the number of repeating
int T;                             //the number of test cases
int i, j, k, l;

int main(void)
{
    scanf("%d", &T);
    l = 0;
    for (i = 0; i < T; ++i)
    {
        scanf("%d", &R);
        scanf("%s", S);
        S_LEN = strlen(S);
        for (j = 0; j < S_LEN; ++j)
        {
            for (k = 0; k < R; ++k)
                P[l++] = S[j];
        }
        P[l++] = '\n';
    }
    P[l] = '\0';
    printf("%s", P);
    return 0;
}