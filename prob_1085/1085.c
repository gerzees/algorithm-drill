#include <stdio.h>
enum
{
    DIST_MAX = 1000,
    CNT_DIRECTION = 4
};
int main(void)
{
    int w, h;
    int distance[4]; //[0]:x,[1]:y,[2]:w-x,[3],h-y
    int min_dist = DIST_MAX;
    scanf("%d%d%d%d", distance, distance + 1, &w, &h);
    distance[2] = w - distance[0];
    distance[3] = h - distance[1];
    for (size_t i = 0; i < CNT_DIRECTION; i++)
    {
        if (min_dist > distance[i])
            min_dist = distance[i];
    }
    printf("%d", min_dist);

    return 0;
}