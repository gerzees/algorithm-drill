//2587: 홀수
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int number[5];
    int sum = 0;
    for (int &n : number)
    {
        cin >> n;
        sum += n;
    }
    sort(number, number + 5, less<int>());
    cout << sum / 5 << '\n'
         << number[2];
    return 0;
}