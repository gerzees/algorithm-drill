//11:35,12:33
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[20'002];
vector<bool> fix(20'002, false);
//{거리, 정점번호} : 정점->정점
vector<pair<int, int>> adj[20'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e, st;
  cin >> v >> e >> st;

  for (int i = 0;i < e;++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w,v });
  }

  fill(d, d + v + 1, INF);

  d[st] = 0;
  //{거리, 정점번호} : 시작점->정점
  priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
  > pq;
  pq.push({ 0,st });

  while (!pq.empty()) {
    int dist, cur;
    tie(dist, cur) = pq.top(); pq.pop();

    if (d[cur] != dist) continue;

    fix[cur] = true;

    for (auto& nxt : adj[cur]) {
      if (fix[nxt.Y]) continue;

      if (d[cur] + nxt.X < d[nxt.Y]) {
        d[nxt.Y] = d[cur] + nxt.X;
        pq.push({ d[nxt.Y], nxt.Y });
      }
    }
  }

  for (int i = 1;i <= v;++i) {
    if (d[i] == INF) cout << "INF\n";
    else cout << d[i] << '\n';
  }
}