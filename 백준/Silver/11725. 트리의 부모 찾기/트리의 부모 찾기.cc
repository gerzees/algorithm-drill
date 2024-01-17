//10:17, 10:26
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
vector<int> adj[100'001];
int par[100'001];
const int ROOT = 1;

void bfs(void) {
  queue<int> q;
  q.push(ROOT);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      if (nxt == par[cur]) continue;

      q.push(nxt);
      par[nxt] = cur;
    }
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
  
  bfs();

  for (int i = 2; i <= N; ++i) {
    cout << par[i] << '\n';
  }
}