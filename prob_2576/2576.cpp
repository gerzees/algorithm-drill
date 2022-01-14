//2576: 홀수
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int min = 100;
    int sum = 0;
    for (size_t i = 0; i < 7; i++)
    {
        cin >> n;
        if (n % 2 == 1)
        {
            sum += n;
            if (n < min)
                min = n;
        }
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n'
             << min;
    return 0;
}