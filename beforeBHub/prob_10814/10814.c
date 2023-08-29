#include <stdio.h>
#include <stdlib.h>
enum
{
    MAX_LEN = 100,
    MAX_CNT = 100000
};
struct member
{
    int id;
    int age;
    char name[MAX_LEN + 1];
};
int cmp_member(const void *arg1, const void *arg2)
{
    struct member *mem1 = (struct member *)arg1;
    struct member *mem2 = (struct member *)arg2;
    if (mem1->age > mem2->age)
        return 1;
    else if (mem1->age < mem2->age)
        return -1;
    else if (mem1->id > mem2->id)
        return 1;
    else if (mem1->id < mem2->id)
        return -1;
    else
        return 0; // ids can not have the same value
}
// struct member member_table[MAX_CNT];//no seg fault occur
int main(void)
{
    //struct member member_table[MAX_CNT];//seg fault; stack size limited?
    static struct member member_table[MAX_CNT];
    int N;
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        member_table[i].id = i;
        scanf("%d%s", &member_table[i].age, member_table[i].name);
    }
    qsort(member_table, N, sizeof(struct member), cmp_member);
    for (size_t i = 0; i < N; i++)
    {
        printf("%d %s\n", member_table[i].age, member_table[i].name);
    }
    return 0;
}