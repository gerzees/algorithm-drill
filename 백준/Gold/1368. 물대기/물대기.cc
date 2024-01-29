//9:12, 10:08
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<tuple<int, int, int>> edge;
int p[302];

int find(int x) {
  if (p[x] <= 0) return x;

  return p[x] = find(p[x]);
}

bool is_connected(int u, int v) {
  return find(u) == find(v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  edge.reserve(100'000);
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int cost;
    cin >> cost;
    edge.push_back({ cost,n + 1,i });
  }

  for (int i = 1;i <= n;++i) {
    for (int j = 1; j <= n; ++j) {
      int cost;
      cin >> cost;
      edge.push_back({ cost,i,j });
    }
  }

  sort(edge.begin(), edge.end());

  int cnt = 0;//고른 간선 수
  int ans = 0;

  for (auto& [cost, u, v] : edge) {
    if (is_connected(u, v)) continue;

    //root가져오기
    u = find(u);
    v = find(v);

    //랭크 비교? 사이즈 비교?
    if (p[u] == p[v]) --p[u];

    if (p[u] < p[v])p[v] = u;
    else p[u] = v;

    ans += cost;
    ++cnt;

    if (cnt == n) break; // 정점 n+1개인 샘
  }

  cout << ans;
}