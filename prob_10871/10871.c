#include <stdio.h>
#include <string.h>

#define MAX_SEQ_LEN 10000
#define MAX_NUM_LEN 6

int N, X, A, i;
char NUM_STR[MAX_NUM_LEN];
char ANS[MAX_SEQ_LEN*MAX_NUM_LEN+1];

int main(void)
{
    scanf("%d%d",&N, &X);
    for(i=0; i<N; ++i){
        scanf("%d",&A);
        if(A<X){
            sprintf(NUM_STR,"%d ",A);
            strcat(ANS,NUM_STR);
        }
    }
    printf("%s",ANS);
    return 0;
}