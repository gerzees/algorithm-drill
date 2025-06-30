#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int sides[3];
        cin >> sides[0] >> sides[1] >> sides[2];

        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
        {
            return 0;
        }

        if (sides[0] + sides[1] <= sides[2] || sides[0] + sides[2] <= sides[1] || sides[1] + sides[2] <= sides[0])
        {
            cout << "Invalid\n";
            continue;
        }

        if (sides[0] == sides[1] && sides[1] == sides[2])
        {
            cout << "Equilateral\n";
            continue;
        }

        if (sides[0] != sides[1] && sides[1] != sides[2] && sides[0] != sides[2])
        {
            cout << "Scalene\n";
            continue;
        }

        cout << "Isosceles\n";
    }
}
