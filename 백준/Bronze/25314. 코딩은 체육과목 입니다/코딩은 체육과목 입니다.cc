#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt_long = n/4;

    if (n%4)
    {
        cnt_long++;
    }

    for (int i = 0; i < cnt_long; ++i)
    {
        cout << "long ";
    }
    cout << "int";
}
