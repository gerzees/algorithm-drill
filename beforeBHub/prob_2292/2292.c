#include <stdio.h>

//1 6 12(6*2) 18(6*3) ...
//1 2 3       4
enum
{
    POLYGON = 6
};

int main(void)
{
    int distance = 1;
    int area = 1;
    int N;
    scanf("%d", &N);
    while (N>area)
    {
        area += POLYGON*distance++;
    }
    printf("%d", distance);
        return 0;
}