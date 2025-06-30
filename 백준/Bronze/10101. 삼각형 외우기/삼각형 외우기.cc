#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int angles[3];
    cin >> angles[0] >> angles[1] >> angles[2];

    if (angles[0] + angles[1] + angles[2] != 180)
    {
        cout << "Error";
        return 0;
    }

    if (angles[0] == angles[1] && angles[1] == angles[2])
    {
        cout << "Equilateral";
        return 0;
    }

    if (angles[0] != angles[1] && angles[1] != angles[2] && angles[0] != angles[2])
    {
        cout << "Scalene";
        return 0;
    }

    cout << "Isosceles";
}
