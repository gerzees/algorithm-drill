#include <stdio.h>

int main(void)
{
    int dividend, divisor, quotient, remainder, count;

    scanf("%d", &dividend);
    scanf("%d", &divisor);
    count = 0;
    do{
        quotient = dividend/divisor;
        remainder = dividend%divisor;
        printf("%d", quotient);
        if(count==0 && remainder!=0)
            printf(".");

        count++;
        dividend = remainder*10;    
    }while(count<20 && remainder!=0);
    
    return 0;
}