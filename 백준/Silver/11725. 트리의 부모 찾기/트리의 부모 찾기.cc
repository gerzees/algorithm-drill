//10:17, 10:30
#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[100'001];
int par[100'001];
const int ROOT = 1;

void dfs_recursive(int cur) {
  for (int nxt : adj[cur]) {
    if (nxt == par[cur]) continue;
    
    par[nxt] = cur;
    dfs_recursive(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  dfs_recursive(ROOT);

  for (int i = 2; i <= N; ++i) {
    cout << par[i] << '\n';
  }
}