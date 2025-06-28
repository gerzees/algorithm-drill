#include <bits/stdc++.h>

using namespace std;

stack<char> S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    do
    {
        int digit = n % b;

        if (digit > 9)
        {
            S.push(char('A' + digit - 10));
        }
        else
        {
            S.push(char('0' + digit));
        }
    }
    while (n /= b);

    while (S.empty() == false)
    {
        cout << S.top();
        S.pop();
    }
}
