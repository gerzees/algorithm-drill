//11:06,15:01
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
const long long INF_TOTAL = 0x3f3f3f3f3f3f3f3f;
int max_cost[100'001];
// {거리,정점번호} 
vector<pair<int, int>> adj[100'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a, b;
  long long c;
  cin >> n >> m >> a >> b >> c;
  fill(max_cost, max_cost + 1 + n, INF);

  for (int i = 0;i < m;++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w,v });
    adj[v].push_back({ w,u });
  }

  priority_queue<tuple<long long, int, int>,
    vector< tuple<long long, int, int>>,
    greater< tuple<long long, int, int>>
  > pq;

  max_cost[a] = 0;
  pq.push({ 0,max_cost[a],a });

  while (!pq.empty()) {
    long long w;
    int mx, u;
    tie(w, mx, u) = pq.top(); pq.pop();

    if (mx != max_cost[u]) continue;

    for (auto& [dw, v] : adj[u]) {
      if (w + dw > c) continue;
      if (max(mx, dw) >= max_cost[v]) continue;

      // 단일 골목 최대 비용 작다 > 고려 대상
      max_cost[v] = max(mx, dw);
      pq.push({ w + dw, max(mx,dw),v });
    }
  }

  int ans = max_cost[b];
  if (ans == INF) ans = -1;
  cout << ans;
}