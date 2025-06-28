#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            return 0;
        }

        queue<int> Q;
        stack<int> S;

        Q.push(1);
        int sum = 1;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i)
            {
                continue;
            }

            if (i * i == n)
            {
                sum += i;
                Q.push(i);
            }
            else
            {
                sum += i + n / i;
                Q.push(i);
                S.push(n / i);
            }
        }

        cout << n;
        if (sum != n)
        {
            cout << " is NOT perfect.\n";
        }
        else
        {
            cout << " = ";
            while (!Q.empty())
            {
                cout << Q.front() << " + ";
                Q.pop();
            }
            while (S.size() > 1)
            {
                cout << S.top() << " + ";
                S.pop();
            }
            cout << S.top() << '\n';
        }
    }
}
