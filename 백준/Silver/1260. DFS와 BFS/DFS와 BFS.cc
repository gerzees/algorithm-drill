//11:03, 11:21
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<bool> vis(1001, false);
int N, M, V, u, v;

void dfs(int cur) {
  vis[cur] = true;

  cout << cur << ' ';

  for (int nxt : adj[cur]) {
    if (vis[nxt]) continue;

    dfs(nxt);
  }
}

void bfs() {
  queue<int> q;
  q.push(V);
  vis[V] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    cout << cur << ' ';

    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;

      q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> V;

  while (M--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1;i <= N;++i) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(V);

  fill(vis.begin(), vis.end(), false);
  cout << '\n';

  bfs();
}