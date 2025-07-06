#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char n[11];
    cin >> n;
    int len = 0;
    for (; n[len] != '\0'; len++)
    {
    }
    sort(n, n + len, greater<>());
    cout << n;
}
