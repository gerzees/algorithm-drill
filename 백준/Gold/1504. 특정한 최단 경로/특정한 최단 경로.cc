//07:49,08:42
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 2'400'000;
int d[3][801];
int st[3];
//{거리, 정점번호}
vector<pair<int, int>> adj[801];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, e;
  cin >> n >> e;

  for (int i = 0;i < 3;++i)
    fill(d[i], d[i] + n + 1, INF);

  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({ c,b });
    adj[b].push_back({ c,a });
  }

  st[0] = 1;
  cin >> st[1] >> st[2];
  int u, v, w, dw;

  for (int i = 0;i < 3;++i) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[i][st[i]] = 0;
    pq.push({ d[i][st[i]],st[i] });

    while (!pq.empty()) {
      tie(w, u) = pq.top(); pq.pop();

      if (d[i][u] != w) continue;

      for (auto& nxt : adj[u]) {
        tie(dw, v) = nxt;

        if (d[i][v] > w + dw) {
          d[i][v] = w + dw;
          pq.push({ d[i][v],v });
        }
      }
    }
  }

  // 1->st[1]->st[2]->N
  int path1 = d[0][st[1]] + d[1][st[2]] + d[2][n];
  // 1->st[2]->st[1]->N
  int path2 = d[0][st[2]] + d[2][st[1]] + d[1][n];

  if (path1 >= INF && path2 >= INF) {
    cout << -1;

    return 0;
  }

  if (path1 < path2) {
    cout << path1;
  }
  else {
    cout << path2;
  }
}