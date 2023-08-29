//2444: 별 찍기 - 7
//fix
#include <iostream>

using namespace std;

int main(void)
{
    unsigned int N;
    string starStr;
    cin >> N;
    for (size_t line = 0; line < N; line++)
    {
        for (size_t i = line; i < N - 1; ++i)
            starStr.append(" ");
        for (size_t i = 0; i < 1 + 2 * line; i++)
            starStr.append("*");
        // useless blank
        // for (size_t i = line; i < N - 1; ++i)
        //     starStr.append(" ");
        starStr.append("\n");
    }
    for (size_t line = 0; line < N - 1; line++)
    {
        for (size_t i = 0; i < line + 1; ++i)
            starStr.append(" ");
        for (size_t i = 0; i < 2 * (N - line) - 3; i++)
            starStr.append("*");
        // useless blank
        // for (size_t i = 0; i < line + 1; ++i)
        //     starStr.append(" ");
        starStr.append("\n");
    }
    cout << starStr;
    return 0;
}