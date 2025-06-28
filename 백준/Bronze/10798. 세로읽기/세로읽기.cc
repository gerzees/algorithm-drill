#include <bits/stdc++.h>

using namespace std;

char black_board[5][16];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        cin >> black_board[i];
    }

    for (int c = 0; c < 15; ++c)
    {
        for (int r = 0; r < 5; ++r)
        {
            if (black_board[r][c] == '\0')
            {
                continue;
            }

            cout << black_board[r][c];
        }
    }
}
