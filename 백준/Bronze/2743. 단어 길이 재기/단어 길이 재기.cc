#include <bits/stdc++.h>

using namespace std;

char s[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int len =0;
    while(s[len]!='\0')
    {
        ++len;
    }

    cout << len;
}
