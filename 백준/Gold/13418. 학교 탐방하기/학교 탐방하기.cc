//07:57,08:52
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

tuple<int, int, int> edge[500'000];
int p[1'001];

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

int span_tree(int n) {
  int cnt = 0;
  int e = 0;
  int total = 0;

  while (cnt < n) {
    int cost, a, b;
    tie(cost, a, b) = edge[e++];
    a = find(a);
    b = find(b);

    if (a == b) continue;

    ++cnt;
    total += cost;

    if (p[a] == p[b]) --p[a];

    if (p[a] < p[b]) p[b] = a;
    else p[a] = b;
  }

  return total;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a, b, cost;
  cin >> n >> m >> a >> b >> cost;
  // 1st edge :0->1
  edge[0] = { !cost,a,b };

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b >> cost;
    edge[i] = { !cost, a, b };
  }

  fill(p, p + 1 + n, -1);
  sort(edge, edge + m + 1);
  int min_cost = span_tree(n);
  fill(p, p + 1 + n, -1);
  sort(edge, edge + m + 1, greater<tuple<int, int, int>>());
  int max_cost = span_tree(n);

  cout << (max_cost + min_cost) * (max_cost - min_cost);
}