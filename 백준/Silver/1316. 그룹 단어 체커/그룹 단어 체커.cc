#include <bits/stdc++.h>

using namespace std;

int cnt;
bool is_appeared[26];
char s[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cnt = n;

    while (n--)
    {
        cin >> s;

        int len;
        is_appeared[s[0] - 'a'] = true;

        for (len = 1; s[len] != '\0'; ++len)
        {
            int offset = s[len] - 'a';

            if (s[len] != s[len - 1] && is_appeared[offset])
            {
                --cnt;
                break;
            }

            is_appeared[offset] = true;
        }

        fill(is_appeared, is_appeared + 26, 0);
        fill(s, s + len, 0);
    }

    cout << cnt;
}
