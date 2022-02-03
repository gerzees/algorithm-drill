//1874: 스택 수열
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    constexpr char PUSH = '+';
    constexpr char POP = '-';
    uint n;
    cin >> n;
    uint num = 1;
    vector<uint> vec;
    vector<char> seqOp;
    bool impossible = false;
    for (size_t i = 0; i < n && !impossible; i++)
    {
        uint seq;
        cin >> seq;
        if (vec.empty() || seq > vec.back())
        {
            for (; num <= seq; ++num)
            {
                vec.push_back(num);
                seqOp.push_back(PUSH);
            }
        }
        if (seq == vec.back())
        {
            vec.pop_back();
            seqOp.push_back(POP);
        }
        else if (seq < vec.back())
            impossible = true;
    }
    if (impossible)
        cout << "NO";
    else
        for (char &op : seqOp)
            cout << op << '\n';
    return 0;
}