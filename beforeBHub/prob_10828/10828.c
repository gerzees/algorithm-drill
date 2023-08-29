#include <stdio.h>
#include <string.h>
enum
{
    CNT_MAX = 10000,
    LEN_MAX = 6,
    KIND_COMMAND = 5,
    NO_ITEM = -1,
    TRUE = 1,
    FALSE = 0
};
typedef enum _command
{
    PUSH = 0,
    POP = 1,
    SIZE = 2,
    EMPTY = 3,
    TOP = 4
} Command;
char PUSH_STR[] = "push";
char POP_STR[] = "pop";
char SIZE_STR[] = "size";
char EMPTY_STR[] = "empty";
char TOP_STR[] = "top";
char *COMMAND_STR[KIND_COMMAND] = {PUSH_STR, POP_STR, SIZE_STR, EMPTY_STR, TOP_STR};
typedef struct _stack_int
{
    int *entity;
    int size;
    int empty;
} Stack_int;
void push(Stack_int *pStack, const int item)
{
    if (pStack->empty)
        pStack->empty = FALSE;
    pStack->entity[(pStack->size)++] = item;
}
int pop(Stack_int *pStack)
{
    if (pStack->empty)
        return NO_ITEM;
    if (--(pStack->size) == 0)
        pStack->empty = TRUE;
    return pStack->entity[pStack->size];
}
int size(const Stack_int *pStack)
{
    return pStack->size;
}
int empty(const Stack_int *pStack)
{
    return pStack->empty;
}
int top(const Stack_int *pStack)
{
    if (pStack->empty)
        return NO_ITEM;
    return pStack->entity[pStack->size - 1];
}
int main(void)
{
    static int stack_entity[CNT_MAX];
    Stack_int stack = {stack_entity, 0, TRUE};
    int N;
    char command_str[LEN_MAX];
    int num;
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        int c_kind;
        scanf("%s", command_str);
        for (c_kind = 0; !(strcmp(command_str, COMMAND_STR[c_kind]) == 0); ++c_kind)
            ;
        switch ((Command)c_kind)
        {
        case PUSH:
        {
            int num;
            scanf("%d", &num);
            push(&stack, num);
        }
        break;
        case POP:
            printf("%d\n", pop(&stack));
            break;
        case SIZE:
            printf("%d\n", size(&stack));
            break;
        case EMPTY:
            printf("%d\n", empty(&stack));
            break;
        case TOP:
            printf("%d\n", top(&stack));
        default:
            break;
        }
    }

    return 0;
}