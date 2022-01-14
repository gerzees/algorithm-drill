//2309: 일곱 난쟁이
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    constexpr size_t count = 9;
    int num[count];
    int sum = 0;
    for (int &n : num)
    {
        cin >> n;
        sum += n;
    }
    sort(num, num + count, less<int>());
    for (size_t idx1 = 0; idx1 < count - 1; idx1++)
    {
        for (size_t idx2 = idx1 + 1; idx2 < count; idx2++)
        {
            if (sum - (num[idx1] + num[idx2]) == 100)
            {
                for (size_t i = 0; i < count; i++)
                    if (i != idx1 && i != idx2)
                        cout << num[i] << '\n';
                return 0;
            }
        }
    }
}