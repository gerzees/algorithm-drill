#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int cnt = 0; cnt < m; ++cnt)
    {
        int i, j, k;
        cin >> i >> j >> k;
        fill(arr+i,arr+j+1,k);
    }

    for (int i=1;i<=n;++i)
    {
        cout << arr[i] << ' ';
    }
}
