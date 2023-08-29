#include <stdio.h>

int main(void)
{
    int i;
    char A[3], B[3], *answer;
    scanf("%s%s", A, B);
    for (i = 2; i >= 0 && !(A[i] != B[i]); --i)
        ;
    if (A[i]<B[i])
        answer = B;
    else
        answer = A;
    printf("%c%c%c", answer[2], answer[1], answer[0]);

    return 0;
}