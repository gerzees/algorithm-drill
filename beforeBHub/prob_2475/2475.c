#include <stdio.h>

int main(void)
{
    int num, squared_sum, i;
    const int COUNT=5;
    squared_sum=0;
    for(i=0; i<COUNT; ++i){
        scanf("%d", &num);
        squared_sum+=num*num;
    }
    printf("%d", squared_sum%10);
    return 0;
}