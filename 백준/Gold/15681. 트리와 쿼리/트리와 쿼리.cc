//8:24, 8:47
#include<bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<int> adj[100'001];
int cnt[100'001];

void dfs(int cur, int par) {
  int children = 0;
  
  for (int nxt : adj[cur]) {
    if (nxt == par) continue;

    dfs(nxt, cur);

    children += cnt[nxt];
  }
  
  cnt[cur] = 1 + children;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> R >> Q;

  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(R, 0);
 
  while (Q--) {
    int u;
    cin >> u;
    cout << cnt[u] << '\n';
  }
}