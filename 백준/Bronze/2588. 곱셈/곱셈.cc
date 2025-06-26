#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3];
    cin >> arr[1] >> arr[2];

    cout << arr[1] * (arr[2] % 10) << '\n';
    cout << arr[1] * (arr[2] / 10 % 10) << '\n';
    cout << arr[1] * (arr[2] / 100 % 10) << '\n';
    cout << arr[1] * arr[2];
}
