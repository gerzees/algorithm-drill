//1654: 랜선 자르기
#include <bits/stdc++.h>

using namespace std;

int searchLen(uint64_t begin, uint64_t end, uint wire[10000], uint K, uint N)
{
    if (end - begin <= 1)
        return begin;
    uint cnt = 0, len = (begin + end) / 2;
    for (size_t i = 0; i < K; i++)
    {
        cnt += wire[i] / len;
    }
    if (cnt >= N)
    {
        return searchLen(len, end, wire, K, N);
    }
    else
    {
        return searchLen(begin, len, wire, K, N);
    }
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    uint K, N;
    uint64_t sum = 0;
    uint wire[10000];
    cin >> K >> N;
    for (size_t i = 0; i < K; i++)
    {
        cin >> wire[i];
        sum += wire[i];
    }
    cout << searchLen(1, sum, wire, K, N);
    return 0;
}