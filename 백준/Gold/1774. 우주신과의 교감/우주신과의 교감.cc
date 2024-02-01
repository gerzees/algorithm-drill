//07:38,08:48
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int, int> node[1'001];
tuple<long long, int, int> edge[500'000];
vector<int> p(1'001, -1);

int find(int x) {
  if (p[x] < 0) return x;

  return p[x] = find(p[x]);
}

bool try_merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) return false;

  if (p[u] == p[v]) --p[u];

  if (p[u] < p[v]) p[v] = u;
  else p[u] = v;

  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> node[i].X >> node[i].Y;
  }

  // 이미 연결된 통로 연결 시킨다
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    try_merge(u, v);
  }

  //연결되지 않은 정점을 연결할 수 있는 간선 고려 대상에 넣는다.
  int e = 0;
  for (int u = 1; u <= n; ++u)
    for (int v = u + 1; v <= n; ++v) {
      if (find(u) == find(v)) continue;

      long long diff_x = abs(node[u].X - node[v].X);
      long long diff_y = abs(node[u].Y - node[v].Y);
      long long dist_sqr = diff_x * diff_x + diff_y * diff_y;
      edge[e++] = { dist_sqr, u,v };
    }

  sort(edge, edge + e);
  int cnt = 0;
  double ans = 0.0;

  for (int i = 0; i < e; ++i) {
    long long dist_sqr, u, v;
    tie(dist_sqr, u, v) = edge[i];

    if (try_merge(u, v) == false) continue;

    ans += sqrt(dist_sqr);
    ++cnt;

    if (cnt == n - 1) break;
  }

  cout << fixed << setprecision(2) << ans;
}