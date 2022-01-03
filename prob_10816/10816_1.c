// binary tree
#include <stdio.h>
typedef struct _node_card Node_card;
struct _node_card
{
    int node_value;
    int cnt;
    int height;
    Node_card *l_sub;
    Node_card *r_sub;
};

enum
{
    MAX_CNT_NODE = 500000
};
Node_card nodes[MAX_CNT_NODE];
size_t next_empty = 0;
Node_card *p_root = NULL;
Node_card *new_node(const int card)
{
    Node_card *p_new = &nodes[next_empty++];
    p_new->cnt = 1;
    p_new->height = 1;
    p_new->l_sub = NULL;
    p_new->r_sub = NULL;
    p_new->node_value = card;
    return p_new;
}
void height_update(Node_card *tree)
{
    if (tree == NULL)
        return;
    if (tree->l_sub == NULL && tree->r_sub == NULL)
        tree->height = 1;
    else if (tree->l_sub != NULL)
        tree->height = 1 + tree->l_sub->height;
    else if (tree->r_sub != NULL)
        tree->height = 1 + tree->r_sub->height;
    else
    {
        const int sub_height = tree->l_sub->height > tree->r_sub->height ? tree->l_sub->height : tree->r_sub->height;
        tree->height = 1 + sub_height;
    }
}
void balance(Node_card **pp_tree)
{
    Node_card *p_tree = *pp_tree;
    if (p_tree == NULL)
        return;
    if (p_tree->l_sub == NULL && p_tree->r_sub == NULL)
        return;
    else if (p_tree->l_sub != NULL && p_tree->l_sub->height > 1)
    {
        *pp_tree = p_tree->l_sub;
        p_tree->l_sub = (*pp_tree)->r_sub;
        (*pp_tree)->r_sub = p_tree;
        height_update(p_tree);
        height_update(*pp_tree);
    }
    else if (p_tree->r_sub != NULL && p_tree->r_sub->height > 1)
    {
        *pp_tree = p_tree->r_sub;
        p_tree->r_sub = (*pp_tree)->l_sub;
        (*pp_tree)->l_sub = p_tree;
        height_update(p_tree);
        height_update(*pp_tree);
    }
    else if (p_tree->l_sub != NULL && p_tree->r_sub != NULL)
    {
        if (p_tree->r_sub->height - p_tree->l_sub->height > 1)
        {
            *pp_tree = p_tree->r_sub;
            p_tree->r_sub = (*pp_tree)->l_sub;
            (*pp_tree)->l_sub = p_tree;
            height_update(p_tree);
            height_update(*pp_tree);
        }
        else if (p_tree->l_sub->height - p_tree->r_sub->height > 1)
        {
            *pp_tree = p_tree->l_sub;
            p_tree->l_sub = (*pp_tree)->r_sub;
            (*pp_tree)->r_sub = p_tree;
            height_update(p_tree);
            height_update(*pp_tree);
        }
    }
}
void attach(Node_card **pp_tree, Node_card *sub)
{
    Node_card *p_tree = *pp_tree;
    if (p_tree == NULL)
    {
        *pp_tree = sub;
        return;
    }
    if (sub->node_value < p_tree->node_value)
    {
        if (p_tree->l_sub == NULL)
        {
            p_tree->l_sub = sub;
        }
        else
        {
            attach(&(p_tree->l_sub), sub);
        }
    }
    else if (p_tree->node_value < sub->node_value)
    {
        if (p_tree->r_sub == NULL)
        {
            p_tree->r_sub = sub;
        }
        else
        {
            attach(&(p_tree->r_sub), sub);
        }
    }
    else // sub->node_value == tree->node_value
    {
        ++(p_tree->cnt);
    }
    height_update(p_tree);
    balance(pp_tree);
}
int search(Node_card *p_tree, const int card)
{
    if (p_tree == NULL)
        return 0;
    if (p_tree->node_value == card)
        return p_tree->cnt;
    else if (p_tree->node_value < card)
        return search(p_tree->r_sub, card);
    else if (card < p_tree->node_value)
        return search(p_tree->l_sub, card);
}
void set_card(const int card)
{
    attach(&p_root, new_node(card));
}
int get_cnt_card(const int card)
{
    return search(p_root, card);
}
int main(void)
{
    size_t N, M;
    scanf("%ld", &N);
    for (size_t i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        set_card(n);
    }
    scanf("%ld", &M);
    for (size_t i = 0; i < M; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", get_cnt_card(n));
    }
    return 0;
}