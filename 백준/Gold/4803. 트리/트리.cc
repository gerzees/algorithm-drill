//9:51, 10:32
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[501];
vector<bool> vis(501);

int T;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cntCase = 0;

  while (true) {
    cin >> n >> m;

    if (n == 0 && m == 0) return 0;

    ++cntCase;
    T = 0;
    fill(vis.begin() + 1, vis.begin() + 1 + n, false);

    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
    }

    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;

      int node = 0;
      int edge = 0;
      queue<int> q;
      vis[i] = true;
      q.push(i);

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ++node;
        edge += adj[cur].size();

        for (int nxt : adj[cur]) {
          if (vis[nxt]) continue;

          vis[nxt] = true;
          q.push(nxt);
        }
      }

      edge /= 2;

      if (edge == node - 1) {
        ++T;
      }
    }

    cout << "Case " << cntCase << ": ";

    if (T == 0) {
      cout << "No trees." << '\n';
    }
    else if (T == 1) {
      cout << "There is one tree." << '\n';
    }
    else {
      cout << "A forest of " << T << " trees." << '\n';
    }
  }

}