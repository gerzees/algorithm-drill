//3273: 두 수의 합
// fix
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    static bool isInput[1000001]; // not explicitly initialized-->zero-initialized
    int size;
    cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        isInput[num] = true;
    }
    int X, cntPair = 0;
    cin >> X;
    for (size_t num = 1; num < X / 2 + 1; num++)
        if (2 * num != X) //X=a_i+a_j, i!=j
            if (X - num < 1000001)//check outOfBounds
                if (isInput[num] && isInput[X - num])
                    ++cntPair;
    cout << cntPair;
    return 0;
}