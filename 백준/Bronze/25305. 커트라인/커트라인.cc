#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x[1'001];

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    sort(x, x + n, greater<>());

    cout << x[k - 1];
}
