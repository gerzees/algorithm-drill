//2108: 통계학
//Wrong
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    uint16_t cnt[8001] = {
        0,
    };
    //index=num+4000
    //index 0       4000    4001    8000
    //num   -4000   0       1       4000
    uint cntNum, cntMid, freq = 0;
    int min = 4000, max = -4000, sum = 0, mostFreqNum, mid, ave;
    bool isOnlyMostFreq = false, foundMid = false;
    cin >> cntNum;
    for (size_t i = 0; i < cntNum; i++)
    {
        int num;
        cin >> num;
        ++cnt[num + 4000];
        if (num < min) //find min
            min = num;
        if (num > max) //find max
            max = num;
        sum += num; //acc sum;
    }
    for (int i = 0, cntMid = 0; i < 8001; i++)
    {
        if (!foundMid) //find middle value
        {
            cntMid += cnt[i];
            if (cntMid >= cntNum / 2 + 1)
            {
                mid = i - 4000;
                foundMid = true;
            }
        }
        if (freq < cnt[i]) //find most frequent value
        {
            freq = cnt[i];
            mostFreqNum = i - 4000;
            isOnlyMostFreq = true;
        }
        else if (freq == cnt[i] && isOnlyMostFreq)
        {
            isOnlyMostFreq = false;
            mostFreqNum = i - 4000;
        }
    }
    int rounding = sum * 10 / int(cntNum) % 10;
    ave = sum / int(cntNum);
    if (rounding >= 5)
        ++ave;
    else if (rounding <= -5)
        --ave;
    // ave = round(sum / double(cntNum));
    cout
        << ave << '\n'
        << mid << '\n'
        << mostFreqNum << '\n'
        << max - min; //range
    return 0;
}