#include <bits/stdc++.h>

using namespace std;

int mat[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2; ++i)
    {
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < m; ++c)
            {
                int num;
                cin >> num;
                mat[r][c] += num;
            }
        }
    }

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            cout << mat[r][c] << ' ';
        }
        cout << '\n';
    }
}
