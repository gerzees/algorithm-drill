//2480: 주사위 세개
#include <iostream>

using namespace std;

int main(void)
{
    int dice[3];
    int cntSame = 1;
    int price;
    cin >> dice[0] >> dice[1] >> dice[2];
    if (dice[0] == dice[1] && dice[1] == dice[2])
    {
        cntSame += 2;
        price = 10 + dice[0];
    }
    else if (dice[0] != dice[1] && dice[1] != dice[2] && dice[2] != dice[0])
    {
        price = 10*(dice[0] > dice[1] ? (dice[0] > dice[2] ? dice[0] : dice[2]) : (dice[1] > dice[2] ? dice[1] : dice[2]));
    }
    else if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0])
    {
        ++cntSame;
        price = 10 + (dice[0] == dice[1] ? dice[0] : dice[2]);
    }
    for (size_t i = 0; i < cntSame; i++)
    {
        price *= 10;
    }
    cout << price;
    return 0;
}