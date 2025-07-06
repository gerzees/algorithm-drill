#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt_a, cnt_b;
    unordered_set<int> S;
    cin >> cnt_a >> cnt_b;

    for (int i = 0; i < cnt_a; ++i)
    {
        int element;
        cin >> element;
        S.insert(element);
    }

    for (int i = 0; i < cnt_b; ++i)
    {
        int element;
        cin >> element;
        if (S.erase(element) == 0)
        {
            S.insert(element);
        }
    }

    cout << S.size();
}
