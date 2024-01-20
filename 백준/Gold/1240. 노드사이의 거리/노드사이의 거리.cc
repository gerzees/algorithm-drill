//15:21, 15:44
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
vector<pair<int, int>> adj[1'001];
int dist[1'001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N - 1; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back({ v,d });
    adj[v].push_back({ u,d });
  }

  while (M--) {
    fill(dist + 1, dist + 1 + N, -1);
    int st, en;
    cin >> st >> en;

    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
      int cur = q.front(); q.pop();

      for (auto& p : adj[cur]) {
        int nxt, d;
        tie(nxt, d) = p;
        if (dist[nxt] != -1) continue;

        q.push(nxt);
        dist[nxt] = dist[cur] + d;

        if (en == nxt) goto GOT_DIST;
      }
    }

  GOT_DIST:
    cout << dist[en] << '\n';
  }
}