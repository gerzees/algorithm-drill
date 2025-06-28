#include <bits/stdc++.h>

using namespace std;

char n[40];

inline int digit_to_int(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }

    return c - '0';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int b;
    cin >> n >> b;
    int num = digit_to_int(n[0]);

    for (int i = 1; n[i] != '\0'; ++i)
    {
        num *= b;
        num += digit_to_int(n[i]);
    }

    cout << num;
}
