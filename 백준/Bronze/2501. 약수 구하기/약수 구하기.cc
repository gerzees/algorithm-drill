#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int div = 1; div <= n; ++div)
    {
        if (n % div)
        {
            continue;
        }

        ++cnt;

        if (cnt == k)
        {
            cout << div;
            return 0;
        }
    }

    cout << 0;
}
