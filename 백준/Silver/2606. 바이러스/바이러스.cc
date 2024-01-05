//10:56, 11:06
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<bool> vis(101, false);
int V, E, u, v;

int ans;
void dfs(int cur) {
  if (cur != 1) {
    ++ans;
  }

  vis[cur] = true;

  for (int nxt : adj[cur]) {
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;
  while (E--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  cout << ans;
}