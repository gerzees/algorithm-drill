//1966: Printer Queue
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    uint T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        uint cntDoc, target, doc[101];
        uint cntPrio[10];
        // priority 10 means queue end
        // constexpr uint END = 10;
        cin >> cntDoc >> target;
        for (uint n = 0; n < cntDoc; ++n)
        {
            cin >> doc[n];
            ++cntPrio[doc[n]];
        }
        size_t nextPrio = 9, docIdx = 0, order = 0;
        while (!(doc[target] == 0))
        {
            while (!(cntPrio[nextPrio] >= 1))
                --nextPrio;
            --cntPrio[nextPrio];
            while (!(nextPrio == doc[docIdx]))
                if (docIdx == cntDoc)
                    docIdx = 0;
                else
                    ++docIdx;
            doc[docIdx] = 0; // priority 0 means entity poped
            ++order;
        }
        cout << order << '\n';
    }
    return 0;
}