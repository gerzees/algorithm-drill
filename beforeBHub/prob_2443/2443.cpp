#include <iostream>

using namespace std;

int main(void)
{
    unsigned int N;
    cin >> N;
    string starStr;
    for (size_t line = 0; line < N; ++line)
    {
        for (size_t i = 0; i < line; i++)
            starStr.append(" ");
        for (size_t i = 0; i < 2 * N - (1 + 2 * line); i++)
            starStr.append("*");
        // error: output format wrong
        // useless blank
        // for (size_t i = 0; i < line; i++)
        //     starStr.append(" ");
        starStr.append("\n");
    }
    cout << starStr;
    return 0;
}