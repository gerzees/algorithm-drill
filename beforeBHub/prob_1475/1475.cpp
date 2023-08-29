//1475: 방 번호
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    constexpr uint BASE = 10;
    uint cnt[BASE] = {
        0,
    };
    uint N;
    cin >> N; //N natural number
    do
    {
        ++cnt[N % BASE];
    } while (N /= BASE);
    //'6' can be '9', '9' can be '6'
    if ((cnt[6] + cnt[9]) % 2 == 1)
        cnt[6] = (cnt[6] + cnt[9]) / 2 + 1;
    else
        cnt[6] = (cnt[6] + cnt[9]) / 2;
    int cntNumSet = 0;
    for (size_t n = 0; n < 9; n++)
        if (cntNumSet < cnt[n])
            cntNumSet = cnt[n];
    cout << cntNumSet;
    return 0;
}