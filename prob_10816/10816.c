// Fail: timeover
#include <stdio.h>
#include <stdlib.h>

enum
{
    MAX_CNT = 500000
};
int compare_int(const void *arg1, const void *arg2)
{
    const int i1 = *(const int *)arg1;
    const int i2 = *(const int *)arg2;
    return (i1 > i2) - (i1 < i2);
}
int search_position(const int target, const int *sorted_arr, const int begin, const int end)
{
    int center = (begin + end) / 2;
    if (end - begin < 1)
        return -1; //no element: not found target
    if (sorted_arr[center] < target)
        return search_position(target, sorted_arr, center + 1, end);
    else if (target < sorted_arr[center])
        return search_position(target, sorted_arr, begin, center);
    else //target found
        return center;
}
int count_int(const int target, const int *sorted_arr, const int arr_len)
{
    int cnt = 0;
    int pos = search_position(target, sorted_arr, 0, arr_len);
    if (pos < 0)
        return cnt;
    ++cnt; //at least, there is one card

    for (size_t i = pos - 1; 0 <= i && !(target != sorted_arr[i]); --i, ++cnt)
        ; //check left side from pos
    for (size_t i = pos + 1; i < arr_len && !(target != sorted_arr[i]); ++i, ++cnt)
        ; //check right side from pos
    return cnt;
}
int main(void)
{
    int N, M;
    // static int cards[MAX_CNT];
    scanf("%d", &N);
    int cards[N];
    for (size_t i = 0; i < N; i++)
        scanf("%d", &cards[i]);
    qsort(cards, N, sizeof(int), compare_int);
    scanf("%d", &M);
    for (size_t i = 0; i < M; i++)
    {
        int target;
        scanf("%d", &target);
        printf("%d ", count_int(target, cards, N));
    }
    return 0;
}