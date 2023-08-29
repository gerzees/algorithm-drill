//10093:숫자
#include <iostream>

using namespace std;

int main(void)
{
    unsigned long long int A, B, countBitween;
    cin >> A >> B;
    countBitween = A > B ? A - B : B - A;
    if (countBitween > 0)
        countBitween -= 1;
    cout << countBitween << '\n';
    for (size_t i = 1, num = A > B ? B : A; i <= countBitween; i++)
        cout << num + i << ' ';
    return 0;
}