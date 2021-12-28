#include <stdio.h>
#include <stdlib.h>
enum
{
    DIMENSION = 2,
    CNT_MAX = 100000
};
typedef struct _matrixNx1
{
    int entry[DIMENSION];
} MatrixNx1;
int cmpMatrixNx1(const void *arg1, const void *arg2)
{
    MatrixNx1 *mat1 = (MatrixNx1 *)arg1;
    MatrixNx1 *mat2 = (MatrixNx1 *)arg2;
    for (size_t i = 0; i < DIMENSION; i++)
    {
        if (mat1->entry[i] > mat2->entry[i])
            return 1;
        else if (mat1->entry[i] < mat2->entry[i])
            return -1;
        else
            continue;
    }
    return 0; //all entries are same: equivalent
}
int main(void)
{
    int N;
    static MatrixNx1 points[CNT_MAX];
    scanf("%d", &N);

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < DIMENSION; ++j)
            scanf("%d", &points[i].entry[j]);
    qsort(points, N, sizeof(MatrixNx1), cmpMatrixNx1);
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < DIMENSION; ++j)
            printf("%d ", points[i].entry[j]);
        printf("\n");
    }
    return 0;
}