#include <stdio.h>
#define ROW 4
#define COL 9 
const char cat_symbol[ROW][COL]=
{
    "\\    /\\ \0",
    " )  ( \')\0",
    "(  /  ) \0",
    " \\(__)| \0"
};
int main(void)
{
    int i;
    for(i=0; i<ROW; ++i)
        printf("%s\n", &cat_symbol[i][0]);
    return 0;
}