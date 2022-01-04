//BOJ 2752: 세수정렬
#include <iostream>

using namespace std;

int main(void)
{
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    if (n[0] > n[1])
        swap<int>(n[0], n[1]);
    if (n[0] > n[2])
        swap<int>(n[0], n[1]);
    if (n[1] > n[2])
        swap<int>(n[1], n[2]);
    cout << n[0] << ' ' << n[1] << ' ' << n[2];
    return 0;
}