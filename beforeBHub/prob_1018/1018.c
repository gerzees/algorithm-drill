#include <stdio.h>
enum
{
    CHESS_BOARD_WIDTH = 8
};
int cnt_repaint(char *chess_board, int board_width)
{
    int cnt_W = 0; //repaint count when left top is white
    int cnt_B = 0; //repaint count when left top is black
    for (size_t r = 0; r < CHESS_BOARD_WIDTH; r++)
    {
        for (size_t c = 0; c < CHESS_BOARD_WIDTH; c++)
        {
            if (chess_board[r * board_width + c] == 'W')
            {
                if (r % 2 == 0 && c % 2 == 0)
                {
                    ++cnt_B;
                }
                else if (r % 2 == 0) //c%2==1
                {
                    ++cnt_W;
                }
                else if (c % 2 == 0) //r%2==1
                {
                    ++cnt_W;
                }
                else //r%2==1 && c%2==1
                {
                    ++cnt_B;
                }
            }
            else //chess_board[r * M + c] == 'B'
            {
                if (r % 2 == 0 && c % 2 == 0)
                {
                    ++cnt_W;
                }
                else if (r % 2 == 0) //c%2==1
                {
                    ++cnt_B;
                }
                else if (c % 2 == 0) //r%2==1
                {
                    ++cnt_B;
                }
                else //r%2==1 && c%2==1
                {
                    ++cnt_W;
                }
            }
        }
    }
    return cnt_W < cnt_B ? cnt_W : cnt_B;
}

int main(void)
{
    int N; //the number of row of board
    int M; //the number of column of board
    int min_cnt_repaint = CHESS_BOARD_WIDTH * CHESS_BOARD_WIDTH;
    char board[50 * 50] = {
        0,
    };
    scanf("%d%d", &N, &M);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", board + i * M);
    }
    //8x8 chessboard case (N-7)*(M-7)
    for (size_t r = 0; r < N - 7; ++r)
    {
        for (size_t c = 0; c < M - 7; ++c)
        {
            int cnt = cnt_repaint(board + r * M + c, M);
            if (min_cnt_repaint > cnt)
                min_cnt_repaint = cnt;
        }
    }
    printf("%d", min_cnt_repaint);
    return 0;
}