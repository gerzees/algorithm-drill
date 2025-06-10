#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int V;
vpii edges[100'001];
int farthest;
int farthest_dist;

void dfs(int parent, int cur, int dist)
{
    for (const auto& [nxt, nxt_dist] : edges[cur])
    {
        if (nxt == parent)
        {
            continue;
        }

        dfs(cur, nxt, dist + nxt_dist);
    }

    if (farthest_dist < dist)
    {
        farthest = cur;
        farthest_dist = dist;
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

    dfs(0, 1, 0);
    dfs(0, farthest, 0);

    cout << farthest_dist;
}
