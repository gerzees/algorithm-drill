#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int V;
vpii edges[100'001];

void search(int parent, int cur, pii& farthest)
{
    vpii nodes;
    for (const auto& [nxt, nxt_dist] : edges[cur])
    {
        if (nxt == parent)
        {
            continue;
        }
        pii far{0, 0};
        search(cur, nxt, far);

        if (far.first == 0)
        {
            far.first = nxt;
        }

        far.second += nxt_dist;
        nodes.push_back(far);
    }

    for (const auto& node : nodes)
    {
        if (farthest.second < node.second)
        {
            farthest = node;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int u, v, dist;
        cin >> u;

        while (true)
        {
            cin >> v;

            if (v == -1)
            {
                break;
            }

            cin >> dist;
            edges[u].push_back(pii{v, dist});
        }
    }

    pii far[2] = {{0, 0}, {0, 0}};
    search(0, 1, far[0]);
    search(0, far[0].first, far[1]);

    cout << far[1].second;
}
