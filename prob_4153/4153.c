#include <stdio.h>
enum
{
    CNT_SIDE = 3
};
int main(void)
{
    int temp;
    int side_square[CNT_SIDE];
    int done = 0;
    while (!done)
    {
        for (size_t i = 0; i < CNT_SIDE; i++)
        {
            scanf("%d", &temp);
            side_square[i] = temp * temp;
        }
        if (side_square[1] == 0 && side_square[2] == 0 && side_square[0] == 0)
        {
            done = 1;
            continue;
        }
        if (side_square[1] > side_square[2] && side_square[1] > side_square[0])
        {
            temp = side_square[0];
            side_square[0] = side_square[1];
            side_square[1] = temp;
        }
        else if (side_square[2] > side_square[1] && side_square[2] > side_square[0])
        {
            temp = side_square[0];
            side_square[0] = side_square[2];
            side_square[2] = temp;
        }

        if (side_square[0] == side_square[1] + side_square[2])
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}