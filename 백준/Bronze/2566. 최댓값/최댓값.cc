#include <bits/stdc++.h>

using namespace std;

int mxm, row, col;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int r = 1; r <= 9; ++r)
    {
        for (int c = 1; c <= 9; ++c)
        {
            int num;

            cin >> num;

            if (num < mxm)
            {
                continue;
            }

            mxm = num;
            row = r;
            col = c;
        }
    }

    cout << mxm << '\n' << row << ' ' << col;
}
