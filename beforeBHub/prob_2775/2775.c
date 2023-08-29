#include <stdio.h>

enum
{
    MAX_ROOM = 15,
    MAX_FLOOR = 15
};
int main(void)
{
    int room[MAX_FLOOR][MAX_ROOM] = {
        {
            0,
        },
    };
    int floor, room_num, cnt_test_case, resident_num;
    scanf("%d", &cnt_test_case);
    floor = 0;
    resident_num = 1;
    for (room_num = 1; room_num < MAX_ROOM; ++room_num)
    {
        room[floor][room_num] = resident_num++;
    }
    for (++floor; floor < MAX_FLOOR; floor++)
    {
        for (room_num = 1, resident_num = 0; room_num < MAX_ROOM; ++room_num)
        {
            resident_num += room[floor - 1][room_num];
            room[floor][room_num] = resident_num;
        }
    }

    for (; !(cnt_test_case == 0); cnt_test_case--)
    {
        scanf("%d%d", &floor, &room_num);
        printf("%d\n", room[floor][room_num]);
    }

    return 0;
}