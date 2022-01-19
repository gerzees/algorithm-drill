//2108: 통계학
//fix
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    //cnt range 0~500,000 but uint16_t max 65535
    uint32_t cnt[8001] = {
        0,
    };
    //index=num+4000
    //index 0       4000    4001    8000
    //num   -4000   0       1       4000
    int cntNum, freq = 0;
    int min = 4000, max = -4000, sum = 0, mostFreqNum, mid, ave;
    bool isOnlyMostFreq = false, foundMid = false;
    cin >> cntNum;
    for (int i = 0; i < cntNum; i++)
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
    for (int i = 0, cntChecked = 0; i < 8001; i++)
    {
        if (!foundMid) //find middle value
        {
            cntChecked += cnt[i];
            if (cntChecked >= cntNum / 2 + 1)
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
    // sum can be 2,000,000,000 and int maximum is 2,147,483,647
    // sum*10 --> overflow!!
    // changing 10 to 10ll works
    int rounding = sum * 10ll / int(cntNum) % 10;
    ave = sum / int(cntNum);
    if (rounding >= 5)
        ++ave;
    else if (rounding <= -5)
        --ave;
    // ave = round(sum / double(cntNum));// works
    cout
        << ave << '\n'
        << mid << '\n'
        << mostFreqNum << '\n'
        << max - min; //range
    return 0;
}