#include <stdio.h>
#define CNT 9

int num, max_num, order_max_num, i;
int main(void)
{
    max_num = 0;

    for (i = 1; i <= CNT; ++i)
    {
        scanf("%d", &num);
        if (max_num < num)
        {
            max_num = num;
            order_max_num = i;
        }
    }
    printf("%d\n%d", max_num, order_max_num);
    return 0;
}