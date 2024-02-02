// 22:37, 22:57
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

tuple<int, int, int> e[100'000];// {w,u,v} w:비용, u,v:도시
vector<int> p(1'001, -1);
const int ROOT = 0;

int find(int x) {
  if (p[x] < 0) return x;

  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
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

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < k; ++i) {
    int plant;
    cin >> plant;
    merge(ROOT, plant);
  }

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = { w,u,v };
  }

  sort(e, e + m);
  int cnt = 0;
  int ans = 0;

  for (int i = 0; i < m;++i) {
    int w, u, v;
    tie(w, u, v) = e[i];

    if (merge(u, v) == false) continue;

    ans += w;
    ++cnt;
    if (cnt == n - k) break;
  }

  cout << ans;
}