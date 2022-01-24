//3273: 두 수의 합
// wrong
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    static int cnt[1000001] = {
        0,
    };
    int size;
    cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        ++cnt[num];
    }
    int X, cntPair = 0;
    cin >> X;
    for (size_t num = 1; num < 1000001; num++)
        if (cnt[num] > 0 && 0 <= X - int(num) && X - int(num) <= 1000000)
            if (cnt[X - num])
                ++cntPair, --cnt[num], --cnt[X - num];
    cout << cntPair;
    return 0;
}