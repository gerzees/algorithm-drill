#include <stdio.h>

int main(void)
{

    int scores[1000];
    int count_subject, i, max_score, sum;
    int dividend, divisor, quotient, remainder;
    const int scaler=10000;
    max_score=0;
    sum=0;
    scanf("%d",&count_subject);
    for(i=0; i<count_subject; ++i){
        scanf("%d", &scores[i]);
        //look for max_score
        if(max_score<scores[i])
            max_score=scores[i];
    }
        
    // new_score=score/max_score*100
    // need *10000 for small error
    for(i=0; i<count_subject; ++i){
        sum+=scores[i]*scaler*100/max_score;
    }
    quotient=sum/(count_subject*scaler);
    remainder=sum%(count_subject*scaler);
    printf("%d",quotient);
    if(remainder==0)
        return 0;
    else
        printf(".");
    for(i=0; i<4; ++i){
        quotient=remainder*10/(count_subject*scaler);
        remainder=remainder*10%(count_subject*scaler);
        printf("%d",quotient);
        if(remainder==0)
            return 0;
    }
    return 0;
}