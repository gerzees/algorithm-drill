// 8:24,9:42
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100'001];
vector<bool> vis(100'001);
int parent;
int scores[100'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cin >> parent;

  for (int child = 2; child <= n; ++child) {
    cin >> parent;
    adj[parent].push_back(child);
  }

  while (m--) {
    int i, w;
    cin >> i >> w;
    scores[i] += w;
  }

  for (int i = 1;i <= n; ++i) {
    if (vis[i]) continue;

    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (!q.empty()) {
      int cur = q.front(); q.pop();

      for (int child : adj[cur]) {

        scores[child] += scores[cur];
        q.push(child);
        vis[child] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << scores[i] << ' ';
  }
}