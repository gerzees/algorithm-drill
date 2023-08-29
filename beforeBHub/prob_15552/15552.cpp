//15552: 빠른 A+B
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    size_t cntCase;
    cin >> cntCase;
    for (size_t i = 0; i < cntCase; i++)
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    return 0;
}