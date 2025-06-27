#include <bits/stdc++.h>

using namespace std;

int right_cnt[6] = {1, 1, 2, 2, 2, 8};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 6; i++)
    {
        int cnt;
        cin >> cnt;

        cout << right_cnt[i] - cnt << ' ';
    }
}
