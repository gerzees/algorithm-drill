#include <bits/stdc++.h>

using namespace std;
char s[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int len = 0;
        cin >> s;
        while (s[len] != '\0')
        {
            ++len;
        }
        cout << s[0] << s[len - 1] << '\n';
        fill(s, s + len, '\0');
    }
}
