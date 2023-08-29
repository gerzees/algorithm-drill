#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    constexpr uint CNT_MAX = 100000;
    cin.tie(0)->sync_with_stdio(false);
    static pair<int, int> points[CNT_MAX];
    uint cntPoint;
    cin >> cntPoint;
    for (size_t i = 0; i < cntPoint; i++)
        cin >> points[i].first >> points[i].second;
    struct
    {
        bool operator()(pair<int, int> &arg1, pair<int, int> &arg2)
        {
            return arg1.second == arg2.second ? arg1.first < arg2.first : arg1.second < arg2.second;
        }
    } lessPoints;
    sort(points, points + cntPoint, lessPoints);
    for (size_t i = 0; i < cntPoint; i++)
        cout << points[i].first << ' ' << points[i].second << '\n';
    return 0;
}