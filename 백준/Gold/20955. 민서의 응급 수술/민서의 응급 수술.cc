//22:18,22:52
#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[100'001];
vector<int> vis(100'001);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cnt_cycle = 0;

  for (int i = 1; i <= N; ++i) {
    if (vis[i]) continue;

    int cnt_node = 0;
    int cnt_edge_twice = 0;
    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (!q.empty()) {
      int cur = q.front(); q.pop();

      ++cnt_node;
      cnt_edge_twice += adj[cur].size();

      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;

        vis[nxt] = true;
        q.push(nxt);
      }
    }

    cnt_cycle += cnt_edge_twice / 2 - (cnt_node - 1);
  }

  int cnt_added_edge = N - 1 - (M - cnt_cycle);

  cout << cnt_cycle + cnt_added_edge;
}