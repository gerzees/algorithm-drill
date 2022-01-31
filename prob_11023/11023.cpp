//11023: 더하기 3
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string num;
    getline(cin, num);
    int sum = 0;
    int temp = 0;
    for (const char &c : num)
    {
        if ('0' <= c && c <= '9')
        {
            temp *= 10;
            temp += c - '0';
        }
        else
        {
            sum += temp;
            temp = 0;
        }
    }
    if (temp != 0)
        sum += temp;
    cout << sum;
    return 0;
}