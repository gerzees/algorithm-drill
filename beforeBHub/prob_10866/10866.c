#include <stdio.h>
enum
{
    FALSE = 0,
    TRUE = 1
};
typedef struct _deque_int
{
    int *entity;
    int begin;
    int end;
    int size;
    const int max_size;
} Deque;
void push_front(Deque *pDeque, const int item)
{
    if (pDeque->size == pDeque->max_size)
        return;
    ++(pDeque->size);
    if (pDeque->begin == 0)
        pDeque->begin = pDeque->max_size;
    pDeque->entity[--(pDeque->begin)] = item;
}
void push_back(Deque *pDeque, const int item)
{
    if (pDeque->size == pDeque->max_size)
        return;
    ++(pDeque->size);
    if (pDeque->end == pDeque->max_size)
        pDeque->end = 0;
    pDeque->entity[(pDeque->end)++] = item;
}
int pop_front(Deque *pDeque)
{
    if (pDeque->size == 0)
        return -1;
    --(pDeque->size);
    if (pDeque->begin == pDeque->max_size)
        pDeque->begin = 0;
    return pDeque->entity[(pDeque->begin)++];
}
int pop_back(Deque *pDeque)
{
    if (pDeque->size == 0)
        return -1;
    --(pDeque->size);
    if (pDeque->end == 0)
        pDeque->end = pDeque->max_size;
    return pDeque->entity[--(pDeque->end)];
}
int size(const Deque *pDeque)
{
    return pDeque->size;
}
int empty(const Deque *pDeque)
{
    return pDeque->size == 0 ? TRUE : FALSE;
}
int front(const Deque *pDeque)
{

    if (pDeque->size == 0)
        return -1;
    return pDeque->entity[pDeque->begin == pDeque->max_size ? 0 : pDeque->begin];
}
int back(const Deque *pDeque)
{
    if (pDeque->size == 0)
        return -1;
    return pDeque->entity[(pDeque->end == 0 ? pDeque->max_size : pDeque->end) - 1];
}
void execute(const char *c_str, Deque *pDeque)
{
    if (c_str[1] == 'u' && c_str[5] == 'f') //push_front
    {
        int n;
        scanf("%d", &n);
        push_front(pDeque, n);
    }
    else if (c_str[1] == 'u' && c_str[5] == 'b') //push_back
    {
        int n;
        scanf("%d", &n);
        push_back(pDeque, n);
    }
    else if (c_str[1] == 'o' && c_str[4] == 'f') //pop_front
    {
        printf("%d\n", pop_front(pDeque));
    }
    else if (c_str[1] == 'o' && c_str[4] == 'b') //pop_back
    {
        printf("%d\n", pop_back(pDeque));
    }
    else if (c_str[0] == 's') //size
    {
        printf("%d\n", size(pDeque));
    }
    else if (c_str[0] == 'e') //empty
    {
        printf("%d\n", empty(pDeque));
    }
    else if (c_str[0] == 'f') //front
    {
        printf("%d\n", front(pDeque));
    }
    else if (c_str[0] == 'b') //back
    {
        printf("%d\n", back(pDeque));
    }
}
int main(void)
{
    static int entitis[10000];
    static Deque deque = {entitis, 0, 0, 0, sizeof(entitis) / sizeof(int)};
    char command_str[20];
    int N;
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", command_str);
        execute(command_str, &deque);
    }
    return 0;
}