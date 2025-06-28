#include <bits/stdc++.h>

using namespace std;

bool white_paper[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt, area = 0;
    cin >> cnt;

    while (cnt--)
    {
        int left, bottom;
        cin >> left >> bottom;

        for (int r = 90 - bottom; r < 100 - bottom; ++r)
        {
            for (int c = left; c < left + 10; ++c)
            {
                if (white_paper[r][c] == false)
                {
                    ++area;
                }

                white_paper[r][c] = true;
            }
        }
    }

    cout << area;
}
