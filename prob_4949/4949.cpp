//4949: The balance of the world
// fix
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
    char bracket[MAX_LEN_DATASET / 2];
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
            switch (data)
            {
            case '(':
            {
                if (!(bracketIdx < MAX_LEN_DATASET / 2)) //idx keep less than the half of max length of dataset
                {
                    balanced = false;
                    break;
                }
                bracket[bracketIdx++] = '(';
            }
            break;
            case '[':
            {
                if (!(bracketIdx < MAX_LEN_DATASET / 2))
                {
                    balanced = false;
                    break;
                }
                bracket[bracketIdx++] = '[';
            }
            break;
            case ')':
            {
                if (bracketIdx == 0)
                {
                    balanced = false;
                    break;
                }
                if (bracket[--bracketIdx] != '(')
                    balanced = false;
            }
            break;
            case ']':
            {
                if (bracketIdx == 0)
                {
                    balanced = false;
                    break;
                }
                if (bracket[--bracketIdx] != '[')
                    balanced = false;
            }
            break;
            }
            if (!balanced)
                break;
        } //end for
        if (bracketIdx != 0)
            balanced = false;
        cout << (balanced ? "yes" : "no") << '\n';
    } //end while
    return 0;
}