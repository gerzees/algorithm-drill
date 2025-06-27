#include <bits/stdc++.h>

using namespace std;


char phone_num[16];
int dial_time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> phone_num;
    int total_time = 0;
    for (int i = 0; phone_num[i] != '\0'; i++)
    {
        total_time += dial_time[phone_num[i] - 'A'];
    }

    cout << total_time;
}
