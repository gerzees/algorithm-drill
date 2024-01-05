//11:11, 11:26
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<bool> vis(1001, false);
stack<int> s;
int N, M, u, v, ans;

void dfs(int start) {
  s.push(start);

  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (vis[cur]) continue;

    vis[cur] = true;
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;

      s.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    if (vis[i]) continue;

    ++ans;
    dfs(i);
  }

  cout << ans;
}