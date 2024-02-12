#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[1'001]; // 최단 거리 테이블
int pre[1'001];
vector<pair<int, int>> adj[1'001];
vector<bool> fix(1'001);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int st, en, cost;
    cin >> st >> en >> cost;
    adj[st].push_back({ cost,en });
  }

  int st, en;
  cin >> st >> en;
  priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
  fill(d, d + n + 1, INF);
  d[st] = 0;
  pq.push({ d[st],st });

  while (!pq.empty()) {
    int cost_to_cur, cur;
    tie(cost_to_cur, cur) = pq.top(); pq.pop();

    if (d[cur] != cost_to_cur) continue;

    fix[cur] = true;

    for (auto& [cost_to_nxt_from_cur, nxt] : adj[cur]) {
      if (fix[nxt]) continue;
      if (d[nxt] <= cost_to_cur + cost_to_nxt_from_cur) continue;

      d[nxt] = cost_to_cur + cost_to_nxt_from_cur;
      pq.push({ d[nxt],nxt });
      pre[nxt] = cur;
    }
  }

  cout << d[en] << '\n';
  vector<int> route;
  int cur = en;
  
  while (cur != st) {
    route.push_back(cur);
    cur = pre[cur];
  }
  
  route.push_back(cur);
  cout << route.size() << '\n';

  for (auto it = route.rbegin(); it != route.rend(); ++it) {
    cout << *it << ' ';
  }
}