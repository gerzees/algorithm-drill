#include <bits/stdc++.h>

using namespace std;

char s[102];
int len;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (; s[len] != '\0'; ++len, ++cnt)
    {
        if (s[len] == 'c' && (s[len + 1] == '=' || s[len + 1] == '-'))
        {
            ++len;
        }
        else if (s[len] == 'd')
        {
            if (s[len + 1] == '-')
            {
                ++len;
            }
            else if (s[len + 1] == 'z' && s[len + 2] == '=')
            {
                len += 2;
            }
        }
        else if ((s[len] == 'l' || s[len] == 'n') && s[len + 1] == 'j')
        {
            ++len;
        }
        else if ((s[len] == 's' || s[len] == 'z') && s[len + 1] == '=')
        {
            ++len;
        }
    }

    cout << cnt;
}
