#include <stdio.h>
#include <stdlib.h>
//sort->binary search
enum
{
    CNT_MAX = 100000
};
int compare_int(const void *arg1, const void *arg2)
{
    int i1 = *(int *)arg1;
    int i2 = *(int *)arg2;
    if (i1 > i2)
        return 1;
    else if (i1 < i2)
        return -1;
    else
        return 0;
}
int search_int(const int *arr, const int arr_len, const int target)
{
    if (target < arr[0] || arr[arr_len - 1] < target) // out of range
        return 0;
    if (arr_len == 0) // no entry left
        return 0;
    const int *center_entry = arr + arr_len / 2;
    const int len_left_half = arr_len / 2;
    const int *right_half = center_entry + 1;
    const int len_right_half = arr_len - (arr_len / 2 + 1);
    if (target < *center_entry)
        return search_int(arr, len_left_half, target);
    else if (*center_entry < target)
        return search_int(right_half, len_right_half, target);
    else //(*center_entry==target)
        return 1;
}
int main(void)
{
    int N;
    int M;
    int target;
    int A[CNT_MAX];
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
        scanf("%d", &A[i]);
    qsort(A, N, sizeof(int), compare_int);
    scanf("%d", &M);
    for (size_t i = 0; i < M; i++)
    {
        scanf("%d", &target);
        printf("%d\n", search_int(A, N, target));
    }

    return 0;
}