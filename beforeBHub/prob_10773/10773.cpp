//10773: zero that out
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    uint K;
    cin >> K;
    uint sum = 0;
    uint num[100000];
    for (size_t cnt = 0, idx = 0; cnt < K; cnt++)
    {
        cin >> num[idx];
        if (num[idx] == 0)
            num[--idx] = 0;
        else
            ++idx;
    }
    for (size_t idx = 0; idx < K && num[idx] != 0; idx++)
    {
        sum += num[idx];
    }
    cout << sum;
    return 0;
}