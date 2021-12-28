#include <stdio.h>
enum
{
    LEN_NUM = 5
};
int main(void)
{
    char num_str[LEN_NUM] = {
        '\0',
    };
    char *room_num;
    int cnt_test_cases;
    int H, W, N, xx, yy;
    scanf("%d", &cnt_test_cases);
    for (size_t i = 0; i < cnt_test_cases; i++)
    {
        scanf("%d%d%d", &H, &W, &N);
        xx = 1 + (N - 1) / H;
        yy = 1 + (N - 1) % H;
        num_str[0] = '0' + yy / 10;
        num_str[1] = '0' + yy % 10;
        num_str[2] = '0' + xx / 10;
        num_str[3] = '0' + xx % 10;
        num_str[4] = '\0';
        if (num_str[0]=='0')//yxx
            room_num = num_str + 1;
        else//yyxx
            room_num = num_str;
        printf("%s\n", room_num);
    }

    return 0;
}