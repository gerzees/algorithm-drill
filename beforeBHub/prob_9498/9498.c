#include <stdio.h>

int main(void)
{
    int score;
    scanf("%d", &score);
    if(score-89>0)
        printf("A");
    else if(score-79>0)
        printf("B");
    else if(score-69>0)
        printf("C");
    else if (score-59>0)
        printf("D");
    else
        printf("F");

    return 0;
}