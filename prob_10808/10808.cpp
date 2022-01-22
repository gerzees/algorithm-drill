//10808: 알파벳 개수
//success
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    constexpr size_t CNT_ALPHABET = 26;
    uint8_t cnt[CNT_ALPHABET] = {
        0,
    };
    string S;
    cin >> S;
    for (char &c : S)
        ++cnt[size_t(c - 'a')];
    for (uint8_t &cntEachAlphabet : cnt)
        cout << int(cntEachAlphabet) << ' ';
    return 0;
}