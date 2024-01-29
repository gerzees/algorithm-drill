//07:36,8:51
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

tuple<int, int, int> edge[1'000'000];
vector<int> parent(100'001, -1);

int find(int node) {
  if (parent[node] < 0) return node;

  return parent[node] = find(parent[node]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b, cost;
    cin >> a >> b >> cost;
    edge[i] = { cost,a,b };
  }

  sort(edge, edge + m);
  int cnt = 0;
  int idx = 0;
  int ans = 0;

  // 최소 신장 트리 만들고 제일 비싼 간선 지운다 == 최소 신장 트리 직전(간선수 = 정점수-2)에 끝낸다.
  while (cnt < n - 2) {
    int cost, a, b;
    tie(cost, a, b) = edge[idx++];

    //a,b is connected?
    a = find(a);
    b = find(b);
    
    if (a==b) continue;

    // not connected... make edge between a,b
    ++cnt;
    ans += cost;
    
    // root의 parent에 rank 트리 깊이 음수로 저장(rank가 더 작다 == 트리 더 깊다)

    int& a_rank = parent[a];
    int& b_rank = parent[b];

    if (a_rank == b_rank) --a_rank;
    
    if (a_rank < b_rank) parent[b] = a;
    else parent[a] = b;
  }

  cout << ans;
}