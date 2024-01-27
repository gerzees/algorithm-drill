//08:42,9:06
#include <bits/stdc++.h>

using namespace std;

int V, E;
tuple<int, int, int> edges[100'001];
int root[10'001];

int getRoot(int node) {
  if (root[node] <= 0) return node;

  return root[node] = getRoot(root[node]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int u, v, w;//u,v:정점. w:가중치
    cin >> u >> v >> w;
    edges[i] = { w,u,v };
  }

  sort(edges, edges + E);

  int total = 0;

  for (int i = 0; i < E; ++i) {
    auto& [w, u, v] = edges[i];
    int root_u = getRoot(u);
    int root_v = getRoot(v);

    if (root_u == root_v) continue;

    root[root_u] = root_v;
    total += w;
  }

  cout << total;
}