//10989: 수 정렬하기 3
//success
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    int N;
    uint16_t numTemp;
    //numCnt can be 10,000,000: uint16_t-->uint32_t
    static uint32_t numCnt[10001] = {
        0,
    };
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> numTemp;
        ++numCnt[numTemp];
    }
    for (uint n = 1; n <= 10000; ++n)
        for (size_t i = 0; i < numCnt[n]; i++)
            cout << n << '\n';
    return 0;
}