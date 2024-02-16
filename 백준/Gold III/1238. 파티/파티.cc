//08:14,09:00
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[2][1001];
//{거리, 정점번호}
vector<pair<int, int>> adj[2][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x;
  cin >> n >> m >> x;
  fill(d[0], d[0] + 1 + n, INF);
  fill(d[1], d[1] + 1 + n, INF);

  for (int i = 0;i < m;++i) {
    int st, en, ti;
    cin >> st >> en >> ti;
    adj[0][st].push_back({ ti,en });
    adj[1][en].push_back({ ti,st });
  }

  for (int k = 0; k < 2;++k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[k][x] = 0;
    pq.push({ d[k][x],x });

    while (!pq.empty()) {
      int dist_x_to_cur, cur;
      tie(dist_x_to_cur, cur) = pq.top(); pq.pop();

      if (dist_x_to_cur != d[k][cur]) continue;

      // cur은 최단 경로 확정.
      for (auto& [dist_cur_to_nxt, nxt] : adj[k][cur]) {
        if (d[k][nxt] <= dist_x_to_cur + dist_cur_to_nxt) continue;

        d[k][nxt] = dist_x_to_cur + dist_cur_to_nxt;
        pq.push({ d[k][nxt],nxt });
      }
    }
  }

  int t_max = d[0][1]+d[1][1];

  for (int i = 2;i <= n;++i) {
    if (t_max < d[0][i] + d[1][i]) {
      t_max = d[0][i] + d[1][i];
    }
  }

  cout << t_max;
}