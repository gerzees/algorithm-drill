//13300: 방배정
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    static uint cntBoy[7] = {
        0,
    };
    static uint cntGirl[7] = {
        0,
    };
    uint count, limit;
    cin >> count >> limit;
    for (size_t i = 0; i < count; i++)
    {
        uint year, sex;
        cin >> sex >> year;
        if (sex == 0) //girl
            ++cntGirl[year];
        else
            ++cntBoy[year];
    }
    uint cntRoom = 0;
    for (size_t y = 1; y <= 6; y++)
    {
        cntRoom += cntGirl[y] / limit;
        if (cntGirl[y] % limit > 0)
            ++cntRoom;
        cntRoom += cntBoy[y] / limit;
        if (cntBoy[y] % limit > 0)
            ++cntRoom;
    }
    cout << cntRoom;
    return 0;
}