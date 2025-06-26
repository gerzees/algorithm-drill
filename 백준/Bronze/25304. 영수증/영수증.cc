#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,n;
    cin >> x>> n;
    long long sum=0;

    for (int i=0;i<n;++i)
    {
        long long a,b;
        cin >> a >> b;
        sum+=a*b;
    }

    if (sum==x)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}