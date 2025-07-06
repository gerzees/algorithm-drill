#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt;
    unordered_set<string> S;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        S.insert(str);
    }

    cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if (S.find(str) != S.end())
        {
            ++cnt;
        }
    }

    cout << cnt;
}
