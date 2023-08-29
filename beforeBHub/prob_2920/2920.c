#include <stdio.h>
#define SOUND_CNT 8
int sound[SOUND_CNT], i;

int main(void)
{
    scanf("%d%d%d%d%d%d%d%d", sound, sound + 1, sound + 2, sound + 3, sound + 4, sound + 5, sound + 6, sound + 7);
    for (i = 1; i < SOUND_CNT && sound[i - 1] > sound[i]; ++i)
        ;
    if (i == SOUND_CNT)
    {
        puts("descending");
        return 0;
    }
    for (i = 1; i < SOUND_CNT && sound[i - 1] < sound[i]; ++i)
        ;
    if (i == SOUND_CNT)
    {
        puts("ascending");
        return 0;
    }
    puts("mixed");
    return 0;
}