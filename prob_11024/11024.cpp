//11024: 더하기 4
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    uint T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        string str;
        uint tmp = 0;
        uint sum = 0;
        getline(cin >> ws, str);
        for (const char &c : str)
        {
            if (c == ' ')
            {
                sum += tmp;
                tmp = 0;
            }
            else
            {
                tmp *= 10;
                tmp += c - '0';
            }
        }
        if (tmp != 0)
        {
            sum += tmp;
            tmp = 0;
        }
        cout << sum << '\n';
    }
    return 0;
}