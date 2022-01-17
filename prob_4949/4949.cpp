//4949: The balance of the world
// wrong
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    enum
    {
        MAX_LEN_DATASET = 100
    };
    string dataset;
    bool done = false;
    bool balanced;
    char bracket[MAX_LEN_DATASET / 2 + 1];
    int bracketIdx;
    while (!done)
    {
        getline(cin, dataset);
        if (dataset.size() == 1 && dataset.at(0) == '.')
        {
            done = true;
            continue;
        }
        bracketIdx = 0;
        balanced = true;
        for (char &data : dataset)
        {
            if (!(data == '(' || data == ')' || data == '[' || data == ']'))
                continue;
            if (bracketIdx == 0 && (data == '(' || data == '['))
            {
                bracket[bracketIdx++] = data;
            }
            else if (bracketIdx == 0)
            {
                balanced = false;
                break;
            }
            else
                switch (data)
                {
                case ')':
                    if (bracket[--bracketIdx] != '(')
                        balanced = false;
                    break;
                case ']':

                    if (bracket[--bracketIdx] != '[')
                        balanced = false;
                    break;
                default:
                    bracket[bracketIdx++] = data;
                    break;
                }
            if (!balanced)
            {
                break;
            }
        } //end for
        cout << (balanced ? "yes" : "no") << '\n';
    } //end while
    return 0;
}