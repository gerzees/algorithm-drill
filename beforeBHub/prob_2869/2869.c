#include <stdio.h>
int main(void)
{
    int A, B, V;
    // int height;
    int day;
    scanf("%d%d%d", &A, &B, &V);
    // for (day = 1, height = A; !(height >= V); ++day, height += A - B)
    //     ;
    day = 1;
    day += (V - A) / (A - B);
    day += (V - A) % (A - B) == 0 ? 0 : 1;
    printf("%d", day);
    return 0;
}