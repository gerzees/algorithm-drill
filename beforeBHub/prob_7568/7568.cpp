//7568: 덩치
//pass
#include <iostream>
using namespace std;
//true if p1 > p2
bool gt(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first > p2.first && p1.second > p2.second;
}
//true if p1 < p2
bool lt(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first && p1.second < p2.second;
}
int main(void)
{
    pair<int, int> people[50];
    int cntGreater[50] = {
        0,
    };
    int cntPeople;
    cin >> cntPeople;
    for (int i = 0; i < cntPeople; ++i)
        cin >> people[i].first >> people[i].second;
    for (int i = 0; i < cntPeople - 1; ++i)
        for (int j = i + 1; j < cntPeople; ++j)
        {
            if (gt(people[i], people[j]))
            {
                ++cntGreater[j];
                continue;
            }
            if (lt(people[i], people[j]))
                ++cntGreater[i];
        }
    for (int i = 0; i < cntPeople; i++)
    {
        // the rank of someone = the number of people greater than someone + 1
        cout << cntGreater[i] + 1 << ' ';
    }
    return 0;
}