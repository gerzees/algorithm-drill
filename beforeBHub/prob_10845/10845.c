#include <stdio.h>
#include <string.h>
enum
{
    NO_ITEM = -1,
    FALSE = 0,
    TRUE = 1,
    MAX_COMMAND_LEN = 6,
    KIND_COMMAND = 6,
    MAX_SIZE = 10000
};
typedef enum _command
{
    PUSH = 0,
    POP = 1,
    SIZE = 2,
    EMPTY = 3,
    FRONT = 4,
    BACK = 5
} Command;
typedef struct _queue_int
{
    int *entity;
    int begin;
    int end;
    int empty;
    const int max_size;
} Queue_int;
void push(Queue_int *pQueue, const int item)
{
    if (pQueue->empty)
        pQueue->empty = FALSE;
    else if (pQueue->begin == pQueue->end)
        return; // queue is full
    pQueue->entity[(pQueue->end)++] = item;
    if (pQueue->end == pQueue->max_size)
        pQueue->end = 0;
}
int pop(Queue_int *pQueue)
{
    if (pQueue->empty)
        return NO_ITEM;
    const int popped = pQueue->entity[(pQueue->begin)++];
    if (pQueue->begin == pQueue->max_size)
        pQueue->begin = 0;
    if (pQueue->begin == pQueue->end)
        pQueue->empty = TRUE;
    return popped;
}
int size(const Queue_int *pQueue)
{
    if (pQueue->empty)
        return 0;
    else if (pQueue->end < pQueue->begin)
        return pQueue->end + pQueue->max_size - pQueue->begin;
    else
        return pQueue->end - pQueue->begin;
}
int empty(const Queue_int *pQueue)
{
    return pQueue->empty;
}
int front(const Queue_int *pQueue)
{
    if (pQueue->empty)
        return NO_ITEM;
    return pQueue->entity[pQueue->begin];
}
int back(const Queue_int *pQueue)
{
    if (pQueue->empty)
        return NO_ITEM;
    int last = pQueue->end == 0 ? pQueue->max_size - 1 : pQueue->end - 1;
    return pQueue->entity[last];
}
int main(void)
{
    static int e[MAX_SIZE];
    static char PUSH_STR[] = "push";
    static char POP_STR[] = "pop";
    static char SIZE_STR[] = "size";
    static char EMPTY_STR[] = "empty";
    static char FRONT_STR[] = "front";
    static char BACK_STR[] = "back";
    static char *COMMAND_STR[KIND_COMMAND] = {PUSH_STR, POP_STR, SIZE_STR, EMPTY_STR, FRONT_STR, BACK_STR};
    Queue_int queue = {e, 0, 0, TRUE, MAX_SIZE};
    char c_string[MAX_COMMAND_LEN];
    int N;
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", c_string);
        int c_num;
        for (c_num = 0; !(strcmp(COMMAND_STR[c_num], c_string) == 0); ++c_num)
            ;
        switch ((Command)c_num)
        {
        case PUSH:
        {
            int n;
            scanf("%d", &n);
            push(&queue, n);
        }
        break;
        case POP:
            printf("%d\n", pop(&queue));
            break;
        case SIZE:
            printf("%d\n", size(&queue));
            break;
        case EMPTY:
            printf("%d\n", empty(&queue));
            break;
        case FRONT:
            printf("%d\n", front(&queue));
            break;
        case BACK:
            printf("%d\n", back(&queue));
            break;
        default:
            break;
        }
    }
    return 0;
}