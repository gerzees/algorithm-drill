#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int max_x = -10'001, min_x = 10'001, max_y = -10'001, min_y = 10'001;
    while (n--)
    {
        int x, y;
        cin >> x >> y;

        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }

    cout << (max_x - min_x) * (max_y - min_y);
}
