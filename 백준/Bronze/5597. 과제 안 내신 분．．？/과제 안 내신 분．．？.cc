#include <bits/stdc++.h>

using namespace std;

bool is_submitted[31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int cnt = 0; cnt < 28; cnt++)
    {
        int n;
        cin >> n;
        is_submitted[n] = true;
    }

    for (int num = 1;num<=30;++num)
    {
        if (is_submitted[num]==false)
        {
            cout << num << '\n';
        }
    }
}
