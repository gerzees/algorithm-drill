//10807: 개수 세기
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    uint N;
    uint cnt[201] = {
        0,
    };
    cin >> N; //1~100
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        ++cnt[num + 100];
    }
    int v;
    cin >> v;
    cout << cnt[v + 100];
    return 0;
}